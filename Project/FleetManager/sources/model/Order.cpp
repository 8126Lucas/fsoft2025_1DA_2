//
// Created by dinis on 5/20/25.
//

#include "Order.h"
#include "OrderContainer.h"
#include "Utils.h"
#include "Orderview.h"

Order::Order() : orderId(),clientId(),status(IN_PROGRESS) {}

Order::Order(const int orderId, const int clientId,const Date date,const string sourceAddress,const string destinationAddress,
             const double cargoSpace,const double cargoWeight,const double ShippingValue,const ORDERSTATUS status) {
    this->orderId = orderId;
    this->clientId = clientId;
    this->date = date;//cena do date
    this->sourceAddress = sourceAddress;
    this->destinationAddress = destinationAddress;
    this->cargoSpace = cargoSpace;
    this->cargoWeight = cargoWeight;
    this->ShippingValue = ShippingValue;
    this->status = status;

}

Order::~Order() {}

Order Order::addOrder(Order order) {
    OrderContainer::add(order);
}

void Order::removeOrder(int id) {
    OrderContainer::remove(id);
}

void Order::completeOrder(int id) {
    OrderContainer::complete(orderId);
}
void Order::listOrders() {
    OrderContainer::list();
}
void Order::listOrdersByCompletion() {
  list<Order> listUncompleted;
  list<Order> listCompleted;
  auto result = OrderContainer::listCompletion();
  listUncompleted = result.first;
  listCompleted = result.second;
}
