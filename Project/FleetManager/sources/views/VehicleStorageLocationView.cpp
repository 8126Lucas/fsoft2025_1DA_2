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

VehicleStorageLocation *VehicleStorageLocationView::addVSL() {
    VehicleStorageLocation *vsl = new VehicleStorageLocation();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("ID");
            string name = Utils::getString("Name");
            string address = Utils::getString("Address");
            int capacity = Utils::getInt("Capacity");
            vsl->setID(id);
            vsl->setName(name);
            vsl->setAddress(address);
            vsl->setCapacity(capacity);
            vsl->setCurrentVehicleCount(0);
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);

    return vsl;
}

int VehicleStorageLocationView::removeVSL() {
    int id = Utils::getInt("VSL ID");
    return id;
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
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleStorageLocationView::printListVSL(list<VehicleStorageLocation*> &listVSL) {
    if (listVSL.empty()) {
        cout << "\nTHERE ARE NO STORAGE LOCATIONS RECORDED!\n";
    }
    else {
        list<VehicleStorageLocation*>::iterator it = listVSL.begin();
        for (; it != listVSL.end(); ++it) {
            printVSL(*it);
        }
    }
}

void VehicleStorageLocationView::printListStoredVehicles(const VehicleStorageLocation &vsl) {
    if (&vsl != nullptr) {
        try {
            list<Vehicle *> vehicles = vsl.getStoredVehicles(vsl.getID());
            list<Vehicle *>::iterator it = vehicles.begin();
            if (vehicles.empty()) {
                cout << "THERE ARE NO STORED VEHICLES AT THIS STORAGE LOCATION!\n";
                return;
            }
            for (; it != vehicles.end(); ++it) {
                if (*it != nullptr) {
                    cout << "Vehicle: " << (*it)->getLicensePlate() << "\n";
                }
            }
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
        }
    }
}

VehicleStorageLocation *VehicleStorageLocationView::getVSL(VSLContainer *container) {
    int id = getID();
    VehicleStorageLocation *vsl = container->get(id);
    return vsl;
}

void VehicleStorageLocationView::addVehicleToStorage(VehicleStorageLocation *vsl, Vehicle *vehicle) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            if (vsl->getCapacity() == vsl->getVehicleCount()) {
                cout << "The Storage Location is full!\n";
                return;
            }
            vsl->addVehicle(vehicle);
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleStorageLocationView::removeVehicleFromStorage(VehicleStorageLocation *vsl, Vehicle *vehicle) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            if (vsl->getVehicleCount() == 0) {
                cout << "The Storage Location is empty!\n";
                return;
            }
            vsl->removeVehicle(vehicle);
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}