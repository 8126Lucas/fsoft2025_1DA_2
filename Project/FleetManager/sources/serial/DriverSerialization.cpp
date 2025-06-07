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
    for(list<Vacation *>::iterator it = driver.getVacation().begin(); it == driver.getVacation().end; ++it) {
        json vacationJSON = json::array();
        vacationJSON.push_back(it->)
    //j["vacations"] = driver.getVacation();
}

void DriverSerialization::fromJSON(const json &j, Driver &driver) {
    driver.setID(j["id"]);
    char char_license = driver.stringToChar(j["license"]);
    driver.setLicense(char_license);
    driver.setAge(j["age"]);
    driver.setAge(j["timeTiRetire"]);
    driver.setAvailability(j["available"]);

    //driver.setVacation(j["vacation"]);
}