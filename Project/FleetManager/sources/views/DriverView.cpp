//
// Created by ruben on 24/05/2025.
//

#include <iostream>
#include "DriverView.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include "Driver.h"
#include "DriverContainer.h"

using namespace std;

Driver DriverView::addDriver() {
    Driver driver = Utils::setDriver();
    return driver;
}

Driver *DriverView::getDriver(DriverContainer *container) {
    int id = getId();
    Driver *driver = container->get(id);
    return driver;
}

int DriverView::getId() {
    int id = Utils::getInt("Id");
    return id;
}

void DriverView::printDriver(Driver *driver) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Driver " << driver->getId() << " ***\n";
            cout << "License: " << driver->getLicense() << endl;
            cout << "Age: " << driver->getAge() << endl;
            cout << "Time to Retire: " << driver->getTimeToRetire() << endl;
            if (driver->getAvailability()) {
                cout << "Availability: available\n";
            }
            else {cout << "Availability: not available\n";}
            cout << "Vacation (ID): " << driver->getVacationId() << endl;
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void DriverView::printDrivers(list<Driver> &drivers) {
    list<Driver>::iterator it = drivers.begin();
    for (; it != drivers.end(); ++it) {
        printDriver(&*it);
    }
}

void DriverView::vacationAlert(Driver &driver) {
    cout << "!!! ATTENTION !!!\n";
    cout << "The driver " << driver.getId() << "is on vacation!\n";
}

void DriverView::retirementAlert(Driver &driver) {
    cout << "!!! ATTENTION !!!\n";
    cout << "The driver " << driver.getId() << "passed retirement age!\n";
}