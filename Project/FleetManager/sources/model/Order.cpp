//
// Created by dinis on 5/20/25.
//

#include "Order.h"
#include "OrderContainer.h"
#include "Utils.h"
#include "OrderView.h"
#include "Date.h"

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
    OrderContainer::complete(id);
}
void Order::listOrders() {
    OrderContainer::list();
}
/*void Order::listOrdersByCompletion() {
  list<Order> listUncompleted;
  list<Order> listCompleted;
  auto result = OrderContainer::listCompletion();
  listUncompleted = result.first;
  listCompleted = result.second;
}*/

void Order::listCompletedOrders() {
    OrderContainer::listCompleted();
}

void Order::listUncompletedOrders() {
    OrderContainer::listUncompleted();
}

int Order::getOrderId() {
    return orderId;
}

int Order::getClientId() {
    return clientId;
}

Date Order::getDate() {
    return date;
}

string Order::getSourceAddress() {
    return sourceAddress;
}

string Order::getDestinationAddress() {
    return destinationAddress;
}

double Order::getCargoSpace() {
    return cargoSpace;
}

double Order::getCargoWeight() {
    return cargoWeight;
}

double Order::getShippingValue() {
    return ShippingValue;
}

ORDERSTATUS Order::getStatus() {
    return status;
}