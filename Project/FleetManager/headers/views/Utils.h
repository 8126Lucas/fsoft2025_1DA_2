//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_VIEWS_UTILS_H
#define HEADERS_VIEWS_UTILS_H

#include <string>
#include "Vehicle.h"
#include "VehicleContainer.h"
#include "VehicleStorageLocation.h"
#include "Driver.h"
#include "Trip.h"
#include "Order.h"
#include "Insurance.h"
#include "Inspection.h"
#include "Expense.h"
#include "Revenue.h"
#include "OrderContainer.h"
#include "DriverContainer.h"
#include "TripContainer.h"

using namespace std;

class Utils {
  public:
    static int getInt(const string &label);
    static double getDouble(const string &label);
    static string getString(const string &label);
    static char getChar(const string &label);
    static Date getDate(const string &label);
    static Vehicle *getVehicle(VehicleContainer &container, const string &label);
    static Order *getOrder(OrderContainer &container, const string &label);
    static Driver *getDriver(DriverContainer &container, const string &label);
    static Trip *getTrip(TripContainer &container, const string &label);
};

#endif //HEADERS_VIEWS_UTILS_H
