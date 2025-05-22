//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_INSPECTION_H
#define HEADERS_MODEL_INSPECTION_H
#include "InspectionView.h"
#include "Vehicle.h"

using namespace std;

class Inspection {
  private:
    int id;
    Vehicle vehicle;
    Date date;
    double cost;
    Date today = Date::getToday();

  public:
    Inspection();
    Inspection(int id, Vehicle *vehicle, Date &date, double cost);

    ~Inspection();

    int getID() const;

    Inspection addInspection(InspectionView inspectionView);
    int removeInspection(InspectionView inspectionView);
    bool isDued();
    int getRemainingDays() const;
    void updateToday();
};

#endif //HEADERS_MODEL_INSPECTION_H
