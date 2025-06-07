//
// Created by Vitor Teixeira on 06/06/2025.
//

#ifndef HEADERS_SERIAL_TRIPSERIALIZATION_H
#define HEADERS_SERIAL_TRIPSERIALIZATION_H

#include "Trip.h"
#include "DriverContainer.h"
#include "OrderContainer.h"
#include "VehicleContainer.h"
#include <nlohmann/json.hpp>


using namespace nlohmann;

class TripSerialization {

  public:
     void toJSON(json &j, const STATE &state);
     void fromJSON(const json &j, STATE &state);
     void toJSON(json &j, const Trip &trip);
     void fromJSON(const json &j, Trip &trip);
     static void fromJSON(const json&, Trip& trip, DriverContainer& driverContainer, OrderContainer& orderContainer, VehicleContainer& vehicleContainer);
};



#endif //HEADERS_SERIAL_TRIPSERIALIZATION_H
