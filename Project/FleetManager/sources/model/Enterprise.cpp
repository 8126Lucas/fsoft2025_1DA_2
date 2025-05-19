//
// Created by lucas on 19/05/2025.
//

#include "Enterprise.h"

Enterprise::Enterprise() : vslC() {
    this->name = "";
}

Enterprise::Enterprise(const string &name) : vslC() {
    this->name = name;
}

Enterprise::Enterprise(const Enterprise &enterprise) : vslC(enterprise.vslC) {
    this->name = enterprise.name;
    this->vehicleC = enterprise.vehicleC;
    this->tripC = enterprise.tripC;
    this->driverC = enterprise.driverC;
    this->orderC = enterprise.orderC;
}

const string &Enterprise::getName() const {
    return name;
}

void Enterprise::setName(const string &name) {
    this->name = name;
}

VehicleContainer &Enterprise::getVehicleContainer() {
    return this->vehicleC;
}

VSLContainer &Enterprise::getVSLContainer() {
    return this->vslC;
}

TripContainer &Enterprise::getTripContainer() {
    return this->tripC;
}

DriverContainer &Enterprise::getDriverContainer() {
    return this->driverC;
}

OrderContainer &Enterprise::getOrderContainer() {
    return this->orderC;
}