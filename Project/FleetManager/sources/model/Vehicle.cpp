//
// Created by lucas on 17/05/2025.
//

#include "Vehicle.h"
#include "Utils.h"
#include "VehicleContainer.h"

Vehicle::Vehicle() {}

Vehicle::Vehicle(CATEGORY category, string &brand, string &model, int year, string &licensePlate,
                double mileage, double fuel, bool available = true) {
    Vehicle::addVehicle();
}


void Vehicle::addVehicle() {
    Vehicle vehicle = Vehicle();

    vehicle.category = static_cast<CATEGORY>(Utils::getInt("Category"));
    vehicle.brand = Utils::getString("Brand");
    vehicle.model = Utils::getString("Model");
    vehicle.year = Utils::getInt("Year");
    vehicle.licensePlate = Utils::getString("License Plate");
    vehicle.mileage = Utils::getDouble("Mileage");
    vehicle.fuel = Utils::getDouble("Fuel");
    vehicle.available = true;

    vehicle = Vehicle(category, brand, model, year, licensePlate, mileage, fuel, available = true);

    VehicleContainer::add(vehicle);
}

void Vehicle::removeVehicle() {
    string licensePlate = Utils::getString("License Plate");
    VehicleContainer::remove(licensePlate);
}

string &Vehicle::getLicensePlate() {
    return licensePlate;
}

void Vehicle::setInsurance(const Insurance insurance) {
    this->insurance = insurance;
}

void Vehicle::setInspection(const Inspection inspection) {
    this->inspection = inspection;
}

void Vehicle::setVSL(const VehicleStorageLocation vsl) {
    this->vsl = vsl;
}

