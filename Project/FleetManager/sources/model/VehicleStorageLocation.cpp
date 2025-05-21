//
// Created by lucas on 17/05/2025.
//

#include "VehicleStorageLocation.h"

#include "Vehicle.h"
#include "VehicleStorageLocationView.h"

VehicleStorageLocation::VehicleStorageLocation(): id(0), capacity(0), currentVehicleCount(0) {}

VehicleStorageLocation::VehicleStorageLocation(int id, string name, string address,
                                                int capacity, int currentVehicleCount) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->capacity = capacity;
    this->currentVehicleCount = currentVehicleCount;
}

VehicleStorageLocation::~VehicleStorageLocation() {}

VehicleStorageLocation VehicleStorageLocation::addStorageLocation() {
    return VehicleStorageLocationView::getVSL();;
}

int VehicleStorageLocation::removeStorageLocation() {
    return VehicleStorageLocationView::getID();
}

void VehicleStorageLocation::listStorageLocations(list<VehicleStorageLocation> &listVSL) {
    VehicleStorageLocationView::printListVSL(listVSL);
}



int VehicleStorageLocation::getAvailableSpace() {
    return this->capacity - this->currentVehicleCount;
}

void VehicleStorageLocation::incrementVehicleCount() {
    this->currentVehicleCount++;
}

int VehicleStorageLocation::getID() const {
    return id;
}

string VehicleStorageLocation::getName() const {
    return name;
}

string VehicleStorageLocation::getAddress() const {
    return address;
}

int VehicleStorageLocation::getCapacity() const {
    return capacity;
}

int VehicleStorageLocation::getVehicleCount() const {
    return currentVehicleCount;
}