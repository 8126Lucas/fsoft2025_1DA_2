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

VehicleStorageLocation VehicleStorageLocationView::addVSL() {
    VehicleStorageLocation vsl = VehicleStorageLocation();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("ID");
            string name = Utils::getString("Name");
            string address = Utils::getString("Address");
            int capacity = Utils::getInt("Capacity");
            vsl.setID(id);
            vsl.setName(name);
            vsl.setAddress(address);
            vsl.setCapacity(capacity);
            vsl.setCurrentVehicleCount(0);
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

void VehicleStorageLocationView::printListVSL(list<VehicleStorageLocation> &listVSL) {
    list<VehicleStorageLocation>::iterator it = listVSL.begin();
    for (; it != listVSL.end(); ++it) {
        printVSL(&*it);
    }
}

void VehicleStorageLocationView::printListStoredVehicles(const VehicleStorageLocation &vsl) {
    list<Vehicle *> vehicles = vsl.getStoredVehicles(vsl.getID());
    list<Vehicle *>::iterator it = vehicles.begin();
    if (vehicles.empty()) {
        cout << "There are no stored Vehicles at this Storage Location!\n";
        return;
    }
    for (; it != vehicles.end(); ++it) {
        if (*it != NULL) {
            cout << "Vehicle: " << (*it)->getLicensePlate() << "\n";
        }
    }
}

VehicleStorageLocation *VehicleStorageLocationView::getVSL(VSLContainer *container) {
    int id = getID();
    VehicleStorageLocation *vsl = container->get(id);
    return vsl;
}

pair<int, Vehicle *> VehicleStorageLocationView::getVehicleVSLPair(VSLContainer *containerVSL, VehicleContainer *containerVehicle) {
    try
    {
        Vehicle *vehicle = VehicleView::getVehicle(containerVehicle);
        VehicleStorageLocation *vsl = getVSL(containerVSL);
        int vslID = vsl->getID();
        return {vslID, vehicle};
    } catch (InvalidDataException &error)
    {
        cout << error.what() << endl;
    }
    return {-1, nullptr};
}

void VehicleStorageLocationView::addVehicleToStorage(VSLContainer *containerVSL, VehicleContainer *containerVehicle) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            pair<int, Vehicle *> pair = getVehicleVSLPair(containerVSL, containerVehicle);
            VehicleStorageLocation *vsl = containerVSL->get(pair.first);
            if (vsl->getCapacity() == vsl->getVehicleCount()) {
                cout << "The Storage Location is full!\n";
                return;
            }
            vsl->getVehicles()[pair.first].push_back(pair.second);
            vsl->incrementVehicleCount();
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}

void VehicleStorageLocationView::removeVehicleFromStorage(VSLContainer *containerVSL, VehicleContainer *containerVehicle) {
    bool flag_error = false;
    do {
        pair<int, Vehicle *> pair = getVehicleVSLPair(containerVSL, containerVehicle);
        try {
            flag_error = false;
            VehicleStorageLocation *vsl = containerVSL->get(pair.first);
            if (vsl->getVehicleCount() == 0) {
                cout << "The Storage Location is empty!\n";
                return;
            }
            list<Vehicle *>::iterator it = vsl->getVehicles()[pair.first].begin();
            for (; it != vsl->getVehicles()[pair.first].end(); ++it) {
                if ((*it) == pair.second) {
                    vsl->getVehicles()[pair.first].erase(it);
                    vsl->decrementVehicleCount();
                }
                else {
                    string msg = "Vehicle " + pair.second->getLicensePlate() + " is not at Vehicle Storage Location "
                                + to_string(pair.first) +"!\n";
                    throw NonExistingDataException(msg);
                }
            }
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}