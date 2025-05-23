//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DRIVER_H
#define HEADERS_MODEL_DRIVER_H

#include <string>
#include <vector>

#include "Vacation.h"

using namespace std;

class Vacation;

enum STATUS {
    Available = 1,
    OnVacation = 2,
    DayOff = 3,
};

class Driver {
private:
    int id;
    string license;
    int age;
    int timeToRetire;
    bool available;
    bool vacationStatus;
    STATUS driverStatus;
    Vacation vacation;

public:
    Driver();

    Driver(int id, string &license, int age);
    Driver(int id, string license, int age, bool available = true, bool vacationStatus = false);

    ~Driver();

    void addDriver();
    void removeDriver();

    int getId();
    string getLicense() const;
    int getAge() const;
    STATUS getDriverStatus() const;
    bool getAvailability() const;
    bool getVacationStatus() const;

    void setVacation(Vacation vacation);
    void setAvailability(bool available);

    void updateTimeToRetire();
    void vacationAlert();
    void retirementAlert();
    bool isAvailable() const;

    bool operator == (int id) const;
};

#endif //HEADERS_MODEL_DRIVER_H