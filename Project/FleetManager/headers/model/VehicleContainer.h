//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLECONTAINER_H
#define HEADERS_MODEL_VEHICLECONTAINER_H

#include <list>
#include "Vehicle.h"

using namespace std;

class VehicleContainer {
private:
    list<Vehicle> vehicles;
    list<Vehicle>::iterator search(string &licensePlate);

public:
    Vehicle *get(string &licensePlate);
    void add(Vehicle &vehicle);
    void remove(string &licensePlate);
    list<Vehicle> list();
};

#endif //HEADERS_MODEL_VEHICLECONTAINER_H
