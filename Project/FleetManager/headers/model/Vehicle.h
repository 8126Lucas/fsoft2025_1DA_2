//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLE_H
#define HEADERS_MODEL_VEHICLE_H
#include <string>
#include "VehicleStorageLocation.h"
#include "Inspection.h"
#include "Insurance.h"

using namespace std;

enum CATEGORY {
  TRUCK = 1,
  VAN = 2,
};

class Vehicle {
  protected:
    CATEGORY category;
    string brand;
    string model;
    int year;
    string licensePlate;
    double mileage;
    double fuel;

  public:
    bool available;
    Insurance insurance;
    Inspection inspection;
    VehicleStorageLocation vsl;

    Vehicle();

    Vehicle(CATEGORY category, string &brand, string &model, int year, string &licensePlate,
            double mileage, double fuel, bool available = true);

    // Vehicle(CATEGORY category, string brand, string model, int year, string licensePlate,
    //         double mileage, double fuel, bool available = true, Insurance insurance, Inspection inspection,
    //         VehicleStorageLocation vsl);

    ~Vehicle();

    void addVehicle();
    void removeVehicle();
    void listVehicles();
    void listAvailableVehicles();

    string &getLicensePlate();

    void addFuel();
    bool isFuelEnough();
    void updateMileage();
    void insuranceAlert();
    void inspectionAlert();
    void fuelAlert();
    bool isAvailable();

    bool operator == (const string &string) const;

};

#endif //HEADERS_MODEL_VEHICLE_H
