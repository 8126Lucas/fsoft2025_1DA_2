//
// Created by lucas on 05/06/2025.
//

#include "VehicleStorageLocationSerialization.h"

void VehicleStorageLocationSerialization::toJSON(json &j, const VehicleStorageLocation &vsl) {
    j["id"] = vsl.getID();
    j["name"] = vsl.getName();
    j["address"] = vsl.getAddress();
    j["capacity"] = vsl.getCapacity();
    j["currentVehicleCount"] = vsl.getVehicleCount();
}

void VehicleStorageLocationSerialization::fromJSON(const json &j, VehicleStorageLocation &vsl) {
    vsl.setID(j["id"]);
    vsl.setName(j["name"]);
    vsl.setAddress(j["address"]);
    vsl.setCapacity(j["capacity"]);
    vsl.setCurrentVehicleCount(j["currentVehicleCount"]);
}