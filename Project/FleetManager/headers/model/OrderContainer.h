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
    list<Order>::iterator search(int &orderId);
  public:
    Order *get(int &orderId);
    void add(Order &order);
    void remove(int &orderId);
    list<Order> list();
    list<Order> list(ORDERSTATUS status );
    list<Order> list(int &clientId );
    void complete(int &orderId);

};
#endif //HEADERS_MODEL_ORDERCONTAINER_H
