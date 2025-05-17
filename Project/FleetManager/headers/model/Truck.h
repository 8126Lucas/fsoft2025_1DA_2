//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_TRUCK_H
#define HEADERS_MODEL_TRUCK_H
#include <string>
#include "Vehicle.h"

using namespace std;

class Truck : public Vehicle {
  private:
    double weightCapacity;

  public:
    Truck(string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double weightCapacity);

    Truck(string brand, string model, int year, string licensePlate,
          double mileage, double fuel, double weightCapacity, Insurance insurance,
          Inspection inspection, VehicleStorageLocation vsl);

    ~Truck();

    bool canCarryLoad();
};
#endif //HEADERS_MODEL_TRUCK_H
