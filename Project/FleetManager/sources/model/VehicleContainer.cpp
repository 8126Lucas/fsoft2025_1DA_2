//
// Created by lucas on 18/05/2025.
//

#include "VehicleContainer.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"


list<Truck*>::iterator VehicleContainer::searchTruck(const string &licensePlate) {
    list<Truck*>::iterator it = this->trucks.begin();
    for (; it != this->trucks.end(); ++it) {
        if ((*it)->getLicensePlate() == licensePlate) {
            return it;
        }
    }
    return trucks.end();
}

list<Van*>::iterator VehicleContainer::searchVan(const string &licensePlate) {
    list<Van*>::iterator it = this->vans.begin();
    for (; it != this->vans.end(); ++it) {
        if ((*it)->getLicensePlate() == licensePlate) {
            return it;
        }
    }
    return vans.end();
}

bool VehicleContainer::searchInspection(int inspectionID) {
    for (const Truck *truck : trucks) {
        if (truck->getInspection() && truck->getInspectionID() == inspectionID) {
            return true;
        }
    }
    for (const Van *van : vans) {
        if (van->getInspection() && van->getInspectionID() == inspectionID) {
            return true;
        }
    }
    return false;
}

bool VehicleContainer::searchInsurance(int insuranceID) {
    for (const Truck *truck : trucks) {
        if (truck->getInsurance() && truck->getInsuranceID() == insuranceID) {
            return true;
        }
    }
    for (const Van *van : vans) {
        if (van->getInsurance() && van->getInsuranceID() == insuranceID) {
            return true;
        }
    }
    return false;
}

VehicleContainer::~VehicleContainer() {
    for (Truck *truck : trucks) {
        delete truck;
    }
    trucks.clear();
    for (Van *van : vans) {
        delete van;
    }
    vans.clear();
}

Vehicle *VehicleContainer::get(string &licensePlate){
    try {
        Truck *truck = getTruck(licensePlate);
        Van *van = getVan(licensePlate);
        if (truck == nullptr && van != nullptr) {return van;}
        if (truck != nullptr && van == nullptr) {return truck;}
        throw NonExistingDataException("Vehicle's License Plate");
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    return nullptr;
}

Truck *VehicleContainer::getTruck(string &licensePlate) {
    list<Truck*>::iterator it = searchTruck(licensePlate);
    if (it != this->trucks.end()) {
        return *it;
    }
    return nullptr;
}

Van *VehicleContainer::getVan(string &licensePlate) {
    list<Van*>::iterator it = searchVan(licensePlate);
    if (it != this->vans.end()) {
        return *it;
    }
    return nullptr;
}


void VehicleContainer::add(Truck *truck) {
    try {
        list<Truck*>::iterator it = searchTruck(truck->getLicensePlate());
        if (it == this->trucks.end()) {
            this->trucks.push_back(truck);
        }
        else {
            string msg = "Vehicle (Truck): " + truck->getLicensePlate();
            throw DuplicatedDataException(msg);
        }
    } catch (DuplicatedDataException &error) {
        cout << error.what() << endl;
    }
}

void VehicleContainer::add(Van *van) {
    try {
        list<Van*>::iterator it = searchVan(van->getLicensePlate());
        if (it == this->vans.end()) {
            this->vans.push_back(van);
        }
        else {
            string msg = "Vehicle (Van): " + van->getLicensePlate();
            throw DuplicatedDataException(msg);
        }
    } catch (DuplicatedDataException &error) {
        cout << error.what() << endl;
    }
}

void VehicleContainer::remove(const string &licensePlate) {
    try {
        const list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        const list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            if ((*truckIT)->getVSL() != nullptr) {throw InvalidDataException("Truck is still in a Storage Location. Therefore, License Plate");}
            if ((*truckIT)->getInsurance() != nullptr) {throw InvalidDataException("Truck still has Insurance. Therefore, License Plate");}
            if ((*truckIT)->getInspection() != nullptr) {throw InvalidDataException("Truck still has Inspection. Therefore, License Plate");}
            this->trucks.erase(truckIT);
        }
        else if (vanIT != this->vans.end()) {
            if ((*vanIT)->getVSL() != nullptr) {throw InvalidDataException("Van is still in a Storage Location. Therefore, License Plate");}
            if ((*vanIT)->getInsurance() != nullptr) {throw InvalidDataException("Van still has Insurance. Therefore, License Plate");}
            if ((*vanIT)->getInspection() != nullptr) {throw InvalidDataException("Van still has Inspection. Therefore, License Plate");}
            this->vans.erase(vanIT);
        }
        else {
            throw(NonExistingDataException("Vehicle " + licensePlate));
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    } catch (InvalidDataException &error) {
        cout << error.what() << endl;
    }
}

const list<Truck*> &VehicleContainer::listTrucks() const {
    return this->trucks;
}

list<Truck*> VehicleContainer::listTrucks(const bool available) const {
    list<Truck*> newList;
    for (Truck *truck : this->trucks) {
        if (truck->getAvailability() == available) {
            newList.push_back(truck);
        }
    }
    return newList;
}

const list<Van*> &VehicleContainer::listVans() const {
    return this->vans;
}

list<Van*> VehicleContainer::listVans(bool available) const {
    list<Van*> newList;
    for (Van *van : this->vans) {
        if (van->getAvailability() == available) {
            newList.push_back(van);
        }
    }
    return newList;
}

void VehicleContainer::update(string &licensePlate, Insurance *insurance) {
    try {
        list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            (*truckIT)->setInsurance(insurance);
        }
        else if (vanIT != this->vans.end()) {
            (*vanIT)->setInsurance(insurance);
        }
        else {
            string msg = "Vehicle (insurance): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

void VehicleContainer::update(string &licensePlate, Inspection *inspection) {
    try {
        list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            (*truckIT)->setInspection(inspection);
        }
        else if (vanIT != this->vans.end()) {
            (*vanIT)->setInspection(inspection);
        }
        else {
            string msg = "Vehicle (inspection): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

void VehicleContainer::update(string &licensePlate, VehicleStorageLocation *vsl) {
    try {
        list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            (*truckIT)->setVSL(vsl);
        }
        else if (vanIT != this->vans.end()) {
            (*vanIT)->setVSL(vsl);
        }
        else {
            string msg = "Vehicle (VSL): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }

}

void VehicleContainer::updateFuel(string &licensePlate, double addedFuel) {
    try {
        list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            (*truckIT)->addFuel(addedFuel);
        }
        else if (vanIT != this->vans.end()) {
            (*vanIT)->addFuel(addedFuel);
        }
        else {
            string msg = "Vehicle (fuel): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

void VehicleContainer::updateMileage(string &licensePlate, Trip &trip) {
    try {
        list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            (*truckIT)->updateMileage(trip);
        }
        else if (vanIT != this->vans.end()) {
            (*vanIT)->updateMileage(trip);
        }
        else {
            string msg = "Vehicle (mileage): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

void VehicleContainer::updateAvailability(string &licensePlate, bool available) {
    try {
        list<Truck*>::iterator truckIT = searchTruck(licensePlate);
        list<Van*>::iterator vanIT = searchVan(licensePlate);
        if (truckIT != this->trucks.end()) {
            (*truckIT)->setAvailability(available);
        }
        else if (vanIT != this->vans.end()) {
            (*vanIT)->setAvailability(available);
        }
        else {
            string msg = "Vehicle (availability): " + licensePlate;
            throw NonExistingDataException(msg);
        }
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}