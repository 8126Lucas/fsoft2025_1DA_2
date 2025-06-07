//
// Created by ruben on 06/06/2025.
//

#ifndef HEADERS_SERIAL_DRIVERSERIALIZATION_H
#define HEADERS_SERIAL_DRIVERSERIALIZATION_H
#include <nlohmann/json.hpp>
#include "Driver.h"

using namespace nlohmann;

class DriverSerialization {
public:
    void toJSON(json &j, const Driver &driver);
    void fromJSON(const json &j, Driver &driver);
};

#endif //HEADERS_SERIAL_DRIVERSERIALIZATION_H