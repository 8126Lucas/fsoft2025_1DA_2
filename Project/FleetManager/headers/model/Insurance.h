//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_INSURANCE_H
#define HEADERS_MODEL_INSURANCE_H
#include "Vehicle.h"
#include "date.h"

using namespace std;

class Insurance {
  private:
    int id;
    Vehicle vehicle;
    date startDate; //mudar classe para letra maiúscula
    date endDate; //mudar classe para letra maiúscula
    double monthlyCost;
    // pensar como fazer o atributo "today"

  public:
    Insurance(int id, Vehicle vehicle, date startDate, date endDate, double monthlyCost);

    ~Insurance();

    Insurance addInsurance();
    void removeInsurance();
    bool isExpired();
    int getRemainingDays();
};


#endif //HEADERS_MODEL_INSURANCE_H
