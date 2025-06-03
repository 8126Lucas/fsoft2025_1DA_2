//
// Created by dinis on 5/20/25.
//

#ifndef HEADERS_VIEWS_ORDERVIEW_H
#define HEADERS_VIEWS_ORDERVIEW_H
#include <list>
#include "Order.h"
#include "OrderContainer.h"

class OrderView {
  public:
    static Order addOrder();
    static void completeOrder(Order *order);
    static int removeOrder();
    static Order *getOrder(OrderContainer *container);
    static void printOrder(Order *order);
    static void printOrders(list<Order> &orders);
    //static void printCompleted(orders)
};
#endif //HEADERS_VIEWS_ORDERVIEW_H
