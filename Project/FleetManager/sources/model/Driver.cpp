//
// Created by ruben on 19/05/2025.
//

#include "Driver.h"
#include "Utils.h"
#include "DriverContainer.h"
#include "DriverView.h"

Driver::Driver() : id(), available(true) {}

Driver::Driver(const int &id, const string &license, const int &age, const bool available) {
    this->id = id;
    this->license = license;
    this->age= age;
    this->available = available;
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
    return id; // alterado declaração de string para INT.
}

bool Driver::getAvailability() const {
    return available;
}

void Driver::setVacation(const Vacation vacation) {
    this->vacation = vacation;
}