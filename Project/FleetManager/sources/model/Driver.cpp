//
// Created by ruben on 19/05/2025.
//

#include "Driver.h"
#include "Utils.h"
#include "DriverContainer.h"
#include "DriverView.h"

Driver::driver() : id(), available(true) {}

Driver::driver(const int &id, const string &license, const int &age, const bool available) {
    this->id = id;
    this->license = license;
    this->age= age;
    this->available = available;
}

Driver::~Driver() {}