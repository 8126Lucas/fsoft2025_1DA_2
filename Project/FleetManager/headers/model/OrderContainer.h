//
// Created by dinis on 5/19/25.
//

#ifndef HEADERS_MODEL_ORDERCONTAINER_H
#define HEADERS_MODEL_ORDERCONTAINER_H

#include <list>
#include "Order.h"

using namespace std;
class OrderContainer {
  private:
    list<Order> orders;
    list<Order>::iterator search(int orderId);
  public:
    Order *get(int orderId);
    void add(Order &order);
    void remove(int orderId);
    void update(Order *order);
    list<Order> listOrders();

    list<Order> listCompleted();
    list<Order> listUncompleted();
    list<Order> listOrdersByClient(int clientID);


};
#endif //HEADERS_MODEL_ORDERCONTAINER_H
