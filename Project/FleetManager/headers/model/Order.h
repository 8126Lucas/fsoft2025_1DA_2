//
// Created by dinis on 5/18/25.
//

#ifndef HEADERS_MODEL_ORDER_H
#define HEADERS_MODEL_ORDER_H
#include "Date.h"
#include <string>

using namespace std;

enum ORDERSTATUS{
  UNCOMPLETED = 0,
  IN_PROGRESS = 1,
  COMPLETED = 2,
};
class Order {
  protected:
    int orderId;
    int clientId;
    DATE date;//ver a date
    string sourceAddress;
    string destinationAddress;
    double cargoSpace;
    double cargoWeight;
    double ShippingValue;
  private:
    ORDERSTATUS status;
  public:
    Order(int orderId, int clientId, Date date, string sourceAddress, string destinationAddress,
          double cargoSpace, double cargoWeight, double ShippingValue,ORDERSTATUS status);
    ~Order();

    Order addOrder();
    void removeOrder();

    void completeOrder();

    void listUncompletedOrders();
    void listCompletedOrders();
    void listOrdersByClient();

    int getOrderId();
    int getClientId();
  //adicionar o resto dps

};
#endif //HEADERS_MODEL_ORDER_H
