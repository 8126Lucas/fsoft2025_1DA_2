//
// Created by lucas on 18/05/2025.
//

#include <iostream>
#include "VehicleView.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Truck.h"
#include "Utils.h"
#include "Van.h"
#include "Vehicle.h"
#include "VehicleContainer.h"

using namespace std;

Truck VehicleView::addTruck() {
    Truck truck = Truck();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            string brand = Utils::getString("Brand");
            string model = Utils::getString("Model");
            int year = Utils::getInt("Year");
            string licensePlate = Utils::getString("License Plate");
            double mileage = Utils::getDouble("Mileage");
            double fuel = Utils::getDouble("Fuel");
            double weightCapacity = Utils::getDouble("Weight Capacity");

            truck.setCategory(TRUCK);
            truck.setBrand(brand);
            truck.setModel(model);
            truck.setYear(year);
            truck.setLicensePlate(licensePlate);
            truck.setMileage(mileage);
            truck.setFuel(fuel);
            truck.setWeightCapacity(weightCapacity);
            truck.setAvailability(true);
        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
    return truck;
}

Van VehicleView::addVan() {
    Van van = Van();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            string brand = Utils::getString("Brand");
            string model = Utils::getString("Model");
            int year = Utils::getInt("Year");
            string licensePlate = Utils::getString("License Plate");
            double mileage = Utils::getDouble("Mileage");
            double fuel = Utils::getDouble("Fuel");
            double spaceCapacity = Utils::getDouble("Space Capacity");

            van.setCategory(VAN);
            van.setBrand(brand);
            van.setModel(model);
            van.setYear(year);
            van.setLicensePlate(licensePlate);
            van.setMileage(mileage);
            van.setFuel(fuel);
            van.setSpaceCapacity(spaceCapacity);
            van.setAvailability(true);
        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
    return van;
}


string VehicleView::removeVehicle() {
    string licensePlate = Utils::getString("License Plate");
    return licensePlate;
}

Vehicle *VehicleView::getVehicle(VehicleContainer *container) {
    string licensePlate = getLicensePlate();
    Vehicle *vehicle = container->get(licensePlate);
    return vehicle;
}

string VehicleView::getLicensePlate() {
    string licensePlate = Utils::getString("License Plate");
    return licensePlate;
}

// void VehicleView::printCategory(const Vehicle *vehicle) {
//     if (vehicle->getCategory() == 1) {
//         cout << "Truck";
//     }
//     if (vehicle->getCategory() == 2) {
//         cout << "Van";
//     }
// }

void VehicleView::printVehicle(const Vehicle *vehicle) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Vehicle " << vehicle->getLicensePlate() << " ***\n";
            cout << "Category: " << vehicle->getCategory() << endl;
            cout << "Brand: " << vehicle->getBrand() << endl;
            cout << "Model: " << vehicle->getModel() << endl;
            cout << "License Plate: " << vehicle->getLicensePlate() << endl;
            cout << "Year: " << vehicle->getYear() << endl;
            cout << "Mileage: " << vehicle->getMileage() << endl;
            cout << "Fuel (percentage): " << vehicle->getFuel() << endl;
            if (vehicle->getAvailability()) {
                cout << "Availability: available\n";
            }
            else {cout << "Availability: not available\n";}
            cout << "Insurance (ID): " << vehicle->getInsurance() << endl;
            cout << "Inspection (ID): " << vehicle->getInspection() << endl;
            cout << "Storage Location (ID): " << vehicle->getVSL() << endl;
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleView::printListVehicles(list<Vehicle> &vehicles) {
    cout << "\n*** List of Vehicles: " << vehicles.size() << " ***\n\n";
    list<Vehicle>::iterator it = vehicles.begin();
    for (; it != vehicles.end(); ++it) {
        printVehicle(&*it);
    }
}

double VehicleView::addFuel() {
    const double addedFuel = Utils::getDouble("Fuel percentage added");
    return addedFuel;
}

void VehicleView::insuranceAlert(Vehicle &vehicle) {
    cout << "!!! ATTENTION !!!\n";
    cout << "The vehicle " << vehicle.getLicensePlate() << "does not insurance active!\n";
}

void VehicleView::inspectionAlert(Vehicle &vehicle) {
    cout << "!!! ATTENTION !!!\n";
    cout << "The vehicle " << vehicle.getLicensePlate() << "is pending inspection!\n";
}

void VehicleView::fuelAlert(Vehicle &vehicle) {
    cout << "!!! ATTENTION !!!\n";
    cout << "The vehicle " << vehicle.getLicensePlate() << "does not have enough fuel!\n";
}