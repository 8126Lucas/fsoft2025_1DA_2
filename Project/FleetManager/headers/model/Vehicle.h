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
  private:
    CATEGORY category;
  protected:
    string brand;
    string model;
    int year;
    string licensePlate;
    double mileage;
    double fuel;
    Insurance insurance;
    Inspection inspection;
    VehicleStorageLocation vsl;

  public:
    Vehicle(CATEGORY category, string brand, string model, int year, string licensePlate,
            double mileage, double fuel);

    Vehicle(CATEGORY category, string brand, string model, int year, string licensePlate,
            double mileage, double fuel, Insurance insurance, Inspection inspection,
            VehicleStorageLocation vsl);

    ~Vehicle();

    Vehicle addVehicle();
    void removeVehicle();
    void listVehicles();
    void listAvailableVehilces();

    void addFuel();
    bool isFuelEnough();
    void updateMileage();
    void insuranceAlert();
    void inspectionAlert();
    void fuelAlert();
    bool isAvailable();
};

#endif //HEADERS_MODEL_VEHICLE_H
