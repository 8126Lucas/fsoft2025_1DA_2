//
// Created by dinis on 5/20/25.
//
#include "OrderContainer.h"
#include "Order.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include <utility>

list<Order>::iterator OrderContainer::search(int orderId) {
    ::list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if ((*it) == orderId) {
            return it;
        }
    }
    return it;
}

Order *OrderContainer::get(int orderId) {
    ::list<Order>::iterator it = search(orderId);
    if (it != this->orders.end()) {
        return &(*it);
    }
    return NULL;
}
void OrderContainer::add(Order &order) {
    ::list<Order>::iterator it = search(order.getorderId());
    if (it != this->orders.end()) {
        string msg = "order: " + to_string(order.getOrderId());
        throw DuplicatedDataException(msg);
    }
    else {
        this->orders.push_back(order);
    }
}

void OrderContainer::remove(int orderId) {
    ::list<Order>::iterator it = search(orderId);
    if (it != this->orders.end()) {
        this->orders.erase(it);
    }
    else {
        string msg = "order: " + to_string(orderId);
        throw NonExistingDataException(msg);
    }
}

void OrderContainer::complete(int orderId) {
    ::list<Order>::iterator it = search(orderId);
    if (it != this->orders.end()) {
        (*it).setStatus(COMPLETED);//ver os sets
    }
}

list<Order> OrderContainer::list() {
    ::list<Order> newList(this->orders);
    return newList;
}

std::list<Order> OrderContainer::listUncompleted(){
    ::list<Order> listUncompleted;
    ::list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getStatus() == IN_PROGRESS) listUncompleted.push_back(*it);
    }
    return listUncompleted;
}

std::list<Order> OrderContainer::listCompleted(){
    ::list<Order> listCompleted;
    ::list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getStatus() == COMPLETED) listCompleted.push_back(*it);
    }
    return listCompleted;
}
/*std::pair<std::list<Order>, std::list<Order>> OrderContainer::listCompletion() {
    ::list<Order> listUncompleted;
    ::list<Order> listCompleted;
    ::list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getStatus() == IN_PROGRESS) listUncompleted.push_back(*it);
        else listCompleted.push_back(*it);
    }
    return std::make_pair(listUncompleted, listCompleted);
}
*/
std::list<Order> OrderContainer::listClient(int clientId){
    ::list<Order> listClient;
    ::list<Order>::iterator it = this->orders.begin();
    for (; it != this->orders.end(); ++it) {
        if (it->getClientId() == clientId) listClient.push_back(*it);
    }
    return listClient;
}


