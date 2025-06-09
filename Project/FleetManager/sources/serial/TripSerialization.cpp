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

STATE TripSerialization::fromJSON(const json &j){
  string stringState = j["state"].get<string>();
  STATE state;
  if (stringState == "DELIVERED"){state = DELIVERED;}
  else if (stringState == "INCOMING"){state = INCOMING;}
  else if (stringState == "SUPRESSED"){state = SUPRESSED;}
  else if (stringState == "FAILED"){state = FAILED;}
  return state;
}

void TripSerialization::toJSON(json &j, const Trip &trip){
   toJSON(j, trip.getState());
   j["id"] = trip.getID();
   j["orderID"] = trip.getOrder()->getOrderID();
  if (trip.getDriver() != nullptr) {
   j["driverID"] = trip.getDriver()->getID();
  }else {
    j["driverID"] = -1;
  }
  if (trip.getVehicle() != nullptr) {
   j["vehicleLicensePlate"] = trip.getVehicle()->getLicensePlate();
  }else {
    j["vehicleLicensePlate"] = "No Vehicle";
  }
   j["km"] = trip.getKM();
   j["fuelCost"] = trip.getFuelCost();
   j["tolls"] = trip.getTolls();
   j["fines"] = trip.getFines();
   j["fuel"] =  trip.getFuel();
   j["cost"]  = trip.getCost();
}

void TripSerialization::fromJSON(const json &j, Trip &trip, DriverContainer& driverContainer, OrderContainer& orderContainer, VehicleContainer& vehicleContainer){
   trip.setState(fromJSON(j));
   trip.setID(j["id"].get<int>());
   trip.setKM(j["km"].get<double>());
   trip.setFuel(j["fuel"].get<double>());
   trip.setFuelCost(j["fuelCost"].get<double>());
   trip.setTolls(j["tolls"].get<double>());
   trip.setFines(j["fines"].get<double>());
   trip.setCost(j["cost"].get<double>());

   if (j["driverID"] != -1) {
     const int driverID = j["driverID"].get<int>();
     Driver* driver = driverContainer.get(driverID);
     trip.setDriver(driver);
   }else {
     trip.setDriver(nullptr);
   }

   const int orderID = j["orderID"].get<int>();
   Order* order = orderContainer.get(orderID);
   trip.setOrder(order);



  if (j["vehicleLicensePlate"] != -1) {
    string vehicleLicensePlate = j["vehicleLicensePlate"].get<string>();
    Vehicle* vehicle = vehicleContainer.get(vehicleLicensePlate);           
    trip.setVehicle(vehicle);
  }else {
    trip.setVehicle(nullptr);
  }

}
