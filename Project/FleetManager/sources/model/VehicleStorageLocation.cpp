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

VehicleStorageLocation VehicleStorageLocation::addStorageLocation() {
    return VehicleStorageLocationView::getVSL();
}

int VehicleStorageLocation::removeStorageLocation() {
    return VehicleStorageLocationView::getID();
}

void VehicleStorageLocation::listStorageLocations(list<VehicleStorageLocation> &listVSL) {
    VehicleStorageLocationView::printListVSL(listVSL);
}

void VehicleStorageLocation::listStoredVehicles() const {
    VehicleStorageLocationView::printListStoredVehicles(*this);
}

void VehicleStorageLocation::addVehicleToStorage(VehicleContainer *container) {
    bool flag_error = false;
    do {
        pair<int, Vehicle *> pair = VehicleStorageLocationView::addVehicle(container);
        try {
            flag_error = false;
            this->vehicles[pair.first].push_back(pair.second);
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleStorageLocation::removeVehicleFromStorage(VehicleContainer *container) {
    bool flag_error = false;
    do {
        pair<int, Vehicle *> pair = VehicleStorageLocationView::addVehicle(container);
        try {
            flag_error = false;
            unordered_map<int, list<Vehicle *>>::iterator mapIT = this->vehicles.find(pair.first);
            if (mapIT != this->vehicles.end()) {
                list<Vehicle *>::iterator vehicleIT = find(mapIT->second.begin(), mapIT->second.end(), pair.second);
                if (vehicleIT != mapIT->second.end()) {
                    mapIT->second.erase(vehicleIT);
                }
                else {
                    string msg = "Vehicle " + pair.second->getLicensePlate() + " is not at Vehicle Storage Location "
                                + to_string(pair.first) +"!\n";
                    throw NonExistingDataException(msg);
                }
            }
            else {
                string msg = "Vehicle Storage Location " + to_string(pair.first) + " does not exist!\n";
                throw NonExistingDataException(msg);
            }
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

int VehicleStorageLocation::getAvailableSpace() const {
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

unordered_map<int, list<Vehicle *>> VehicleStorageLocation::getVehicles() const {
    return vehicles;
}

list<Vehicle *> VehicleStorageLocation::getStoredVehicles(int id) const {
    return vehicles.at(id);
}