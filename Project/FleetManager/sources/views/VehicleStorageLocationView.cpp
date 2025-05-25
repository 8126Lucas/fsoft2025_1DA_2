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
    VehicleStorageLocation vsl = Utils::setVSL();
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
    list<Vehicle *> vehiclesPtr = vsl.getStoredVehicles(vsl.getID());
    list<Vehicle> vehicles;
    list<Vehicle *>::iterator it = vehiclesPtr.begin();
    for (; it != vehiclesPtr.end(); ++it) {
        const Vehicle *oneVehicle = *it;
        if (oneVehicle != NULL) {
            const Vehicle &vehicle = *oneVehicle;
            vehicles.push_back(vehicle);
        }
    }
    VehicleView::printListVehicles(vehicles);
}

VehicleStorageLocation *VehicleStorageLocationView::getVSL(VSLContainer *container) {
    int id = getID();
    VehicleStorageLocation *vsl = container->get(id);
    return vsl;
}

pair<int, Vehicle *> VehicleStorageLocationView::getVehicleVSLPair(VSLContainer *containerVSL, VehicleContainer *containerVehicle) {
    Vehicle *vehicle = VehicleView::getVehicle(containerVehicle);
    VehicleStorageLocation *vsl = getVSL(containerVSL);
    int vslID = vsl->getID();
    return {vslID, vehicle};
}

void VehicleStorageLocationView::addVehicleToStorage(VSLContainer *containerVSL, VehicleContainer *containerVehicle) {
    bool flag_error = false;
    do {
        pair<int, Vehicle *> pair = getVehicleVSLPair(containerVSL, containerVehicle);
        VehicleStorageLocation *vsl = containerVSL->get(pair.first);
        try {
            flag_error = false;
            vsl->getVehicles()[pair.first].push_back(pair.second);
        } catch (NonExistingDataException &error) {
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
            list<Vehicle *>::iterator it = vsl->getVehicles()[pair.first].begin();
            for (; it != vsl->getVehicles()[pair.first].end(); ++it) {
                if ((*it) == pair.second) {
                    vsl->getVehicles()[pair.first].erase(it);
                }
                else {
                    string msg = "Vehicle " + pair.second->getLicensePlate() + " is not at Vehicle Storage Location "
                                + to_string(pair.first) +"!\n";
                    throw NonExistingDataException(msg);
                }
            }
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}