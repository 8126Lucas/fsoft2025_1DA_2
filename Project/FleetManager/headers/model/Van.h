//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VAN_H
#define HEADERS_MODEL_VAN_H
#include <string>
#include "Vehicle.h"

using namespace std;

class Van : public Vehicle {
  private:
    double spaceCapacity;

  public:
    Van(string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double spaceCapacity);

    Van(string brand, string model, int year, string licensePlate,
          double mileage, double fuel, double spaceCapacity, Insurance insurance,
          Inspection inspection, VehicleStorageLocation vsl);

    ~Van();

    bool canCarryLoad();
};
#endif //HEADERS_MODEL_VAN_H