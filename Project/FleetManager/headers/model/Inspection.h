//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_INSPECTION_H
#define HEADERS_MODEL_INSPECTION_H
#include "Date.h"
#include <string>

using namespace std;

class Vehicle;

class Inspection {
  private:
    int id;
    Vehicle *vehicle;
    Date date;
    double cost;
    Date today;

  public:
    Inspection();
    Inspection(int id, Vehicle *vehicle, Date &date, double cost);

    ~Inspection();

    int getID() const;
    Vehicle *getVehicle() const;
    Date getDate() const;
    double getCost() const;
    Date getToday() const;

    void setID(int id);
    void setVehicle(Vehicle *vehicle);
    void setDate(Date date);
    void setCost(double cost);
    void setToday(const Date &date);

    bool isDued();
    int getRemainingDays();
    void updateToday();
};

#endif //HEADERS_MODEL_INSPECTION_H
