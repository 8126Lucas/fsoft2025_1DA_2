//
// Created by lucas on 15/05/2025.
//

#ifndef HEADERS_VIEWS_UTILS_H
#define HEADERS_VIEWS_UTILS_H
#include <string>

using namespace std;

class Utils {
  public:
    static int getInt(const string &label);
    static double getDouble(const string &label);
    static string getString(const string &label);
    static Vehicle getVehicle(const string &label);
    static VehicleStorageLocation getVSL(const string &label);
    static Driver getDriver(const string &label);
    static Order getOrder(const string &label);
    static Insurance getInsurance(const string &label);
    static Inspection getInspection(const string &label);
};

#endif //HEADERS_VIEWS_UTILS_H
