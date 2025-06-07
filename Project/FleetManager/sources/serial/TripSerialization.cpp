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

void TripSerialization::fromJSON(const json &j, Trip &trip){
   trip.setState(j["state"].get<STATE>());
   trip.setID(j["id"].get<int>());
   int orderID = j["orderID"].get<int>(); // duvida nesta parte
   trip.setDriver(j["driverID"].get<*Driver>(  ));

}