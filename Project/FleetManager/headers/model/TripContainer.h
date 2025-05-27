//
// Created by vitor on 5/20/25.
//

#ifndef HEADERS_MODEL_TRIPCONTAINER_H
#define HEADERS_MODEL_TRIPCONTAINER_H
#include "Trip.h"
#include "Driver.h"
#include <list>

using namespace std;

class TripContainer {
private:
    list<Trip> trips;
    list<Trip>::iterator search(int id);
public:
    void add(Trip &trip);
    void start(Trip &trip);
    void complete(Trip &trip);
    void failed(Trip &trip);
    void updateState(int id, STATE state);
    Trip *getTrip(int id);
    list<Trip> listTrips();
    list<Trip> listTripsByDriver(Driver &driver);
    list<Trip> listTripsByState(STATE state);

};


#endif //HEADER_MODEL_TRIPCONTAINER_H
