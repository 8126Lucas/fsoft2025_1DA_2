//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_VIEWS_UTILS_H
#define HEADERS_VIEWS_UTILS_H
#include <string>
#include "Vehicle.h"
#include "VehicleStorageLocation.h"
#include "Driver.h"
#include "Trip.h"
#include "Order.h"
#include "Insurance.h"
#include "Inspection.h"

using namespace std;

class Utils {
  public:
    static int getInt(const string &label);
    static double getDouble(const string &label);
    static string getString(const string &label);
    static Date getDate(const string &label);
    static Vehicle *getVehicle(const string &label);
    static Vehicle setVehicle();
    static VehicleStorageLocation setVSL();
    static Driver setDriver();
    static Order setOrder();
    static Insurance setInsurance();
    static Inspection setInspection();
};

#endif //HEADERS_VIEWS_UTILS_H
