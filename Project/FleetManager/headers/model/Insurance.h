//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_INSURANCE_H
#define HEADERS_MODEL_INSURANCE_H
#include "Date.h"
#include "Vehicle.h"


using namespace std;

class Insurance {
  private:
    int id;
    Vehicle vehicle;
    Date startDate;
    Date endDate;
    double monthlyCost;
    Date today = Date::getToday();

  public:
    Insurance();
    Insurance(int id, Vehicle vehicle, Date startDate, Date endDate, double monthlyCost);

    ~Insurance();

    int getID() const;

    Insurance addInsurance();
    void removeInsurance();
    bool isExpired();
    int getRemainingDays() const;
    void updateToday();
};


#endif //HEADERS_MODEL_INSURANCE_H
