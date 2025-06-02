//
// Created by lucas on 17/05/2025.
//

#include "Truck.h"

Truck::Truck() {
    this->weightCapacity = 0.0;
    this->insurance = nullptr;
    this->inspection = nullptr;
    this->vsl = nullptr;
}

Truck::Truck(CATEGORY category, string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double weightCapacity, bool available)
             : Vehicle(category, brand, model, year, licensePlate, mileage, fuel, available) {
    this->weightCapacity = weightCapacity;
}

Truck::~Truck() {}

bool Truck::canCarryLoad(Order &order) {
    if (weightCapacity > order.getCargoWeight()) {return true;}
    return false;
}

double Truck::getWeightCapacity() const {
    return weightCapacity;
}

void Truck::setWeightCapacity(double weightCapacity) {
    this->weightCapacity = weightCapacity;
}
