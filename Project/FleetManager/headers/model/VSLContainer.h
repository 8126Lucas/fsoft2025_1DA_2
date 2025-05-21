//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_MODEL_VSLCONTAINER_H
#define HEADERS_MODEL_VSLCONTAINER_H
#include <list>
#include <tuple>
#include "VehicleStorageLocation.h"
#include "Vehicle.h"

using namespace std;

class VSLContainer {
private:
    list<VehicleStorageLocation> locations;
    list<tuple<VehicleStorageLocation, Vehicle>> vehicleLocations;
    list<VehicleStorageLocation>::iterator search(int id);

public:
    void add(const VehicleStorageLocation &location);
    void remove(int id);
    list<VehicleStorageLocation> list();

    void addVehicle(tuple<VehicleStorageLocation, Vehicle> vehicleLocations);
};

#endif //HEADERS_MODEL_VSLCONTAINER_H
