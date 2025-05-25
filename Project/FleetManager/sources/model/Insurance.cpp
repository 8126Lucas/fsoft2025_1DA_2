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

Vehicle Insurance::getVehicle() const {
    return *vehicle;
}

Insurance Insurance::addInsurance(InsuranceView insuranceView) {
    Insurance insurance = insuranceView.addInsurance();
    return insurance;
}

int Insurance::removeInsurance(InsuranceView insuranceView) {
    int id = insuranceView.removeInsurance();
    return id;
}

bool Insurance::isExpired() {
    this->updateToday();
    if (this->endDate < this->today) {return true;}
    if (this->endDate == this->today) {return true;}
    return false;
}

int Insurance::getRemainingDays() const {
    return this->endDate - this->today;
}

void Insurance::updateToday() {
    this->today = Date::getToday();
}
