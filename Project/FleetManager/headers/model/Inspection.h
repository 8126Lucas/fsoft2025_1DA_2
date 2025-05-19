//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_INSPECTION_H
#define HEADERS_MODEL_INSPECTION_H
#include "Vehicle.h"

using namespace std;

class Inspection {
  private:
    int id;
    Vehicle vehicle;
    Date date;
    double cost;
    Date today;

  public:
    Inspection();
    Inspection(int id, Vehicle vehicle, Date date, double cost);

    ~Inspection();

    Inspection addInspection();
    void removeInspection();
    bool isExpired();
    int getReaminingDays();
};

#endif //HEADERS_MODEL_INSPECTION_H
