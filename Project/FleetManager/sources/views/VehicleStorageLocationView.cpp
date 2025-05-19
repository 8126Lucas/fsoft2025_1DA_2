//
// Created by lucas on 19/05/2025.
//

#include "VehicleStorageLocationView.h"
#include "InvalidDataException.h"
#include "Utils.h"
#include "VehicleStorageLocation.h"
#include "VSLContainer.h"

VehicleStorageLocation VehicleStorageLocationView::getVSL() {
    VehicleStorageLocation vsl = VehicleStorageLocation();

    bool flag_error = false;

    do {
        try {
            flag_error = false;
            int id = Utils::getInt("ID");
            string name = Utils::getString("Name");
            string address = Utils::getString("Address");
            int capacity = Utils::getInt("Capacity");
            int currentVehicleCount = 0;
            vsl = VehicleStorageLocation(id, name, address, capacity, currentVehicleCount);
        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

int VehicleStorageLocationView::getID() {
    int id = Utils::getInt("ID");
    return id;
}