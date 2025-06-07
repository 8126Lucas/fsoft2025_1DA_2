//
// Created by Vitor Teixeira on 06/06/2025.
//

#include "Trip.h"
#include "Order.h"
#include "TripSerialization.h"


void TripSerialization::toJSON(json &j, const STATE &state){
  switch (state){
    case DELIVERED:
      j ["state"] = "DELIVERED";
      break;
    case INCOMING:
      j ["state"] = "INCOMING";
      break;
    case SUPRESSED:
      j ["state"] = "SUPRESSED";
      break;
    case FAILED:
      j ["state"] = "FAILED";
      break;
  }
}

void TripSerialization::fromJSON(const json &j, STATE &state){
  string stringState = j["state"].get<string>();
  if (stringState == "DELIVERED"){state = DELIVERED;}
  else if (stringState == "INCOMING"){state = INCOMING;}
  else if (stringState == "SUPRESSED"){state = SUPRESSED;}
  else if (stringState == "FAILED"){state = FAILED;}
}

void TripSerialization::toJSON(json &j, const Trip &trip){
   toJSON(j, trip.getState());
   j["id"] = trip.getID();
   j["orderID"] = trip.getOrder()->getOrderID();
   j["driverID"] = trip.getDriver()->getID();
   j["vehicleLicensePlate"] = trip.getVehicle()->getLicensePlate();
   j["kilometer"] = trip.getKM();
   j["fuelCost"] = trip.getFuelCost();
   j["tolls"] = trip.getTolls();
   j["fines"] = trip.getFines();
   j["fuel"] =  trip.getFuel();
   j["cost"]  = trip.getCost();
}

void TripSerialization::fromJSON(const json &j, Trip &trip, DriverContainer& driverContainer, OrderContainer& orderContainer, VehicleContainer& vehicleContainer){
   trip.setState(j["state"].get<STATE>());
   trip.setID(j["id"].get<int>());
   trip.setKM(j["km"].get<double>());
   trip.setFuel(j["fuel"].get<double>());
   trip.setFuelCost(j["fuelCost"].get<double>());
   trip.setTolls(j["tolls"].get<double>());
   trip.setFines(j["fines"].get<double>());
   trip.setCost(j["cost"].get<double>());

  const int driverID = j["driverID"].get<int>();
   Driver* driver = driverContainer.get(driverID);
  if (driver != nullptr) {
     trip.setDriver(driver);
   }else {
     trip.setDriver(nullptr);
   }

  const int orderID = j["orderID"].get<int>();
   Order* order = orderContainer.get(orderID);
   trip.setOrder(order);

  string vehicleLicensePlate = j["vehicleLicensePlate"].get<string>();
  Vehicle* vehicle = vehicleContainer.get(vehicleLicensePlate);
  if (vehicle != nullptr) {
    trip.setVehicle(vehicle);
  }else {
    trip.setVehicle(nullptr);
  }

}
