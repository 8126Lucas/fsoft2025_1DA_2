//
// Created by lucas on 17/05/2025.
//

#include "Insurance.h"

#include "InsuranceView.h"
#include "Vehicle.h"


Insurance::Insurance(): id(0), vehicle(nullptr), monthlyCost(0) {}

Insurance::Insurance(int id, Vehicle *vehicle, Date &startDate, Date &endDate, double monthlyCost) {
    this->id = id;
    this->vehicle = vehicle;
    this->startDate = startDate;
    this->endDate = endDate;
    this->monthlyCost = monthlyCost;
}

Insurance::~Insurance() {}

int Insurance::getID() const {
    return id;
}

Vehicle *Insurance::getVehicle() const {
    return vehicle;
}

Date Insurance::getStartDate() const {
    return startDate;
}

Date Insurance::getEndDate() const {
    return endDate;
}

double Insurance::getMonthlyCost() const {
    return monthlyCost;
}

Date Insurance::getToday() const {
    return today;
}

void Insurance::setID(int id) {
    this->id = id;
}

void Insurance::setVehicle(Vehicle *vehicle) {
    this->vehicle = vehicle;
}

void Insurance::setStartDate(Date &startDate) {
    this->startDate = startDate;
}

void Insurance::setEndDate(Date endDate) {
    this->endDate = endDate;
}

void Insurance::setMonthlyCost(double monthlyCost) {
    this->monthlyCost = monthlyCost;
}

void Insurance::setToday(const Date &date) {
    this->today = date;
}

bool Insurance::isExpired() {
    this->updateToday();
    if (this->endDate < this->today) {return true;}
    if (this->endDate == this->today) {return true;}
    return false;
}

int Insurance::getRemainingDays() {
    this->updateToday();
    return this->endDate - this->today;
}

void Insurance::updateToday() {
    this->today = Date::getToday();
}
