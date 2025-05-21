//
// Created by lucas on 19/05/2025.
//

#include "VehicleStorageLocationView.h"
#include <iostream>
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include "VehicleStorageLocation.h"
#include "VehicleView.h"
#include "VSLContainer.h"

using namespace std;

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

    return vsl;
}

int VehicleStorageLocationView::getID() {
    return Utils::getInt("VSL ID");
}

void VehicleStorageLocationView::printVSL(VehicleStorageLocation *vsl) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Storage Location " << vsl->getID() << " ***\n";
            cout << "ID: " << vsl->getID() << endl;
            cout << "Name: " << vsl->getName() << endl;
            cout << "Address: " << vsl->getAddress() << endl;
            cout << "Capacity: " << vsl->getCapacity() << " vehicles\n";
            cout << "Vehicles Stored: " << vsl->getVehicleCount() << " vehicles\n";
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleStorageLocationView::printListVSL(list<VehicleStorageLocation> &listVSL) {
    list<VehicleStorageLocation>::iterator it = listVSL.begin();
    for (; it != listVSL.end(); ++it) {
        printVSL(&*it);
    }
}

tuple<VehicleStorageLocation, Vehicle> VehicleStorageLocationView::addVehicle() {
    int vslID = getID();
    string licensePlate = VehicleView::getLicensePlate();
}