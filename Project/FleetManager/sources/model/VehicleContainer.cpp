//
// Created by lucas on 18/05/2025.
//

#include "VehicleContainer.h"
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

void VehicleContainer::add(const Vehicle &vehicle) {

}

void VehicleContainer::remove(string &licensePlate) {

}

list<Vehicle> VehicleContainer::list() {

}