//
// Created by dinis on 5/20/25.
//

#include "Order.h"
#include "OrderContainer.h"
#include "Utils.h"
#include "Orderview.h"

Order::Order() : orderId(),clientId(),status(UNCOMPLETED) {}

Order::Order(const int &orderId, const int &clientId,const DATE &date,const string &sourceAddress,const string &destinationAddress,
             const double &cargoSpace,const double &cargoWeight,const double &ShippingValue,const ORDERSTATUS &status) {
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

Order Order::addOrder() {
    Order order = OrderView::getOrder();
    OrderContainer::add(order);
}

void Order::removeOrder() {
    int OrderId = OrderView::getorderId();
    OrderContainer::remove(OrderId);
}

void Order::completeOrder() {
    int OrderId = OrderView::getorderId();
    OrderContainer::complete(OrderId);
}