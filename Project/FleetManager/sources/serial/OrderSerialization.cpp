//
// Created by dinis on 6/7/25.
//
#include "OrderSerialization.h"

string OrderSerialization::toJSON(json &j,const STATUS &status){
    switch(status){
      case IN_PROGRESS:
        j["status"] = "IN_PROGRESS";
        break;
      case COMPLETED:
        j["status"] = "COMPLETED";
        break;
    }
}

STATUS OrderSerialization::fromJSON(const json &j){
  string Orderstring = j["status"].get<string>();
  STATUS status;
  if(Orderstring == "IN_PROGRESS") {status = IN_PROGRESS;}
  else {status = COMPLETED;}
  return status;
}

void OrderSerialization::toJSON(json &j,const Order &order){
  toJSON(j,order.getStatus());
  j["id"] = order.getOrderID();
  j["client"] = order.getClientID();
  j["sourceAddress"] = order.getSourceAddress();
  j["destinationAddress"] = order.getDestinationAddress();
  j["cargoSpace"] = order.getCargoSpace();
  j["cargoWeight"] = order.getCargoWeight();
  j["shippingValue"] = order.getShippingValue();
  string string_date = order.getDate().dateToString();
  j["date"] = string_date;
}
void OrderSerialization::fromJSON(const json &j,Order &order){
  order.setStatus(fromJSON(j));
  order.setOrderID(j["id"]);
  order.setClientID(j["client"]);
  order.setSourceAddress(j["sourceAddress"]);
  order.setDestinationAddress(j["destinationAddress"]);
  order.setCargoSpace(j["cargoSpace"]);
  order.setCargoWeight(j["cargoWeight"]);
  order.setShippingValue(j["shippingValue"]);
  Date date = date.stringToDate(j["date"]);
  order.setDate(date);

}