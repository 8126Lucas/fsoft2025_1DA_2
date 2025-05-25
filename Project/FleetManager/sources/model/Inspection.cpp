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

Inspection Inspection::addInspection(InspectionView inspectionView) const {
    Inspection inspection = inspectionView.addInspection();
    return inspection;
}

int Inspection::removeInspection(InspectionView inspectionView) {
    int id = inspectionView.removeInspection();
    return id;
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
