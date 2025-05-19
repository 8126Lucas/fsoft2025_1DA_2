//
// Created by lucas on 17/05/2025.
//

#include "VehicleStorageLocation.h"

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

}

int VehicleStorageLocation::getID() const {
    return id;
}
