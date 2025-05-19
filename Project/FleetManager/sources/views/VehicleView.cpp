//
// Created by lucas on 18/05/2025.
//

#include "VehicleView.h"
#include "InvalidDataException.h"
#include "Utils.h"
#include "Vehicle.h"
#include "VehicleContainer.h"

Vehicle VehicleView::getVehicle() {
    Vehicle vehicle = Vehicle();

    bool flag_error = false;

    do {
        try {
            flag_error = false;
            CATEGORY category = static_cast<CATEGORY>(Utils::getInt("Category"));
            string brand = Utils::getString("Brand");
            string model = Utils::getString("Model");
            int year = Utils::getInt("Year");
            string licensePlate = Utils::getString("License Plate");
            double mileage = Utils::getDouble("Mileage");
            double fuel = Utils::getDouble("Fuel");
            bool available = true;
            vehicle = Vehicle(category, brand, model, year, licensePlate, mileage, fuel, available = true);
        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);

    return vehicle;
}

string VehicleView::getLicensePlate() {
    string licensePlate = Utils::getString("License Plate");
    return licensePlate;
}
