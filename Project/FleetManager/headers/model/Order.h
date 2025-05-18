//
// Created by dinis on 5/18/25.
//

#ifndef ORDER_H
#define ORDER_H
#include "date.h"
#include <string>
enum ORDERSTATUS{
  Uncompleted =0
  Completed = 1
};
class Order {
  protected:
    int orderId;
    int clientId;
    DATE date;//ver a date
    string sourceAdress;
    string destinationAdress;
    double cargoSpace;
    double cargoWeight;
    double ShippingValue;
  private:
    ORDERSTATUS status;
  public:
    Order(int orderId, int clientId, Date date, string sourceAdress, string destinationAdress,
          double cargoSpace, double cargoWeight, double ShippingValue,orderStatus status);
    ~Order();

    Order addOrder();
    void removeOrder();

    void completeOrder();

    void listUncompletedOrders();
    void listCompletedOrders();
    void listOrdersByClient();



}
#endif //ORDER_H
