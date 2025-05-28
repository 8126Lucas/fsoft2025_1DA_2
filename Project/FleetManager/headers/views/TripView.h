//
// Created by Vitor on 25/05/2025.
//

#ifndef HEADERS_VIEW_TRIPVIEW_H
#define HEADERS_VIEW_TRIPVIEW_H
#include <list>

#include "DriverContainer.h"
#include "OrderContainer.h"
#include "Trip.h"
#include "VehicleContainer.h"


class TripView {
public:
    Trip addTrip(OrderContainer &containerOrder);
    Trip removeTrip();
    void startTrip(Trip *trip, DriverContainer &containerDriver, VehicleContainer &containerVehicle);
    void endTrip(Trip *trip, DriverContainer &containerDriver, VehicleContainer &containerVehicle);
    void failTrip(Trip *trip);
    // static void listTripsByDriver(Trip *trip); Acho que para já não vai ser necessario
    void printTrip(Trip *trip);
    void printListTrips(list<Trip> &trips);
    int getId();
    Trip getTrip(TripContainer *container);

};

#endif //HEADERS_VIEW_TRIPVIEW_H
