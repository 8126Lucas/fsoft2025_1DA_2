#ifndef HEADERS_MODEL_TRIP_H
#define HEADERS_MODEL_TRIP_H

#include "Vehicle.h"


enum STATE{
  DELIVERED = 3,
  INCOMING = 2,
  SUPRESSED = 1,
  FAILED = 0,
};

class Trip
{
private:
  STATE state;
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
  Trip(STATE state=SUPRESSED, int order, double kilometers, double fuel, double fuelCost,double fines, double cost,
       double tolls);
  ~Trip();

  Trip trip(Trip &trip);
  void startTrip(Trip &trip);

  double calculateCost();
  double addFuelCost();
  double addToll();
  double addFines();

  void completeTrip(Trip &trip);

  void listTripsByDriver();
  void listUncompletedTrips();
  void listCompletedTrips();

  int getID();
  void setState(STATE state);
  STATE getState();

  bool operator==(const int int) const;
};


#endif //HEADERS_MODEL_TRIP_H