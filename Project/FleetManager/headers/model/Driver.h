//
// Created by vitor on 5/16/25.
//

#ifndef HEADERS_MODEL_DRIVER_H
#define HEADERS_MODEL_DRIVER_H

#include <string>
#include <vector>
//#include "Vacation.h"

using namespace std;

class Driver {
private:
    int id;
    string license;
    int age;
    int timeToRetire;
    bool available;
    bool vacationStatus;

public:
    Driver(int id, string license, int age);

    int calculateTimeToRetire();

    int getId();
    bool isAvailable();

    /*driver.cpp
    int &driver::getId() {
        return id;
    }*/
};

#endif //HEADERS_MODEL_DRIVER_H