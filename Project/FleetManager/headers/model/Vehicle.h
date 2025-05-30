//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLE_H
#define HEADERS_MODEL_VEHICLE_H

#include "VehicleStorageLocation.h"
#include "Insurance.h"
#include <string>

using namespace std;


enum CATEGORY {
  TRUCK = 1,
  VAN = 2,
};

class Inspection;

class Trip;

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
    Insurance *insurance{};
    Inspection *inspection{};
    VehicleStorageLocation *vsl{};

  public:

    Vehicle();

    Vehicle(CATEGORY category, const string &brand, const string &model, int year, const string &licensePlate,
            double mileage, double fuel, bool available = true);

    virtual ~Vehicle();

    CATEGORY getCategory() const;
    string getBrand() const;
    string getModel() const;
    int getYear() const;

    string getLicensePlate() const;
    double getMileage() const;
    double getFuel() const;
    bool getAvailability() const;
    int getInsuranceID() const;
    int getInspectionID() const;
    int getVSLID() const;

    Inspection *getInspection() const;
    Insurance *getInsurance() const;
    VehicleStorageLocation *getVSL() const;

    void setCategory(CATEGORY category);
    void setBrand(const string &brand);
    void setModel(const string &model);
    void setYear(int year);
    void setLicensePlate(const string &licensePlate);
    void setMileage(double mileage);
    void setFuel(double fuel);
    void setInsurance(Insurance *insurance);
    void setInspection(Inspection *inspection);
    void setVSL(VehicleStorageLocation *vsl);
    void setAvailability(bool availability);

    void addFuel(double addedFuel);
    bool isFuelEnough(Trip &trip);
    void updateMileage(Trip &trip);
    void insuranceAlert();
    void inspectionAlert();
    void fuelAlert(Trip &trip);
    bool isAvailable() const;

    bool operator== (const string &string) const;

};

#endif //HEADERS_MODEL_VEHICLE_H
