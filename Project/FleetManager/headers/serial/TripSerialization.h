//
// Created by Vitor Teixeira on 06/06/2025.
//

#ifndef HEADERS_SERIAL_TRIPSERIALIZATION_H
#define HEADERS_SERIAL_TRIPSERIALIZATION_H

#include "Trip.h"
#include <nlohmann/json.hpp>


using namespace nlohmann;

class TripSerialization {

  public:
     void toJSON(json &j, const STATE &state);
     void fromJSON(const json &j, STATE &state);
     void toJSON(json &j, const Trip &trip);
     void fromJSON(const json &j, Trip &trip);
};



#endif //HEADERS_SERIAL_TRIPSERIALIZATION_H
