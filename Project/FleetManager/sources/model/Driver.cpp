//
// Created by ruben on 19/05/2025.
//

#include "Driver.h"
#include "Utils.h"
#include "DriverContainer.h"
#include "DriverView.h"
#include "Vacation.h"

Driver::Driver() : id(), available(true) {}

Driver::Driver(int id, char &license, int age) : available(true) {
    this->id = id;
    this->license = license;
    this->age= age;
}

Driver::~Driver() {}

// void Driver::addDriver() {
//     Driver driver = DriverView::getDriver(DriverContainer *container);
//     DriverContainer::add(driver);
// }
//
// void Driver::removeDriver() {
//     int id = DriverView::getID();
//     DriverContainer::remove(id);
// }

int Driver::getID() {
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

bool Driver::getVacationID() const {
    return vacation.getID();
}

void Driver::setVacation(const Vacation vacation) {
    this->vacation = vacation;
}

void Driver::setAvailability(bool available) {
    this->available = available;
}

int Driver::getTimeToRetire() const {
    const int retirementAge = 65;
    if (age >= retirementAge) {
        return 0;
    }
    return retirementAge - age;
}

void Driver::vacationAlert() {
    if (this->vacation.isOnVacation()) {
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