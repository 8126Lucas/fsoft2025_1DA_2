//
// Created by lucas on 18/05/2025.
//

#include "VSLContainer.h"



#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"

list<VehicleStorageLocation*>::iterator VSLContainer::search(int id) {
    list<VehicleStorageLocation*>::iterator it = this->locations.begin();
    for (; it != this->locations.end(); ++it) {
        if ((*it)->getID() == id) {
            return it;
        }
    }
    return locations.end();
}

VSLContainer::~VSLContainer() {
    for (VehicleStorageLocation *vsl : locations) {
        delete vsl;
    }
    locations.clear();
}

void VSLContainer::add(VehicleStorageLocation *location) {
    try {
        list<VehicleStorageLocation*>::iterator it = search(location->getID());
        if (it == this->locations.end()) {
            this->locations.push_back(location);
        }
        else {
            delete location;
            string msg = "Storage Location";
            throw DuplicatedDataException(msg);
        }
    } catch (DuplicatedDataException &error) {
        cout << error.what() << endl;
    }
}

void VSLContainer::remove(int id) {
    try {
        list<VehicleStorageLocation*>::iterator it = search(id);
        if (it != this->locations.end()) {
            if ((*it)->getVehicleCount() == 0) {
                delete *it;
                this->locations.erase(it);
            }
            else {throw InvalidDataException("Storage Location still has Vehicles. Therefore, ID");}
        }
        else {
            string msg = "Storage Location: " + to_string(id);
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    } catch (InvalidDataException &error) {
        cout << error.what() << endl;
    }
}

void VSLContainer::update(VehicleStorageLocation *location) {
    try {
        list<VehicleStorageLocation*>::iterator it = search(location->getID());
        if (it != this->locations.end()) {
            delete *it;
            this->locations.erase(it);
            this->locations.push_back(location);
        }
        else {
            string msg = "Storage Location: " + to_string(location->getID());
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

const list<VehicleStorageLocation*> &VSLContainer::listVSL() const {
    return locations;
}

VehicleStorageLocation *VSLContainer::get(int id) {
    try{
        list<VehicleStorageLocation*>::iterator it = search(id);
        if (it != this->locations.end()) {
            return *it;
        }
        throw NonExistingDataException("VSL ID");
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    return nullptr;
}