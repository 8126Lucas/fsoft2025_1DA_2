//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLECONTAINER_H
#define HEADERS_MODEL_VEHICLECONTAINER_H

#include "Trip.h"
#include "VehicleStorageLocation.h"
#include <string>
#include "Truck.h"
#include "Van.h"
#include "Inspection.h"
#include "Insurance.h"
#include <list>

using namespace std;

class VehicleContainer {
private:
    list<Truck*> trucks;
    list<Van*> vans;
    list<Truck*>::iterator searchTruck(const string &licensePlate);
    list<Van*>::iterator searchVan(const string &licensePlate);

public:
    ~VehicleContainer();

    bool searchInsurance(int insuranceID);
    bool searchInspection(int inspectionID);

    Vehicle *get(string &licensePlate);
    Truck *getTruck(string &licensePlate);
    Van *getVan(string &licensePlate);

    void add(Truck *truck);
    void add(Van *van);
    void remove(const string &licensePlate);
    const list<Truck*> &listTrucks() const;
    list<Truck*> listTrucks(bool available) const;
    const list<Van*> &listVans() const;
    list<Van*> listVans(bool available) const;
    void update(string &licensePlate, Insurance *insurance);
    void update(string &licensePlate, Inspection *inspection);
    void update(string &licensePlate, VehicleStorageLocation *vsl);
    void updateFuel(string &licensePlate, double addedFuel);
    void updateMileage(string &licensePlate, Trip &trip);
    void updateAvailability(string &licensePlate, bool available);
};

#endif //HEADERS_MODEL_VEHICLECONTAINER_H
