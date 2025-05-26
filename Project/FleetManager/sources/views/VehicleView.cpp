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

Truck *VehicleView::getTruck(VehicleContainer *container) {
    string licensePlate = getLicensePlate();
    Truck *truck = container->getTruck(licensePlate);
    return truck;
}

Van *VehicleView::getVan(VehicleContainer *container) {
    string licensePlate = getLicensePlate();
    Van *van = container->getVan(licensePlate);
    return van;
}

string VehicleView::getLicensePlate() {
    string licensePlate = Utils::getString("License Plate");
    return licensePlate;
}


ostream &operator<<(ostream &stream, const Date &date) {
    stream << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return stream;
}

void VehicleView::printTruck(const Truck *truck) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Vehicle " << truck->getLicensePlate() << " ***\n";
            cout << "Category: " << truck->getCategory() << endl;
            cout << "Brand: " << truck->getBrand() << endl;
            cout << "Model: " << truck->getModel() << endl;
            cout << "License Plate: " << truck->getLicensePlate() << endl;
            cout << "Year: " << truck->getYear() << endl;
            cout << "Mileage: " << truck->getMileage() << endl;
            cout << "Fuel (percentage): " << truck->getFuel() << endl;
            if (truck->getAvailability()) {
                cout << "Availability: available\n";
            }
            else {cout << "Availability: not available\n";}
            cout << "Insurance (ID): " << truck->getInsurance().getID() << endl;
            cout << "Insurance (End Date): " << truck->getInsurance().getEndDate() << endl;
            cout << "Insurance (Monthly Cost): " << truck->getInsurance().getMonthlyCost() << endl;
            cout << "Inspection (ID): " << truck->getInspection().getID() << endl;
            cout << "Inspection (Date): " << truck->getInspection().getDate() << endl;
            cout << "Storage Location (ID): " << truck->getVSL().getID() << "\n\n";
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleView::printVan(const Van *van) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Vehicle " << van->getLicensePlate() << " ***\n";
            cout << "Category: " << van->getCategory() << endl;
            cout << "Brand: " << van->getBrand() << endl;
            cout << "Model: " << van->getModel() << endl;
            cout << "License Plate: " << van->getLicensePlate() << endl;
            cout << "Year: " << van->getYear() << endl;
            cout << "Mileage: " << van->getMileage() << endl;
            cout << "Fuel (percentage): " << van->getFuel() << endl;
            if (van->getAvailability()) {
                cout << "Availability: available\n";
            }
            else {cout << "Availability: not available\n";}
            cout << "Insurance (ID): " << van->getInsurance().getID() << endl;
            cout << "Insurance (End Date): " << van->getInsurance().getEndDate() << endl;
            cout << "Insurance (Monthly Cost): " << van->getInsurance().getMonthlyCost() << endl;
            cout << "Inspection (ID): " << van->getInspection().getID() << endl;
            cout << "Inspection (Date): " << van->getInspection().getDate() << endl;
            cout << "Storage Location (ID): " << van->getVSL().getID() << "\n\n";
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleView::printListTrucks(list<Truck> &trucks) {
    cout << "\n*** List of Trucks: " << trucks.size() << " ***\n\n";
    list<Truck>::iterator it = trucks.begin();
    for (; it != trucks.end(); ++it) {
        printTruck(&*it);
    }
    cout <<"\n**********************************\n\n";
}

void VehicleView::printListVans(list<Van> &vans) {
    cout << "\n*** List of Vans: " << vans.size() << " ***\n\n";
    list<Van>::iterator it = vans.begin();
    for (; it != vans.end(); ++it) {
        printVan(&*it);
    }
    cout <<"\n**********************************\n\n";
}

double VehicleView::addFuel() {
    const double addedFuel = Utils::getDouble("Fuel percentage added");
    return addedFuel;
}

void VehicleView::insuranceAlert(Truck &truck) {
    cout << "\n!!! ATTENTION !!!\n";
    cout << "The vehicle " << truck.getLicensePlate() << "does not insurance active!\n";
}

void VehicleView::insuranceAlert(Van &van) {
    cout << "\n!!! ATTENTION !!!\n";
    cout << "The vehicle " << van.getLicensePlate() << "does not insurance active!\n";
}

void VehicleView::inspectionAlert(Truck &truck) {
    cout << "\n!!! ATTENTION !!!\n";
    cout << "The vehicle " << truck.getLicensePlate() << "is pending inspection!\n";
}

void VehicleView::inspectionAlert(Van &van) {
    cout << "\n!!! ATTENTION !!!\n";
    cout << "The vehicle " << van.getLicensePlate() << "is pending inspection!\n";
}

void VehicleView::fuelAlert(Truck &truck) {
    cout << "\n!!! ATTENTION !!!\n";
    cout << "The vehicle " << truck.getLicensePlate() << "does not have enough fuel!\n";
}

void VehicleView::fuelAlert(Van &van) {
    cout << "\n!!! ATTENTION !!!\n";
    cout << "The vehicle " << van.getLicensePlate() << "does not have enough fuel!\n";
}