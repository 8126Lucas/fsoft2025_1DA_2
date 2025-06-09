//
// Created by ruben on 06/06/2025.
//

#include "DriverSerialization.h"

void DriverSerialization::toJSON(json &j, const Driver &driver) {
    j["id"] = driver.getID();
    char licenseChar = driver.getLicense();
    string licenseString = string(1, licenseChar);
    j["license"] = licenseString;
    j["age"] = driver.getAge();
    j["timeToRetire"] = driver.getTimeToRetire();
    j["available"] = driver.getAvailability();

    j["vacations"] = json::array();
    if (driver.getVacations().empty()) {
        for(list<Vacation *>::iterator it = driver.getVacations().begin(); it != driver.getVacations().end(); ++it) {
            json vacationJSON;

            vacationJSON["id"] = (*it)->getID();
            vacationJSON["startDate"] = (*it)->getStartDate().dateToString();
            vacationJSON["endDate"] = (*it)->getEndDate().dateToString();
            vacationJSON["status"] = (*it)->getStatus();

            j["vacations"].push_back(vacationJSON);
        }
    }
}

void DriverSerialization::fromJSON(const json &j, Driver &driver) {
    driver.setID(j["id"]);
    string licenseString = j["license"];
    char char_license = driver.stringToChar(licenseString);
    driver.setLicense(char_license);
    driver.setAge(j["age"]);
    driver.setAge(j["timeToRetire"]);
    driver.setAvailability(j["available"]);

    if (j["vacations"].is_array() && j["vacations"].size() > 0) {
        for(list<Vacation *>::iterator it = driver.getVacations().begin(); it != driver.getVacations().end(); ++it) {
            Vacation* vacation = new Vacation();

            json vacationJSON = j["vacations"];

            Date startDate;
            Date endDate;

            vacation->setID(vacationJSON["id"]);
            vacation->setStartDate(startDate.stringToDate(vacationJSON["startDate"]));
            vacation->setEndDate(endDate.stringToDate(vacationJSON["endDate"]));
            vacation->setStatus(vacationJSON["status"]);

            driver.setVacation(vacation);
        }
    }
}