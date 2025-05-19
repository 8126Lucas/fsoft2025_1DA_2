//
// Created by lucas on 18/05/2025.
//

#include "VehicleView.h"
#include "Utils.h"
#include "Vehicle.h"
#include "VehicleContainer.h"

void VehicleView::addVehicle() {
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
