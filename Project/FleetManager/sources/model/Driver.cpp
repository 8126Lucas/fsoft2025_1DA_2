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

/*
void Driver::addDriver() {
    Driver driver = DriverView::getDriver();
    DriverContainer::add(driver);
}

void Driver::removeDriver() {
    int id = DriverView::getId();
    DriverContainer::remove(id);
}
*/

int Driver::getId() {
    return id;
}

bool Driver::getAvailability() const {
    return available;
}

void Driver::setVacation(const Vacation vacation) {
    this->vacation = vacation;
}