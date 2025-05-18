//
// Created by lucas on 17/05/2025.
//

#include "Vehicle.h"
#include "Utils.h"
#include "VehicleContainer.h"

void Vehicle::addVehicle() {
    Vehicle vehicle;

    vehicle.category = static_cast<CATEGORY>(Utils::getInt("Category"));
    vehicle.brand = Utils::getString("Brand");
    vehicle.model = Utils::getString("Model");
    vehicle.year = Utils::getInt("Year");
    vehicle.licensePlate = Utils::getString("License Plate");
    vehicle.mileage = Utils::getDouble("Mileage");
    vehicle.fuel = Utils::getDouble("Fuel");

    vehicle = Vehicle(category, brand, model, year, licensePlate, mileage, fuel);

    VehicleContainer::add(vehicle);
}

void Vehicle::removeVehicle() {

}