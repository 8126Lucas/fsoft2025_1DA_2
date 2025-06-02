//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VAN_H
#define HEADERS_MODEL_VAN_H

#include "Vehicle.h"
#include "Order.h"
#include <string>

using namespace std;

class Van : public Vehicle {
  private:
    double spaceCapacity;

  public:
    Van();

    Van(CATEGORY category, string brand, string model, int year, string licensePlate,
         double mileage, double fuel, double spaceCapacity, bool available);

    ~Van();

    bool canCarryLoad(Order &order);

    double getSpaceCapacity() const;

    void setSpaceCapacity(double spaceCapacity);


};
#endif //HEADERS_MODEL_VAN_H