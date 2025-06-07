//
// Created by lucas on 07/06/2025.
//

#ifndef HEADERS_SERIAL_DATACONTAINER_H
#define HEADERS_SERIAL_DATACONTAINER_H
#include <string>
#include <nlohmann/json.hpp>
#include "VehicleContainer.h"
#include "VehicleSerialization.h"
#include "VSLContainer.h"
#include "VehicleStorageLocationSerialization.h"
#include "DriverContainer.h"
#include "DriverSerialization.h"
#include "FinancialContainer.h"
#include "FinancialSerialization.h"
#include "TripContainer.h"
#include "TripSerialization.h"
#include "OrderContainer.h"
#include "OrderSerialization.h"

using namespace std;
using namespace nlohmann;

class DataContainer {
private:
    VehicleContainer *containerVehicle;
    VSLContainer *containerVSL;
    DriverContainer *containerDriver;
    FinancialContainer *containerFinancial;
    TripContainer *containerTrip;
    OrderContainer *containerOrder;

    string vehicleFilePath;
    string vslFilePath;
    string driverFilePath;
    string financialFilePath;
    string tripFilePath;
    string orderFilePath;

public:
    DataContainer(
        VehicleContainer *containerVehicle,
        VSLContainer *containerVSL,
        DriverContainer *containerDriver,
        FinancialContainer *containerFinancial,
        TripContainer *containerTrip,
        OrderContainer *containerOrder,

        string vehicleFilePath = "../../data/vehicle.json",
        string vslFilePath = "../../data/vsl.json",
        string driverFilePath = "../../data/driver.json",
        string financialFilePath = "../../data/financial.json",
        string tripFilePath = "../../data/trip.json",
        string orderFilePath = "../../data/order.json"
        );

    void loadVehicles();
    void loadVSLs();
    void loadDrivers();
    void loadFinancials();
    void loadTrips();
    void loadOrders();

    void loadAllData();
    void saveAllData();
};

#endif //HEADERS_SERIAL_DATACONTAINER_H
