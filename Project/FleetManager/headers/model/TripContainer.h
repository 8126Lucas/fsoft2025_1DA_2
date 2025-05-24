//
// Created by vitor on 5/20/25.
//

#ifndef HEADERS_MODEL_TRIPCONTAINER_H
#define HEADERS_MODEL_TRIPCONTAINER_H
#include "Trip.h"
#include "Driver.h"
#include <list>


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
    list<Trip> list();
    std::list<Trip> list(Driver &driver);
    std::list<Trip> list(STATE state);

};


#endif //HEADER_MODEL_TRIPCONTAINER_H
