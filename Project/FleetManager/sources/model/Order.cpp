//
// Created by dinis on 5/20/25.
//

#include "Order.h"
#include "OrderContainer.h"
#include "Utils.h"
#include "OrderView.h"
#include "Date.h"

Order::Order() : orderID(),cargoSpace(0),cargoWeight(0),shippingValue(0), clientID(), status(IN_PROGRESS) {}

Order::Order(const int orderId, const int clientId,const Date date,const string sourceAddress,const string destinationAddress,
             const double cargoSpace,const double cargoWeight,const double ShippingValue,const STATUS status) {
    this->orderID = orderId;
    this->clientID = clientId;
    this->date = date;//cena do date
    this->sourceAddress = sourceAddress;
    this->destinationAddress = destinationAddress;
    this->cargoSpace = cargoSpace;
    this->cargoWeight = cargoWeight;
    this->shippingValue = ShippingValue;
    this->status = status;

}

Order::~Order() {}

int Order::getOrderID() const {
    return orderID;
}

int Order::getClientID() const {
    return clientID;
}

Date Order::getDate() const {
    return date;
}

string Order::getSourceAddress() const {
    return sourceAddress;
}

string Order::getDestinationAddress() const {
    return destinationAddress;
}

double Order::getCargoSpace() const {
    return cargoSpace;
}

double Order::getCargoWeight() const {
    return cargoWeight;
}

double Order::getShippingValue() const {
    return shippingValue;
}

STATUS Order::getStatus() const {
    return status;
}

void Order::setStatus(STATUS status) {
    this->status = status;
}


void Order::setOrderID(int orderID) {
    this->orderID = orderID;
}

void Order::setClientID(int clientID) {
    this->clientID = clientID;
}

void Order::setDate(Date date) {
    this->date = date;
}

void Order::setSourceAddress(string sourceAddress) {
    this->sourceAddress = sourceAddress;
}

void Order::setDestinationAddress(string destinationAddress) {
    this->destinationAddress = destinationAddress;
}

void Order::setCargoWeight(double cargoweight) {
    this->cargoWeight = cargoweight;
}

void Order::setCargoSpace(double cargoSpace){
    this->cargoSpace = cargoSpace;
}

void Order::setShippingValue(double shippingValue) {
    this->shippingValue = shippingValue;
}