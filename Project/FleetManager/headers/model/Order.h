//
// Created by dinis on 5/18/25.
//

#ifndef HEADERS_MODEL_ORDER_H
#define HEADERS_MODEL_ORDER_H
#include "Date.h"
#include <string>

using namespace std;

enum STATUS{
  IN_PROGRESS = 0,
  COMPLETED = 1,
};
class Order {
  private:
    STATUS status;
    int orderID;
    int clientID;
    Date date;
    string sourceAddress;
    string destinationAddress;
    double cargoSpace;
    double cargoWeight;
    double shippingValue;
  public:
    Order();

    Order(int orderId, int clientId, Date date, string sourceAddress, string destinationAddress,
          double cargoSpace, double cargoWeight, double ShippingValue,STATUS status);

  ~Order();


    Date getDate() const;
    int getOrderID() const;
    int getClientID() const;
    string getSourceAddress() const;
    string getDestinationAddress() const;
    double getCargoSpace() const;
    double getCargoWeight() const;
    double getShippingValue() const;
    STATUS getStatus() const;

    void setStatus(STATUS status);
    void setOrderID(int orderID);
    void setClientID(int clientID);
    void setDate(Date date);
    void setSourceAddress(string sourceAddress);
    void setDestinationAddress(string destinationAddress);
    void setCargoSpace(double cargoSpace);
    void setCargoWeight(double cargoWeight);
    void setShippingValue(double shippingValue);

};
#endif //HEADERS_MODEL_ORDER_H
