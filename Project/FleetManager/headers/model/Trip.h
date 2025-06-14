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

class Trip {
private:
  STATE state;
  int id;
  Order *order;
  Driver *driver{};
  Vehicle *vehicle{};
  double kilometers{};
  double fuel{};
  double fuelCost{};
  double fines{};
  double cost;
  double tolls{};


public:
  Trip();

  Trip(STATE state, int id, Order *order, double cost);

  Trip(STATE state, int id, Order *order, Driver *driver, Vehicle *vehicle, double kilometers, double fuel, double fuelCost, double fines, double cost, double tolls);

  Trip(Order *order, double kilometers, double fuel, double fuelCost,double fines, double cost,
       double tolls);
  Trip(int id, Date date,Order order, Driver driver, Vehicle vehicle);

  ~Trip();


  STATE getState() const;
  int getID() const;
  Order *getOrder() const;
  Driver *getDriver() const;
  Vehicle *getVehicle() const;
  double getCost() const;
  double getFuelCost() const;
  double getTolls() const;
  double getFines() const;
  double getKM() const;
  double getFuel() const;

  void setState(STATE newState);
  void setID(int id);
  void setOrder(Order *order);
  void setDriver(Driver *driver);
  void setVehicle(Vehicle *vehicle);
  void setKM(double kilometers);
  void setFuel(double fuel);
  void setFuelCost(double fuelCost);
  void setFines(double fines);
  void setCost(double cost);
  void setTolls(double tolls);



  bool operator==(const int id) const;
};


#endif //HEADERS_MODEL_TRIP_H