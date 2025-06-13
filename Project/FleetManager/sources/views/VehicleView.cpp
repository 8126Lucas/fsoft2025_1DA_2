//
// Created by lucas on 18/05/2025.
//

#include <iostream>
#include "VehicleView.h"
#include "Date.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Van.h"
#include "VehicleContainer.h"
#include "Utils.h"

using namespace std;

Truck *VehicleView::addTruck() {
    Truck *truck = new Truck();
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

            truck->setCategory(TRUCK);
            truck->setBrand(brand);
            truck->setModel(model);
            truck->setYear(year);
            truck->setLicensePlate(licensePlate);
            truck->setMileage(mileage);
            truck->setFuel(fuel);
            truck->setWeightCapacity(weightCapacity);
            truck->setAvailability(true);

            truck->setInspection(nullptr);
            truck->setInsurance(nullptr);
            truck->setVSL(nullptr);
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
    return truck;
}

Van *VehicleView::addVan() {
    Van *van = new Van();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            string brand = Utils::getString("Brand");
            string model = Utils::getString("Model");
            int year = Utils::getInt("Year");
            string licensePlate = Utils::getString("License Plate");
            double mileage = Utils::getDouble("Mileage (KM)");
            double fuel = Utils::getDouble("Fuel (%)");
            double spaceCapacity = Utils::getDouble("Space Capacity");

            van->setCategory(VAN);
            van->setBrand(brand);
            van->setModel(model);
            van->setYear(year);
            van->setLicensePlate(licensePlate);
            van->setMileage(mileage);
            van->setFuel(fuel);
            van->setSpaceCapacity(spaceCapacity);
            van->setAvailability(true);

            van->setInspection(nullptr);
            van->setInsurance(nullptr);
            van->setVSL(nullptr);
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
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
            if (truck->getInsurance() != nullptr) {
                cout << "Insurance (ID): " << truck->getInsurance()->getID() << endl;
                cout << "Insurance (End Date): " << truck->getInsurance()->getEndDate()  << " (" << truck->getInsurance()->getRemainingDays() << " days remaining)" << endl;
                cout << "Insurance (Monthly Cost): " << truck->getInsurance()->getMonthlyCost() << " €\n";
            }
            else {insuranceAlert(truck);}
            if (truck->getInspection() != nullptr) {
                cout << "Inspection (ID): " << truck->getInspection()->getID() << endl;
                cout << "Inspection (Date): " << truck->getInspection()->getDate() << " (" << truck->getInspection()->getRemainingDays() << " days remaining)" << endl;
                cout << "Inspection (Cost): " << truck->getInspection()->getCost() << " €\n";
            }
            else {inspectionAlert(truck);}
            if (truck->getVSL() != nullptr) {cout << "Storage Location (ID): " << truck->getVSL()->getID() << "\n\n";}
            else {cout << "Storage Location: no storage location\n\n";}

            if (truck->getInsurance() != nullptr) {
                if (truck->getInsurance()->isExpired()) {cout << "!!! Insurance has expired !!!\n";}
            }
            if (truck->getInspection() != nullptr) {
                if (truck->getInspection()->isDued()) {cout << "!!! Inspection is dued !!!\n";}
            }
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
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
            if (van->getInsurance() != nullptr) {
                cout << "Insurance (ID): " << van->getInsurance()->getID() << endl;
                cout << "Insurance (End Date): " << van->getInsurance()->getEndDate() << " (" << van->getInsurance()->getRemainingDays() << " days remaining)" << endl;
                cout << "Insurance (Monthly Cost): " << van->getInsurance()->getMonthlyCost() << " €\n";
            }
            else {insuranceAlert(van);}
            if (van->getInspection() != nullptr) {
                cout << "Inspection (ID): " << van->getInspection()->getID() << endl;
                cout << "Inspection (Date): " << van->getInspection()->getDate() << " (" << van->getInspection()->getRemainingDays() << " days remaining)" << endl;
                cout << "Inspection (Cost): " << van->getInspection()->getCost() << " €\n";
            }
            else {inspectionAlert(van);}
            if (van->getVSL() != nullptr) {cout << "Storage Location (ID): " << van->getVSL()->getID() << "\n\n";}
            else {cout << "Storage Location: no storage location\n\n";}

            if (van->getInsurance() != nullptr) {
                if (van->getInsurance()->isExpired()) {cout << "!!! Insurance has expired !!!\n";}
            }
            if (van->getInspection() != nullptr) {
                if (van->getInspection()->isDued()) {cout << "!!! Inspection is dued !!!\n";}
            }
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleView::printListTrucks(list<Truck*> &trucks) {
    if (trucks.empty()) {
        cout << "\nTHERE ARE NO TRUCKS (WITH SUCH CONDITIONS) IN THE RECORDS!\n";
    }
    else {
        cout << "\n*** List of Trucks: " << trucks.size() << " ***\n\n";
        list<Truck*>::iterator it = trucks.begin();
        for (; it != trucks.end(); ++it) {
            printTruck(*it);
        }
        cout <<"**********************************\n\n";
    }
}

void VehicleView::printListVans(list<Van*> &vans) {
    if (vans.empty()) {
        cout << "\nTHERE ARE NO VANS (WITH SUCH CONDITIONS) IN THE RECORDS!\n";
    }
    else {
        cout << "\n*** List of Vans: " << vans.size() << " ***\n\n";
        list<Van*>::iterator it = vans.begin();
        for (; it != vans.end(); ++it) {
            printVan(*it);
        }
        cout <<"**********************************\n\n";
    }
}

double VehicleView::addFuel(Vehicle *vehicle) {
    bool flag_error = false;
    double addedFuel = 0;
    do {
        try {
            flag_error = false;
            addedFuel = Utils::getDouble("Fuel percentage added");
            if ((vehicle->getFuel() + addedFuel) > 100 || addedFuel <= 0) {
                throw InvalidDataException("Added Fuel Percentage");
            }
        } catch (InvalidDataException &error) {
            flag_error = true;
            cout << error.what() << endl;
        }
    } while (flag_error);
    return addedFuel;
}

void VehicleView::insuranceAlert(const Truck *truck) {
    cout << "!!! ATTENTION !!! The vehicle " << truck->getLicensePlate() << " does not insurance active!\n";
}

void VehicleView::insuranceAlert(const Van *van) {
    cout << "!!! ATTENTION !!! The vehicle " << van->getLicensePlate() << " does not insurance active!\n";
}

void VehicleView::inspectionAlert(const Truck *truck) {
    cout << "!!! ATTENTION !!! The vehicle " << truck->getLicensePlate() << " is pending inspection!\n";
}

void VehicleView::inspectionAlert(const Van *van) {
    cout << "!!! ATTENTION !!! The vehicle " << van->getLicensePlate() << " is pending inspection!\n";
}

void VehicleView::fuelAlert(const Truck *truck) {
    cout << "!!! ATTENTION !!! The vehicle " << truck->getLicensePlate() << " does not have enough fuel!\n";
}

void VehicleView::fuelAlert(const Van *van) {
    cout << "!!! ATTENTION !!! The vehicle " << van->getLicensePlate() << " does not have enough fuel!\n";
}