//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DRIVER_H
#define HEADERS_MODEL_DRIVER_H

#include <string>
#include <vector>
#include "Vacation.h"

using namespace std;

enum class Status {
    Available = 1,
    OnVacation = 2,
    Retired = 3,
};

class Driver {
private:
    int id;
    string license;
    int age;
    int timeToRetire;
    bool available;
    bool vacationStatus;
    Status driverStatus;

public:
    Driver();

    Driver(int id, string license, int age, bool available = true, bool vacationStatus = false);

    ~Driver();

    void addDriver();
    void removeDriver();

    int  getId() const;
    bool getAvailability() const;

    void setVacation(Vacation vacation);

    int calculateTimeToRetire();
    void vacationAlert();
    bool isAvailable() const;

    bool operator == (int id) const;
};

#endif //HEADERS_MODEL_DRIVER_H