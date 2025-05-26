//
// Created by lucas on 17/05/2025.
//

#include "Inspection.h"

Inspection::Inspection(): id(0), cost(0) {
}

Inspection::Inspection(int id, Vehicle *vehicle, Date &date, double cost) {
    this->id = id;
    this->vehicle = *vehicle;
    this->date = date;
    this->cost = cost;
}

Inspection::~Inspection() {}

int Inspection::getID() const {
    return id;
}

Vehicle Inspection::getVehicle() const {
    return vehicle;
}

Date Inspection::getDate() const {
    return date;
}

void Inspection::setID(int id) {
    this->id = id;
}

void Inspection::setVehicle(Vehicle vehicle) {
    this->vehicle = vehicle;
}

void Inspection::setDate(Date date) {
    this->date = date;
}

void Inspection::setCost(double cost) {
    this->cost = cost;
}

bool Inspection::isDued() {
    this->updateToday();
    if (this->date < this->today) {return true;}
    if (this->date == this->today) {return true;}
    return false;
}

int Inspection::getRemainingDays() const {
    return this->date - this->today;
}

void Inspection::updateToday() {
    this->today = Date::getToday();
}
