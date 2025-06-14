//
// Created by lucas on 05/06/2025.
//

#ifndef HEADERS_SERIAL_VEHICLESTORAGELOCATIONSERIALIZATION_H
#define HEADERS_SERIAL_VEHICLESTORAGELOCATIONSERIALIZATION_H
#include <nlohmann/json.hpp>
#include "VehicleStorageLocation.h"

using namespace nlohmann;

class VehicleStorageLocationSerialization {
public:
    void toJSON(json &j, const VehicleStorageLocation &vsl);
    void fromJSON(const json &j, VehicleStorageLocation &vsl);
};



#endif //HEADERS_SERIAL_VEHICLESTORAGELOCATIONSERIALIZATION_H
