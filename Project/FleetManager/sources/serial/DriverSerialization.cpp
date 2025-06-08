//
// Created by ruben on 06/06/2025.
//

#include "DriverSerialization.h"

void DriverSerialization::toJSON(json &j, const Driver &driver) {
    j["id"] = driver.getID();
    j["license"] = driver.getLicense();
    j["age"] = driver.getAge();
    j["timeToRetire"] = driver.getTimeToRetire();
    j["available"] = driver.getAvailability();

    j["vacations"] = json::array();
    for(list<Vacation *>::iterator it = driver.getVacations().begin(); it != driver.getVacations().end(); ++it) {
        json vacationJSON;

        vacationJSON["id"] = (*it)->getID();
        vacationJSON["startDate"] = (*it)->getStartDate().dateToString();
        vacationJSON["endDate"] = (*it)->getEndDate().dateToString();
        vacationJSON["status"] = (*it)->getStatus();

        j["vacations"].push_back(vacationJSON);
    }
}

void DriverSerialization::fromJSON(const json &j, Driver &driver) {
    driver.setID(j["id"]);
    char char_license = driver.stringToChar(j["license"]);
    driver.setLicense(char_license);
    driver.setAge(j["age"]);
    driver.setAge(j["timeTiRetire"]);
    driver.setAvailability(j["available"]);

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