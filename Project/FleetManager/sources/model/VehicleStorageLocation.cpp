//
// Created by lucas on 17/05/2025.
//

#include "VehicleStorageLocation.h"

#include <algorithm>

#include "NonExistingDataException.h"
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


int VehicleStorageLocation::getAvailableSpace() const {
    return this->capacity - this->currentVehicleCount;
}

void VehicleStorageLocation::incrementVehicleCount() {
    this->currentVehicleCount++;
}

void VehicleStorageLocation::decrementVehicleCount() {
    this->currentVehicleCount--;
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

unordered_map<int, list<Vehicle *>> VehicleStorageLocation::getVehicles() const {
    return vehicles;
}

list<Vehicle *> VehicleStorageLocation::getStoredVehicles(int id) const {
    return vehicles.at(id);
}

void VehicleStorageLocation::setID(int id) {
    this->id = id;
}

void VehicleStorageLocation::setName(string name) {
    this->name = name;
}

void VehicleStorageLocation::setAddress(string address) {
    this->address = address;
}

void VehicleStorageLocation::setCapacity(int capacity) {
    this->capacity = capacity;
}

void VehicleStorageLocation::setCurrentVehicleCount(int currentVehicleCount) {
    this->currentVehicleCount = currentVehicleCount;
}