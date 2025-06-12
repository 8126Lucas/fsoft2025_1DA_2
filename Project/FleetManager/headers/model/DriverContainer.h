//
// Created by ruben on 18/05/2025.
//

#ifndef HEADERS_MODEL_DRIVERCONTAINER_H
#define HEADERS_MODEL_DRIVERCONTAINER_H

#include <list>
#include "Driver.h"
#include "Vacation.h"


using namespace std;

class DriverContainer {
private:
    list<Driver> drivers;
    list<Driver>::iterator search(int id);

public:
    Driver *get(int id);
    void add(Driver &driver);
    void remove(int id);
    list<Driver> listDrivers();
    list<Driver> listAvailableDrivers(bool available);
    void addVacation(Vacation *vacation);

    void update(int id, Vacation *vacation);
    void updateAvailability(int id, bool available);
};

#endif //HEADERS_MODEL_DRIVERCONTAINER_H