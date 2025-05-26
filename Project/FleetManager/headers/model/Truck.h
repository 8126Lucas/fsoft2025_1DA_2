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
    Truck();

    Truck(CATEGORY category, string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double weightCapacity, bool available);

    ~Truck();

    bool canCarryLoad(Order &order);

    void setWeightCapacity(double weightCapacity);
};
#endif //HEADERS_MODEL_TRUCK_H
