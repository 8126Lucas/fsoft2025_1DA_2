//
// Created by lucas on 17/05/2025.
//

#include "VehicleStorageLocation.h"

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
    VehicleStorageLocation vsl = VehicleStorageLocationView::getVSL();
    return vsl;
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
