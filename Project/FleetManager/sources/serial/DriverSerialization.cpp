//
// Created by ruben on 06/06/2025.
//

#include "DriverSerialization.h"

#include "DriverContainer.h"

void DriverSerialization::toJSON(json &j, const Driver &driver) {
    j["id"] = driver.getID();
    char licenseChar = driver.getLicense();
    string licenseString = string(1, licenseChar);
    j["license"] = licenseString;
    j["age"] = driver.getAge();
    j["timeToRetire"] = driver.getTimeToRetire();
    j["available"] = driver.getAvailability();

    j["vacations"] = json::array();
    const list<Vacation*>& driverVacations = driver.getVacations();
    for(const Vacation* vacation : driverVacations) {
        json vacationJSON;

        vacationJSON["id"] = vacation->getID();
        vacationJSON["driverID"] = vacation->getDriver()->getID();
        vacationJSON["startDate"] = vacation->getStartDate().dateToString();
        vacationJSON["endDate"] = vacation->getEndDate().dateToString();
        vacationJSON["status"] = vacation->getStatus();

        j["vacations"].push_back(vacationJSON);
    }
}

void DriverSerialization::fromJSON(const json &j, Driver &driver) {
    driver.setID(j["id"]);
    string licenseString = j["license"];
    char char_license = driver.stringToChar(licenseString);
    driver.setLicense(char_license);
    driver.setAge(j["age"]);
    driver.setTimeToRetire(j["timeToRetire"]);
    driver.setAvailability(j["available"]);

    driver.getVacations().clear();

    if (j["vacations"].is_array() && !j["vacations"].empty()) {
        for(const basic_json<> &vacationJSON : j["vacations"]) {
            Vacation *vacation = new Vacation();
            Date startDate;
            Date endDate;
            vacation->setID(vacationJSON["id"]);

            if (vacationJSON["driverID"] == driver.getID()) {
                vacation->setDriver(&driver);
                vacation->setStartDate(startDate.stringToDate(vacationJSON["startDate"]));
                vacation->setEndDate(endDate.stringToDate(vacationJSON["endDate"]));
                vacation->setStatus(vacationJSON["status"]);

                driver.setVacation(vacation);
            }
        }
    }
}