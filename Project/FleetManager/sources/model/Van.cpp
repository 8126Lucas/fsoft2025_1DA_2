//
// Created by lucas on 17/05/2025.
//

#include "Van.h"

Van::Van() {
    this->spaceCapacity = 0.0;
}

Van::Van(CATEGORY category, string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double spaceCapacity, bool available)
             : Vehicle(category, brand, model, year, licensePlate, mileage, fuel, available) {
    this->spaceCapacity = spaceCapacity;
}

bool Van::canCarryLoad(Order &order) {
    if (spaceCapacity > order.getCargoSpace()) {return true;}
    return false;
}

void Van::setSpaceCapacity(double spaceCapacity) {
    this->spaceCapacity = spaceCapacity;
}

