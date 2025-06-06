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
    void toJSON(json &j, const CATEGORY &category);
    CATEGORY fromJSON(const json &j);
    void toJSON(json &j, const Vehicle &vehicle);
    void fromJSON(const json &j, Vehicle &vehicle);
    void toJSON(json &j, const Truck &truck);
    void fromJSON(const json &j, Truck &truck);
    void toJSON(json &j, const Van &van);
    void fromJSON(const json &j, Van &van);
};

#endif //HEADERS_SERIAL_VEHICLESERIALIZATION_H
