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

            int id;
            bool flag_error_id = false;
            do {
                try {
                    flag_error_id = false;
                    id = Utils::getInt("ID");
                    if (id <= 0) {
                        throw InvalidDataException("Driver (id): " + to_string(id));
                    }
                } catch (const InvalidDataException &error) {
                    flag_error_id = true;
                    cout << error.what() << endl;
                }
            } while (flag_error_id);

            char license;
            bool flag_error2 = false;
            do {
                try {
                    flag_error2 = false;
                    license = Utils::getChar("License");
                    if (license != 'B' && license != 'C') {
                        throw InvalidDataException(string(1, license));
                    }
                } catch (const InvalidDataException &error) {
                    flag_error2 = true;
                    cout << error.what() << endl;
                }
            } while (flag_error2);

            int age = Utils::getInt("Age");

            driver.setID(id);
            driver.setLicense(license);
            driver.setAge(age);
            driver.setTimeToRetire(age);
            driver.setAvailability(true);

        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
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
            } else {
                cout << "Availability: not available\n";
            }
            Vacation* vacation = driver->getVacation();
            if (vacation != nullptr) {
                cout << "Vacation (ID): " << driver->getVacationID() << endl;
            } else {
                cout << "Vacation: No vacation active\n";
            }
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}

void DriverView::printDrivers(list<Driver> &drivers) {
    if (drivers.empty()) {
        cout << "\nTHERE ARE NO DRIVERS IN THE RECORDS!\n";
        return;
    }
    list<Driver>::iterator it = drivers.begin();
    for (; it != drivers.end(); ++it) {
        printDriver(&*it);
    }
}

void DriverView::printAvailableDrivers(list<Driver> &drivers) {
    if (drivers.empty()) {
        cout << "\nTHERE ARE NO AVAILABLE DRIVERS IN THE RECORDS!\n";
        return;
    }
    list<Driver>::iterator it = drivers.begin();
    for (; it != drivers.end(); ++it) {
        printDriver(&*it);
    }
}

void DriverView::printUnavailableDrivers(list<Driver> &drivers) {
    if (drivers.empty()) {
        cout << "\nTHERE ARE NO UNAVAILABLE DRIVERS IN THE RECORDS!\n";
        return;
    }
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