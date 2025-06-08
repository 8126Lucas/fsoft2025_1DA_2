//
// Created by dinis on 6/7/25.
//

#ifndef HEADERS_SERIAL_ORDERSERIALIZATION_H
#define HEADERS_SERIAL_ORDERSERIALIZATION_H
#include "Date.h"
#include "nlohmann/json.hpp"
#include "Order.h"

using namespace nlohmann;

class OrderSerialization {
public:
  void toJSON(json &j, const Order &order);
  void fromJSON(const json &j, Order &order);
  void toJSON(json &j, const STATUS &status);
  STATUS fromJSON(const json &j);
};

#endif //HEADERS_SERIAL_ORDERSERIALIZATION_H
