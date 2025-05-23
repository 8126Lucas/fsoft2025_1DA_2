//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_VIEWS_VEHICLEVIEW_H
#define HEADERS_VIEWS_VEHICLEVIEW_H
#include <list>
#include "Vehicle.h"
#include "VehicleContainer.h"

class VehicleView {
public:
    static Vehicle addVehicle();
    static Vehicle *getVehicle(VehicleContainer *container);
    static string getLicensePlate();
    static void printVehicle(const Vehicle *vehicle);
    static void printListVehicles(list<Vehicle> &vehicles);

    static double addFuel();
    static void insuranceAlert(Vehicle &vehicle);
    static void inspectionAlert(Vehicle &vehicle);
    static void fuelAlert(Vehicle &vehicle);
};

#endif //HEADERS_VIEWS_VEHICLEVIEW_H
