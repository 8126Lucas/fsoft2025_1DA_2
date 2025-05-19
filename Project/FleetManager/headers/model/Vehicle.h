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
    bool available;
    Insurance insurance;
    Inspection inspection;
    VehicleStorageLocation vsl;

  public:

    Vehicle();

    Vehicle(const CATEGORY category, const string &brand, const string &model, const int year, const string &licensePlate,
            const double mileage, const double fuel, const bool available = true);

    ~Vehicle();

    void addVehicle();
    void removeVehicle();

    string &getLicensePlate();
    bool getAvailability() const;
    void setInsurance(Insurance insurance);
    void setInspection(Inspection inspection);
    void setVSL(const VehicleStorageLocation vsl);

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
