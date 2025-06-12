//
// Created by lucas on 05/06/2025.
//

#include "VehicleStorageLocationSerialization.h"

#include "Vehicle.h"

void VehicleStorageLocationSerialization::toJSON(json &j, const VehicleStorageLocation &vsl) {
    j["id"] = vsl.getID();
    j["name"] = vsl.getName();
    j["address"] = vsl.getAddress();
    j["capacity"] = vsl.getCapacity();
    j["currentVehicleCount"] = vsl.getVehicleCount();
    j["vehicles"] = json::array();
    const unordered_map<int, list<Vehicle *>> &vehicleMap = vsl.getVehicles();
    unordered_map<int, list<Vehicle *>>::const_iterator it = vehicleMap.find(vsl.getID());

    if (it != vehicleMap.end()) {
        for (const Vehicle *vehicle : it->second) {
            json vehicleJSON;
            vehicleJSON["vehicleLicensePlate"] = vehicle->getLicensePlate();
            j["vehicles"].push_back(vehicleJSON);
        }
    }
}

void VehicleStorageLocationSerialization::fromJSON(const json &j, VehicleStorageLocation &vsl) {
    vsl.setID(j["id"]);
    vsl.setName(j["name"]);
    vsl.setAddress(j["address"]);
    vsl.setCapacity(j["capacity"]);
    vsl.setCurrentVehicleCount(j["currentVehicleCount"]);
}