//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_VIEWS_VEHICLEVIEW_H
#define HEADERS_VIEWS_VEHICLEVIEW_H
#include <list>

#include "Truck.h"
#include "Van.h"
#include "Vehicle.h"
#include "VehicleContainer.h"

class VehicleView {
public:
    Truck addTruck();
    Van addVan();
    string removeVehicle();

    static Vehicle *getVehicle(VehicleContainer *container);
    static Truck *getTruck(VehicleContainer *container);
    static Van *getVan(VehicleContainer *container);
    static string getLicensePlate();

    static void printTruck(const Truck *truck);
    static void printVan(const Van *van);
    static void printListTrucks(list<Truck> &trucks);
    static void printListVans(list<Van> &vans);

    static double addFuel();
    static void insuranceAlert(Truck &truck);
    static void insuranceAlert(Van &van);
    static void inspectionAlert(Truck &truck);
    static void inspectionAlert(Van &van);
    static void fuelAlert(Truck &truck);
    static void fuelAlert(Van &van);

    ostream &operator<<(ostream &stream, const Date &date);
};

#endif //HEADERS_VIEWS_VEHICLEVIEW_H
