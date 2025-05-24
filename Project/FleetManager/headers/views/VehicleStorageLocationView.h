//
// Created by lucas on 19/05/2025.
//

#ifndef HEADERS_VIEW_VEHICLESTORAGELOCATIONVIEW_H
#define HEADERS_VIEW_VEHICLESTORAGELOCATIONVIEW_H
#include <list>
#include <utility>
#include "VehicleContainer.h"
#include "VehicleStorageLocation.h"

class VehicleStorageLocationView {
public:
    static VehicleStorageLocation getVSL();
    static int getID();
    static void printVSL(VehicleStorageLocation *vsl);
    static void printListVSL(list<VehicleStorageLocation> &listVSL);
    static void printListStoredVehicles(VehicleStorageLocation vsl);
    static pair<int, Vehicle *> addVehicle(VehicleContainer *container);
};
#endif //HEADERS_VIEW_VEHICLESTORAGELOCATIONVIEW_H
