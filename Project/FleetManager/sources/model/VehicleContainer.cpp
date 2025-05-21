//
// Created by lucas on 18/05/2025.
//

#include "VehicleContainer.h"
    #include "DuplicatedDataException.h"
    #include "NonExistingDataException.h"
#include "Utils.h"


list<Vehicle>::iterator VehicleContainer::search(string &licensePlate) {
    list<Vehicle>::iterator it = this->vehicles.begin();
    for (; it != this->vehicles.end(); ++it) {
        if ((*it) == licensePlate) {
            return it;
        }
    }
    return it;
}

Vehicle *VehicleContainer::get(string &licensePlate) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        return &(*it);
    }
    return NULL;
}

void VehicleContainer::add(Vehicle &vehicle) {
    list<Vehicle>::iterator it = search(vehicle.getLicensePlate());
    if (it == this->vehicles.end()) {
        this->vehicles.push_back(vehicle);
    }
    else {
        string msg = "Vehicle: " + vehicle.getLicensePlate();
        throw DuplicatedDataException(msg);
    }
}

void VehicleContainer::remove(string &licensePlate) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        this->vehicles.erase(it);
    }
    else {
        string msg = "Vehicle: " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

list<Vehicle> VehicleContainer::list() {
    list<Vehicle> newList(this->vehicles);
    return newList;
}

list<Vehicle> VehicleContainer::list(bool available) {
    list<Vehicle> newList;
    list<Vehicle>::iterator it = this->vehicles.begin();
    for (; it != this->vehicles.end(); ++it) {
        if (it->getAvailability() == true) {
            newList.push_back(*it);
        }
    }
    return newList;
}

void VehicleContainer::update(string &licensePlate, const Insurance insurance) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        it->setInsurance(insurance);
    }
    else {
        string msg = "Vehicle (insurance): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::update(string &licensePlate, const Inspection inspection) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        it->setInspection(inspection);
    }
    else {
        string msg = "Vehicle (inspection): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::update(string &licensePlate, VehicleStorageLocation vsl) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        it->setVSL(vsl);
    }
    else {
        string msg = "Vehicle (vsl): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::updateFuel(string &licensePlate) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        it->addFuel();
    }
    else {
        string msg = "Vehicle (fuel): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::updateMileage(string &licensePlate, Trip &trip) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        it->updateMileage(trip);
    }
    else {
        string msg = "Vehicle (mileage): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}

void VehicleContainer::updateAvailability(string &licensePlate, bool available) {
    list<Vehicle>::iterator it = search(licensePlate);
    if (it != this->vehicles.end()) {
        it->setAvailability(available);
    }
    else {
        string msg = "Vehicle (mileage): " + licensePlate;
        throw NonExistingDataException(msg);
    }
}