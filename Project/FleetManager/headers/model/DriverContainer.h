//
// Created by ruben on 18/05/2025.
//

#ifndef DRIVERCONTAINER_H
#define DRIVERCONTAINER_H

#include <vector>
#include "Driver.h"

class DriverContainer {
private:
    //vetor para armazenar todos os condutores cadastrados no sistema
    std::vector<Driver> drivers;

public:
    void add(Driver &driver);
    void remove(int driverId);
    void list();
    //Provisório
    void listAvailableDrivers() const;
};

#endif //DRIVERCONTAINER_H