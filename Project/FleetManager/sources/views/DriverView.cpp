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
    Driver driver = Driver();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("ID");
            char license = Utils::getChar("License");
            int age = Utils::getInt("Age");

            driver.setID(id);
            driver.setLicense(license);
            driver.setAge(age);
            driver.setTimeToRetire(age);
            driver.setVacation(nullptr);
            driver.setAvailability(true);

        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
    return driver;
}

int DriverView::removeDriver() {
    int id = Utils::getInt("Driver ID");
    return id;
}

Driver *DriverView::getDriver(DriverContainer *container) {
    int id = getID();
    Driver *driver = container->get(id);
    return driver;
}

int DriverView::getID() {
    int id = Utils::getInt("ID");
    return id;
}

void DriverView::printDriver(Driver *driver) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Driver " << driver->getID() << " ***\n";
            cout << "License: " << driver->getLicense() << endl;
            cout << "Age: " << driver->getAge() << endl;
            cout << "Time to Retire: " << driver->getTimeToRetire() << endl;
            if (driver->getAvailability()) {
                cout << "Availability: available\n";
            }
            else {cout << "Availability: not available\n";}
            if (driver->getVacation() != nullptr) {
                cout << "Vacation (ID): " << driver->getVacationID() << endl;
            } else {
                cout << "Vacation: No vacation active\n";
            }
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
    cout << "The driver " << driver.getID() << "is on vacation!\n";
}

void DriverView::retirementAlert(Driver &driver) {
    cout << "!!! ATTENTION !!!\n";
    cout << "The driver " << driver.getID() << "passed retirement age!\n";
}