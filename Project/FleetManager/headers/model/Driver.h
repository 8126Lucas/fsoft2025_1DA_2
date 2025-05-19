//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DRIVER_H
#define HEADERS_MODEL_DRIVER_H

#include <string>
#include <vector>
#include "Vacation.h"

class Driver {
protected:
    int id;
    std::string license;
    int age;
    int timeToRetire;
    bool vacationStatus;

public:
    Driver(int id, std::string license, int age);

    int calculateTimeToRetire();
    bool vacationAlert;

    Vacation addVacation(const Vacation &vacation);

    int getId();
    bool isAvailable();
};

#endif //HEADERS_MODEL_DRIVER_H