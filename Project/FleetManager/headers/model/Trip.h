#ifndef HEADERS_MODEL_TRIP_H
#define HEADERS_MODEL_TRIP_H

#include "Date.h"
#include "Order.h"
#include "Driver.h"
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
  STATE state = SUPRESSED;
  Order order;
  Driver driver;
  Vehicle *vehicle;
  double kilometers;
  double fuel;
  double fuelCost;
  double fines;
  double cost;
  double tolls;
  int id;


public:
  Trip();

  Trip(Order order, double kilometers, double fuel, double fuelCost,double fines, double cost,
       double tolls);
  Trip(int id, Date date,Order order, Driver driver, Vehicle vehicle);

  ~Trip();


  // Trip(Trip &trip);

  double calculateCost();
  double getFuelCost();
  double getTolls();
  double getFines();
  double getKM();
  double getFuel();

  void createTrip(Trip &trip);
  void startTrip(Trip &trip);
  void completeTrip(Trip &trip);
  void failedTrip(Trip &trip);
  void listTripsByDriver();
  void listUncompletedTrips();
  void listCompletedTrips();
  void setState(STATE newState);
  void updateState(int id, STATE newState);

  int getID();


  STATE getState();

  Driver getDriver();


  bool operator==(const int id) const;
};


#endif //HEADERS_MODEL_TRIP_H