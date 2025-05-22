//
// Created by dinis on 5/18/25.
//

#ifndef HEADERS_MODEL_ORDER_H
#define HEADERS_MODEL_ORDER_H
#include "Date.h"
#include <string>

using namespace std;

enum ORDERSTATUS{
  IN_PROGRESS = 0,//removido uncompleted
  COMPLETED = 1,
};
class Order {
  protected:
    int orderId;
    int clientId;
    Date date;
    string sourceAddress;
    string destinationAddress;
    double cargoSpace;
    double cargoWeight;
    double ShippingValue;
  private:
    ORDERSTATUS status;
  public:
    Order();

    Order(int orderId, int clientId, Date date, string sourceAddress, string destinationAddress,
          double cargoSpace, double cargoWeight, double ShippingValue,ORDERSTATUS status);
    ~Order();

    Order addOrder(Order order);
    void removeOrder(int orderId);
    void completeOrder(int orderId);

    void listOrders();
    void listOrdersByCompletion();
    void listOrdersByClient(int clientId);

    int getOrderId();
    int getClientId();
    string getSourceAddress();
    string getDestinationAddress();
    double getCargoSpace();
    double getCargoWeight();
    double getShippingValue();
    ORDERSTATUS getStatus();

    void setStatus(ORDERSTATUS status);

    bool operator==(int id) const;

};
#endif //HEADERS_MODEL_ORDER_H
