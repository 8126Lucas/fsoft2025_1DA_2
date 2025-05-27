//
// Created by ruben on 23/05/2025.
//

#include "Vacation.h"

Vacation::Vacation() : id(), driver(nullptr), status(false) {}

Vacation::Vacation(int id, Driver *driver, Date startDate, Date endDate, bool status) : status(true) {
  this->id = id;
  this->driver = driver;
  this->startDate = startDate;
  this->endDate = endDate;
}

Vacation::~Vacation() {}

Vacation Vacation::addVacation(VacationView vacationView) {
    Vacation vacation = vacationView.addVacation();
    return vacation;
}

int Vacation::removeVacation(VacationView vacationView) {
    int id = vacationView.removeVacation();
    return id;
}

int Vacation::getID() const {
    return id;
}

Driver Vacation::getDriver() const {
  return *driver;
}

Date Vacation::getStartDate() const {
  return startDate;
}

Date Vacation::getEndDate() const {
  return endDate;
}

bool Vacation::getStatus() const {
  return status;
}


void Vacation::setID(int id) {
    this->id = id;
}

void Vacation::setDriver(Driver driver) {
    this->driver = &driver;
}

void Vacation::setStartDate(Date startDate) {
    this->startDate = startDate;
}

void Vacation::setEndDate(Date endDate) {
    this->endDate = endDate;
}

void Vacation::setStatus(bool status) {
    this->status = status;
}

bool Vacation::isOnVacation() {
    this->updateToday();
    if (this->endDate < this->today) {return true;}
    if (this->endDate == this->today) {return true;}
    return false;
}

int Vacation::getRemainingDays() const {
    return this->endDate - this->today;
}

void Vacation::updateToday() {
    this->today = Date::getToday();
}