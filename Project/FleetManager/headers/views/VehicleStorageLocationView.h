//
// Created by lucas on 19/05/2025.
//

#ifndef HEADERS_VIEW_VEHICLESTORAGELOCATIONVIEW_H
#define HEADERS_VIEW_VEHICLESTORAGELOCATIONVIEW_H
#include <list>
#include <utility>
#include "VehicleContainer.h"
#include "VehicleStorageLocation.h"
#include "VSLContainer.h"

class VehicleStorageLocationView {
public:
    static VehicleStorageLocation addVSL();
    static int removeVSL();
    static int getID();
    static void printVSL(VehicleStorageLocation *vsl);
    static void printListVSL(list<VehicleStorageLocation> &listVSL);
    static void printListStoredVehicles(const VehicleStorageLocation &vsl);
    static VehicleStorageLocation *getVSL(VSLContainer *container);
    static pair<int, Vehicle *> getVehicleVSLPair(VSLContainer *containerVSL, VehicleContainer *containerVehicle);

    static void addVehicleToStorage(VSLContainer *containerVSL, VehicleContainer *containerVehicle);
    static void removeVehicleFromStorage(VSLContainer *containerVSL, VehicleContainer *containerVehicle)
};
#endif //HEADERS_VIEW_VEHICLESTORAGELOCATIONVIEW_H
