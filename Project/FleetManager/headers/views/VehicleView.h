//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_VIEWS_VEHICLEVIEW_H
#define HEADERS_VIEWS_VEHICLEVIEW_H
#include <list>
#include "Vehicle.h"

class VehicleView {
public:
    static Vehicle getVehicle();
    static string getLicensePlate();
    static void printVehicle(Vehicle *vehicle);
    static void printVehicles(list<Vehicle> &vehicles);
};

#endif //HEADERS_VIEWS_VEHICLEVIEW_H
