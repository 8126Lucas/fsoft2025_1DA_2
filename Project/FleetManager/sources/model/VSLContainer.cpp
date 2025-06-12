//
// Created by lucas on 18/05/2025.
//

#include "VSLContainer.h"



#include "DuplicatedDataException.h"
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
    list<VehicleStorageLocation*>::iterator it = search(location->getID());
    if (it == this->locations.end()) {
        this->locations.push_back(location);
    }
    else {
        delete location;
        string msg = "Storage Location: " + to_string(location->getID());
        throw DuplicatedDataException(msg);
    }
}

void VSLContainer::remove(int id) {
    list<VehicleStorageLocation*>::iterator it = search(id);
    if (it != this->locations.end()) {
        delete *it;
        this->locations.erase(it);
    }
    else {
        string msg = "Storage Location: " + to_string(id);
        throw NonExistingDataException(msg);
    }
}

void VSLContainer::update(VehicleStorageLocation *location) {
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