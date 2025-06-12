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
    list<VehicleStorageLocation*> locations;
    list<VehicleStorageLocation*>::iterator search(int id);

public:
    ~VSLContainer();

    void add(VehicleStorageLocation *location);
    void remove(int id);
    void update(VehicleStorageLocation *location);
    const list<VehicleStorageLocation*> &listVSL() const;

    VehicleStorageLocation *get(int id);
};

#endif //HEADERS_MODEL_VSLCONTAINER_H
