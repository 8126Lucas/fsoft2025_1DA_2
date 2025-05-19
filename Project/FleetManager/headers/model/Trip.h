#ifndef HEADERS_MODEL_TRIP_H
#define HEADERS_MODEL_TRIP_H

#include "Vehicle.h"

enum ESTADO{
  Entregue = 1,
  Progresso = 0,
};

class Trip: {

  private:
    ESTADO estado;
  protected:
    int order;
    double kilometers;
    double fuel;
    double fuelCost;
    double fines;
    double cost;
    double tolls;
    int id;

  public:
    Trip(ESTADO estado, int order, double kilometers, double fuel, double fuelCost,double fines, double cost,
         double tolls);
    ~Trip();

    Trip createTrip();
    void startTrip();

    double calculateCost();
    double addFuelCost();
    double addToll();
    double addFines();

    void completeTrip();

    void listTripsByDriver();
    void listUncompletedTrips();
    void listCompletedTrips();






#endif //HEADERS_MODEL_TRIP_H