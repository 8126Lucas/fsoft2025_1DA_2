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
    void add(Order &order);//static
    void remove(int orderId);
    list<Order> listOrders();
    // std::pair<std::list<Order>, std::list<Order>> listCompletion();
    std::list<Order> listCompleted();
    std::list<Order> listUncompleted();
    std::list<Order> listClient(int clientID);
    void complete(int orderId);
  //void set(void param)

};
#endif //HEADERS_MODEL_ORDERCONTAINER_H
