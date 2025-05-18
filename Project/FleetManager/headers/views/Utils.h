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
    static Vehicle setVehicle(const string &label);
    static VehicleStorageLocation setVSL(const string &label);
    static Driver setDriver(const string &label);
    static Order setOrder(const string &label);
    static Insurance setInsurance(const string &label);
    static Inspection setInspection(const string &label);
};

#endif //HEADERS_VIEWS_UTILS_H
