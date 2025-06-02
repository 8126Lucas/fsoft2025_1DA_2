//
// Created by lucas on 18/05/2025.
//

#include "VehicleContainer.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"


list<Truck>::iterator VehicleContainer::searchTruck(const string &licensePlate) {
    list<Truck>::iterator it = this->trucks.begin();
    for (; it != this->trucks.end(); ++it) {
        if (it->getLicensePlate() == licensePlate) {
            return it;
        }
    }
    return trucks.end();
}

list<Van>::iterator VehicleContainer::searchVan(const string &licensePlate) {
    list<Van>::iterator it = this->vans.begin();
    for (; it != this->vans.end(); ++it) {
        if (it->getLicensePlate() == licensePlate) {
            return it;
        }
    }
    return vans.end();
}

Vehicle *VehicleContainer::get(string &licensePlate)
{
    try{
        Truck *truck = getTruck(licensePlate);
        Van *van = getVan(licensePlate);
        if (truck == nullptr && van != nullptr) {return van;}
        if (truck != nullptr && van == nullptr) {return truck;}
        throw NonExistingDataException("Vehicle's License Plate");
    }catch (NonExistingDataException &error)
    {
        cout << error.what() << endl;
    }
    return nullptr;
}

Truck *VehicleContainer::getTruck(string &licensePlate) {
    list<Truck>::iterator it = searchTruck(licensePlate);
    if (it != this->trucks.end()) {
        return &(*it);
    }
    return nullptr;
}

Van *VehicleContainer::getVan(string &licensePlate) {
    list<Van>::iterator it = searchVan(licensePlate);
    if (it != this->vans.end()) {
        return &(*it);
    }
    return nullptr;
}


void VehicleContainer::add(Truck &truck) {
    list<Truck>::iterator it = searchTruck(truck.getLicensePlate());
    if (it == this->trucks.end()) {
        this->trucks.push_back(truck);
    }
    else {
        string msg = "Vehicle (Truck): " + truck.getLicensePlate();
        throw DuplicatedDataException(msg);
    }
}

void VehicleContainer::add(Van &van) {
    list<Van>::iterator it = searchVan(van.getLicensePlate());
    if (it == this->vans.end()) {
        this->vans.push_back(van);
    }
    else {
        string msg = "Vehicle (Van): " + van.getLicensePlate();
        throw DuplicatedDataException(msg);
    }
}

void VehicleContainer::remove(const string &licensePlate)
{
    try
    {
        const list<Truck>::iterator truckIT = searchTruck(licensePlate);
        const list<Van>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            this->trucks.erase(truckIT);
        }
        else if (vanIT != this->vans.end()) {
            this->vans.erase(vanIT);
        }
        else
        {
            throw(NonExistingDataException("Vehicle " + licensePlate));
        }
    }catch (NonExistingDataException &error)
        {
            cout << error.what() << endl;
        }

}

list<Truck> VehicleContainer::listTrucks() {
    list<Truck> newList(this->trucks);
    return newList;
}

list<Truck> VehicleContainer::listTrucks(const bool available) {
    list<Truck> newList;
    list<Truck>::iterator it = this->trucks.begin();
    for (; it != this->trucks.end(); ++it) {
        if (it->getAvailability() == available) {
            newList.push_back(*it);
        }
    }
    return newList;
}

list<Van> VehicleContainer::listVans() {
    list<Van> newList(this->vans);
    return newList;
}

list<Van> VehicleContainer::listVans(bool available) {
    list<Van> newList;
    list<Van>::iterator it = this->vans.begin();
    for (; it != this->vans.end(); ++it) {
        if (it->getAvailability() == available) {
            newList.push_back(*it);
        }
    }
    return newList;
}

void VehicleContainer::update(string &licensePlate, Insurance *insurance) {
    list<Truck>::iterator truckIT = searchTruck(licensePlate);
    list<Van>::iterator vanIT = searchVan(licensePlate);
    if (truckIT != this->trucks.end()) {
        truckIT->setInsurance(insurance);
    }
    else if (vanIT != this->vans.end()) {
        vanIT->setInsurance(insurance);
    }
    else {
        string msg = "Vehicle (insurance): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::update(string &licensePlate, Inspection *inspection) {
    list<Truck>::iterator truckIT = searchTruck(licensePlate);
    list<Van>::iterator vanIT = searchVan(licensePlate);
    if (truckIT != this->trucks.end()) {
        truckIT->setInspection(inspection);
    }
    else if (vanIT != this->vans.end()) {
        vanIT->setInspection(inspection);
    }
    else {
        string msg = "Vehicle (inspection): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::update(string &licensePlate, VehicleStorageLocation *vsl) {
        list<Truck>::iterator truckIT = searchTruck(licensePlate);
        list<Van>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            truckIT->setVSL(vsl);
        }
        else if (vanIT != this->vans.end()) {
            vanIT->setVSL(vsl);
        }
        else {
            string msg = "Vehicle (VSL): " + licensePlate;
            throw NonExistingDataException(msg);
        }

}

void VehicleContainer::updateFuel(string &licensePlate, double addedFuel) {
    try
    {
        list<Truck>::iterator truckIT = searchTruck(licensePlate);
        list<Van>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            truckIT->addFuel(addedFuel);
        }
        else if (vanIT != this->vans.end()) {
            vanIT->addFuel(addedFuel);
        }
        else {
            string msg = "Vehicle (fuel): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    }catch (NonExistingDataException &error)
    {
        cout << error.what() << endl;
    }
}

void VehicleContainer::updateMileage(string &licensePlate, Trip &trip) {

        list<Truck>::iterator truckIT = searchTruck(licensePlate);
        list<Van>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            truckIT->updateMileage(trip);
        }
        else if (vanIT != this->vans.end()) {
            vanIT->updateMileage(trip);
        }
        else {
            string msg = "Vehicle (mileage): " + licensePlate;
            throw NonExistingDataException(msg);
        }
}

void VehicleContainer::updateAvailability(string &licensePlate, bool available) {
    list<Truck>::iterator truckIT = searchTruck(licensePlate);
    list<Van>::iterator vanIT = searchVan(licensePlate);
    if (truckIT != this->trucks.end()) {
        truckIT->setAvailability(available);
    }
    else if (vanIT != this->vans.end()) {
        vanIT->setAvailability(available);
    }
    else {
        string msg = "Vehicle (availability): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}