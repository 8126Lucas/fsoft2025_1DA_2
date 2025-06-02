//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_INSURANCE_H
#define HEADERS_MODEL_INSURANCE_H
#include "Date.h"

using namespace std;

class Vehicle;

class Insurance {
  private:
    int id;
    Vehicle *vehicle;
    Date startDate;
    Date endDate;
    double monthlyCost;
    Date today;

  public:
    Insurance();
    Insurance(int id, Vehicle *vehicle, Date &startDate, Date &endDate, double monthlyCost);

    ~Insurance();

    int getID() const;
    Vehicle *getVehicle() const;
    Date getEndDate() const;
    double getMonthlyCost() const;

    void setID(int id);
    void setVehicle(Vehicle *vehicle);
    void setStartDate(Date &startDate);
    void setEndDate(Date endDate);
    void setMonthlyCost(double monthlyCost);
    void setToday();

    bool isExpired();
    int getRemainingDays();
    void updateToday();
};


#endif //HEADERS_MODEL_INSURANCE_H
