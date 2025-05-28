//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_CONTROLLERS_CONTROLLER_H
#define HEADERS_CONTROLLERS_CONTROLLER_H
#include "DriverView.h"
#include "Enterprise.h"
#include "FinancialView.h"
#include "InspectionView.h"
#include "InsuranceView.h"
#include "OrderView.h"
#include "TripView.h"
#include "VehicleView.h"
#include "VehicleStorageLocationView.h"
#include "VacationView.h"
#include "View.h"

class Controller {
private:
    Enterprise &model;
    View view;
    DriverView driverView;
    FinancialView financialView;
    InspectionView inspectionView;
    InsuranceView insuranceView;
    OrderView orderView;
    TripView tripView;
    VehicleView vehicleView;
    VehicleStorageLocationView vslView;
    Vacation vacationView;

    void runVehicle();
    void runTrip();
    void runDriver();
    void runFinancial();
    void runOrder();

public:
    Controller(Enterprise &enterprise);
    void run();
};


#endif //HEADERS_CONTROLLERS_CONTROLLER_H
