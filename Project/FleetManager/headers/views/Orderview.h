//
// Created by dinis on 5/20/25.
//

#ifndef HEADERS_VIEWS_ORDERVIEW_H
#define HEADERS_VIEWS_ORDERVIEW_H
#include <list>
#include "Order.h"

class OrderView {
  public:
    static Order getOrder();
    static int getorderId();
    static void PrintOrder(Order *order);
    static void PrintOrders(list<Order> &orders);
};
#endif //HEADERS_VIEWS_ORDERVIEW_H
