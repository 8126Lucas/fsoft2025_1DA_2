//
// Created by lucas on 19/05/2025.
//

#ifndef HEADERS_MODEL_ENTERPRISE_H
#define HEADERS_MODEL_ENTERPRISE_H
#include <string>
#include "VehicleContainer.h"
#include "VSLContainer.h"
#include "TripContainer.h"
#include "DriverContainer.h"
#include "FinancialContainer.h"
#include "OrderContainer.h"
#include "DataContainer.h"

using namespace std;

class Enterprise {
private:
    string name;
    VehicleContainer vehicleC;
    VSLContainer vslC;
    TripContainer tripC;
    DriverContainer driverC;
    FinancialContainer financialC;
    OrderContainer orderC;
    DataContainer dataC;

public:
    Enterprise();
    Enterprise(const string &name);
    Enterprise(const Enterprise &enterprise);

    const string &getName() const;
    void setName(const string &name);

    VehicleContainer &getVehicleContainer();
    VSLContainer &getVSLContainer();
    TripContainer &getTripContainer();
    DriverContainer &getDriverContainer();
    FinancialContainer &getFinancialContainer();
    OrderContainer &getOrderContainer();
    DataContainer &getDataContainer();
};

#endif //HEADERS_MODEL_ENTERPRISE_H
