//
// Created by lucas on 17/05/2025.
//

#include "Inspection.h"
#include <iostream>
#include "InvalidDataException.h"

Inspection::Inspection() {
    this->id = 0;
    this->vehicle = nullptr;
    this->cost = 0;
    this->today = Date(1, 1, 2020);

}

Inspection::Inspection(int id, Vehicle *vehicle, Date &date, double cost) {
    this->id = id;
    this->vehicle = vehicle;
    this->date = date;
    this->cost = cost;
}

Inspection::~Inspection() {}

int Inspection::getID() const {
    return id;
}

Vehicle *Inspection::getVehicle() const {
    return vehicle;
}

Date Inspection::getDate() const {
    return date;
}

double Inspection::getCost() const {
    return cost;
}

Date Inspection::getToday() const {
    return today;
}

void Inspection::setID(int id) {
    this->id = id;
}

void Inspection::setVehicle(Vehicle *vehicle) {
    this->vehicle = vehicle;
}

void Inspection::setDate(Date date) {
    this->date = date;
}

void Inspection::setCost(double cost) {
    this->cost = cost;
}

void Inspection::setToday(const Date &date) {
    this->today = date;
}

bool Inspection::isDued() {
    this->updateToday();
    if (this->date < this->today) {return true;}
    if (this->date == this->today) {return true;}
    return false;
}

void Inspection::updateToday() {
    try {
        this->today = Date::getToday();
    } catch (const InvalidDataException &error) {
        cout << error.what() << endl;
        this->today = Date(1, 1, 2026);
    }
}

int Inspection::getRemainingDays() {
    updateToday();
    return this->date - this->today;
}
