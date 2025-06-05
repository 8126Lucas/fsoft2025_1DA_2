//
// Created by lucas on 02/06/2025.
//

#ifndef HEADERS_SERIAL_VEHICLESERIALIZATION_H
#define HEADERS_SERIAL_VEHICLESERIALIZATION_H
#include <nlohmann/json.hpp>
#include "Vehicle.h"
#include "Truck.h"
#include "Van.h"

using namespace nlohmann;

class VehicleSerialization {
public:
    virtual void toJSON(json &j, const CATEGORY &category) = 0;
    virtual void fromJSON(const json &j, CATEGORY &category) = 0;
    virtual void toJSON(json &j, const Vehicle &vehicle) = 0;
    virtual void fromJSON(const json &j, Vehicle &vehicle) = 0;
    virtual void toJSON(json &j, const Truck &truck) = 0;
    virtual void fromJSON(const json &j, Truck &truck) = 0;
    virtual void toJSON(json &j, const Van &van) = 0;
    virtual void fromJSON(const json &j, Van &van) = 0;
};

#endif //HEADERS_SERIAL_VEHICLESERIALIZATION_H
