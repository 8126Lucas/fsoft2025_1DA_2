    //
// Created by lucas on 18/05/2025.
//

#include <iostream>
#include "VehicleView.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include "Vehicle.h"
#include "VehicleContainer.h"

using namespace std;

Vehicle VehicleView::addVehicle() {
    Vehicle vehicle = Utils::setVehicle();
    return vehicle;
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
    cout << "!!! ATENTION !!!\n";
    cout << "The vehicle " << vehicle.getLicensePlate() << "does not insurance active!\n";
}

void VehicleView::inspectionAlert(Vehicle &vehicle) {
    cout << "!!! ATENTION !!!\n";
    cout << "The vehicle " << vehicle.getLicensePlate() << "is pending inspection!\n";
}

void VehicleView::fuelAlert(Vehicle &vehicle) {
    cout << "!!! ATENTION !!!\n";
    cout << "The vehicle " << vehicle.getLicensePlate() << "does not have enough fuel!\n";
}