//
// Created by ruben on 19/05/2025.
//

#include "Driver.h"

#include <string.h>

#include "Utils.h"
#include "DriverContainer.h"
#include "DriverView.h"
#include "InvalidDataException.h"
#include "Vacation.h"

Driver::Driver() : id(), available(true), license('\0') {}

Driver::Driver(int id, char &license, int age) : available(true) {
    this->id = id;
    this->license = license;
    this->age= age;
    this->timeToRetire = 65;
}

Driver::~Driver() {}

int Driver::getID() const {
    return id;
}

char Driver::getLicense() const {
    return license;
}

int Driver::getAge() const {
    return age;
}

bool Driver::getAvailability() const {
    return available;
}

list<Vacation *> Driver::getVacations() const {
    return vacations;
}

Vacation *Driver::getVacation() {
    try {
        if (vacations.empty()) {
            return nullptr;
        }

        Date today = Date::getToday();
        list<Vacation *>::iterator it = this->vacations.begin();
        for (; it != this->vacations.end(); ++it) {
            if (*it != nullptr) {
                if (((*it)->getStartDate() < today || (*it)->getStartDate() == today) &&
                    ((*it)->getEndDate() > today || (*it)->getEndDate() == today)) {
                    return *it;
                    }
            }
        }
    } catch (const InvalidDataException &error) {
        cout << error.what() << endl;
    } catch (...) {
        cout << "Erro inesperado ao processar datas" << endl;
    }
    return nullptr;
}


int Driver::getVacationID() {
    try {
        Vacation* vacation = getVacation();
        if (vacation != nullptr) {
            return vacation->getID();
        }
    } catch (...) {
        cout << "Erro ao obter ID das férias" << endl;
    }
    return 0;
}


int Driver::getTimeToRetire() const {
    const int retirementAge = 65;
    if (age >= retirementAge) {
        return 0;
    }
    return retirementAge - age;
}

void Driver::setID(int id) {
    this->id = id;
}

void Driver::setLicense(char license) {
    this->license = license;
}

void Driver::setAge(int age) {
    this->age = age;
}

void Driver::setTimeToRetire(int age) {
    this->timeToRetire = 65 - age;
}

void Driver::setVacation(Vacation *vacation) {
    this->vacations.push_back(vacation);
}

void Driver::setAvailability(bool available) {
    this->available = available;
}

void Driver::vacationAlert() {
    if (this->getVacation()->isOnVacation()) {
        DriverView::vacationAlert(*this);
    }
}

void Driver::retirementAlert() {
    if (this->age >= 65) {
        DriverView::retirementAlert(*this);
    }
}

bool Driver::isAvailable() const {
    if (this->available) {return true;}
    return false;
}

char Driver::stringToChar(string &license) {
    char licenseChar;
    licenseChar = license[0];
    return licenseChar;
}