//
// Created by lucas on 19/05/2025.
//

#include "Enterprise.h"

Enterprise::Enterprise() :
    dataC(
        &vehicleC,
        &vslC,
        &driverC,
        &financialC,
        &tripC,
        &orderC,
      "../data/vehicle.json",
      "../data/vsl.json",
      "../data/driver.json",
      "../data/financial.json",
      "../data/trip.json",
      "../data/order.json") {
    this->name = "";
}

Enterprise::Enterprise(const string &name) :
    dataC(
    &vehicleC,
    &vslC,
    &driverC,
    &financialC,
    &tripC,
    &orderC,
    "../data/vehicle.json",
    "../data/vsl.json",
    "../data/driver.json",
    "../data/financial.json",
    "../data/trip.json",
    "../data/order.json") {
    this->name = name;
}

Enterprise::Enterprise(const Enterprise &enterprise) :
    name(enterprise.name),
    vehicleC(enterprise.vehicleC),
    vslC(enterprise.vslC),
    tripC(enterprise.tripC),
    driverC(enterprise.driverC),
    financialC(enterprise.financialC),
    orderC(enterprise.orderC),
    dataC(enterprise.dataC) {}


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

FinancialContainer &Enterprise::getFinancialContainer() {
    return this->financialC;
}

OrderContainer &Enterprise::getOrderContainer() {
    return this->orderC;
}

DataContainer &Enterprise::getDataContainer() {
    return this->dataC;
}