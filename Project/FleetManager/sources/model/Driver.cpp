//
// Created by ruben on 19/05/2025.
//

#include "Driver.h"
#include "Utils.h"
#include "DriverContainer.h"
#include "DriverView.h"
#include "Vacation.h"

Driver::Driver() : id(), available(true) {}

Driver::Driver(int id, string &license, int age) : available(true), vacationStatus(false){
    this->id = id;
    this->license = license;
    this->age= age;
}

Driver::~Driver() {}

void Driver::addDriver() {
    Driver driver = DriverView::getDriver();
    DriverContainer::add(driver);
}

void Driver::removeDriver() {
    int id = DriverView::getId();
    DriverContainer::remove(id);
}

int Driver::getId() {
    return id;
}

string Driver::getLicense() const {
    return license;
}

int Driver::getAge() const {
    return age;
}

STATUS Driver::getDriverStatus() const {
    return driverStatus;
}

bool Driver::getAvailability() const {
    return available;
}

bool Driver::getVacationStatus() const {
    return vacation.getId();
}

void Driver::setVacation(const Vacation vacation) {
    this->vacation = vacation;
}

void Driver::setAvailability(bool available) {
    this->available = available;
}

void Driver::updateTimeToRetire() {
    const int retirementAge = 65;
    if (age >= retirementAge) {
        this->timeToRetire = 0;
    } else {
        this->timeToRetire = retirementAge - age;
    }
}

void Driver::vacationAlert() {
    if (this->vacation.isOnVacation()) {
        DriverView::vacationAlert(*this);
    }
}
void Driver::retirementAlert() {

}

bool Vehicle::isAvailable() const {
    if (this->available) {return true;}
    return false;
}