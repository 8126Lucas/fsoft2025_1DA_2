//
// Created by lucas on 18/05/2025.
//

#ifndef HEADERS_VIEWS_VEHICLEVIEW_H
#define HEADERS_VIEWS_VEHICLEVIEW_H
#include <list>

#include "Vehicle.h"
#include "Truck.h"
#include "Van.h"
#include "VehicleContainer.h"
#include "Date.h"

using namespace std;

class VehicleView {
public:
    Truck *addTruck();
    Van *addVan();
    string removeVehicle();

    static Vehicle *getVehicle(VehicleContainer *container);
    static Truck *getTruck(VehicleContainer *container);
    static Van *getVan(VehicleContainer *container);
    static string getLicensePlate();

    void printTruck(const Truck *truck);
    void printVan(const Van *van);
    void printListTrucks(list<Truck*> &trucks);
    void printListVans(list<Van*> &vans);

    double addFuel(Vehicle *vehicle);
    static void insuranceAlert(const Truck *truck);
    static void insuranceAlert(const Van *van);
    static void inspectionAlert(const Truck *truck);
    static void inspectionAlert(const Van *van);
    static void fuelAlert(const Truck *truck);
    static void fuelAlert(const Van *van);

};

#endif //HEADERS_VIEWS_VEHICLEVIEW_H
