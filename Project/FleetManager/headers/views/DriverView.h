//
// Created by ruben on 19/05/2025.
//

#ifndef HEADERS_VIEWS_DRIVERVIEW_H
#define HEADERS_VIEWS_DRIVERVIEW_H
#include <list>
#include "Driver.h"
#include "DriverContainer.h"

class DriverView {
public:
    static Driver addDriver();
    static int removeDriver();
    static Driver *getDriver(DriverContainer *container);
    static int getID();
    static void printDriver(Driver *driver);
    static void printDrivers(list<Driver> &drivers);

    static void vacationAlert(Driver &driver);
    static void retirementAlert(Driver &driver);
};

#endif //HEADERS_VIEWS_DRIVERVIEW_H