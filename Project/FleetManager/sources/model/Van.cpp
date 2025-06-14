//
// Created by lucas on 17/05/2025.
//

#include "Van.h"

Van::Van() {
    this->category = VAN;
    this->spaceCapacity = 0.0;
    this->insurance = nullptr;
    this->inspection = nullptr;
    this->vsl = nullptr;
}

Van::Van(CATEGORY category, string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double spaceCapacity, bool available)
             : Vehicle(category, brand, model, year, licensePlate, mileage, fuel, available) {
    this->spaceCapacity = spaceCapacity;
}

Van::~Van() {}

bool Van::canCarryLoad(Order &order) {
    if (spaceCapacity > order.getCargoSpace()) {return true;}
    return false;
}

double Van::getSpaceCapacity() const {
    return spaceCapacity;
}

void Van::setSpaceCapacity(double spaceCapacity) {
    this->spaceCapacity = spaceCapacity;
}

