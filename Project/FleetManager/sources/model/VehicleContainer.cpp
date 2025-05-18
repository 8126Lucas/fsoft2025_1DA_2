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

}