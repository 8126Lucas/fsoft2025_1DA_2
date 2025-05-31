//
// Created by dinis on 5/20/25.
//
#include "OrderContainer.h"
#include "Order.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include <utility>

using namespace std;

list<Order>::iterator OrderContainer::search(int orderID) {
    list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getOrderID() == orderID) {
            return it;
        }
    }
    return orders.end();
}

Order *OrderContainer::get(int orderID) {
    list<Order>::iterator it = search(orderID);
    if (it != this->orders.end()) {
        return &(*it);
    }
    throw NonExistingDataException("Order ID");
}

void OrderContainer::add(Order &order) {
    list<Order>::iterator it = search(order.getOrderID());
    if (it != this->orders.end()) {
        string msg = "Order: " + to_string(order.getOrderID());
        throw DuplicatedDataException(msg);
    }
    this->orders.push_back(order);
}

void OrderContainer::remove(int orderId) {
    list<Order>::iterator it = search(orderId);
    if (it != this->orders.end()) {
        this->orders.erase(it);
    }
    else {
        string msg = "Order: " + to_string(orderId);
        throw NonExistingDataException(msg);
    }
}

void OrderContainer::update(Order *order) {
    list<Order>::iterator it = search(order->getOrderID());
    if (it != this->orders.end()) {
        this->orders.erase(it);
        this->orders.push_back(*order);
    }
}

list<Order> OrderContainer::listOrders() {
    list<Order> newList(this->orders);
    return newList;
}

std::list<Order> OrderContainer::listUncompleted(){
    list<Order> listUncompleted;
    list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getStatus() == IN_PROGRESS) {listUncompleted.push_back(*it);}
    }
    return listUncompleted;
}

std::list<Order> OrderContainer::listCompleted(){
    list<Order> listCompleted;
    list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getStatus() == COMPLETED) {listCompleted.push_back(*it);}
    }
    return listCompleted;
}

list<Order> OrderContainer::listOrdersByClient(int clientID){
    list<Order> listOrder;
    list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getClientID() == clientID) {listOrder.push_back(*it);}
    }
    return listOrder;
}