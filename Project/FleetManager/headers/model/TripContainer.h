//
// Created by vitor on 5/20/25.
//

#ifndef TRIPCONTAINER_H
#define TRIPCONTAINER_H
#include "Trip.h"
#include <list>

class TripContainer {
private:
    list<Trip> trips;
    list<Trip>::iterator search(int id);

public:
    void add(Trip &trip);
    void start(Trip &trip);
    void complete(Trip &trip);
    list<Trip> list();
    list<Trip> list(Driver &driver);
    list<Trip> list(STATUS status);

}


#endif //TRIPCONTAINER_H
