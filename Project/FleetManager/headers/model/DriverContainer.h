//
// Created by ruben on 18/05/2025.
//

#ifndef HEADERS_MODEL_DRIVERCONTAINER_H
#define HEADERS_MODEL_DRIVERCONTAINER_H

#include <list>
#include "Driver.h"

using namespace std;

class DriverContainer {
private:
    list<Driver> drivers;
    list<Driver>::iterator search(int id);

public:
    Driver *get(int id);
    void add(Driver &driver);
    void remove(int id);
    list<Driver> list();
    list<Driver> list(bool available);
    void update(int id, Vacation vacation);
    void updateTimeToRetire(int id);

    void updateAvailability(int id, bool available);
};

#endif //HEADERS_MODEL_DRIVERCONTAINER_H