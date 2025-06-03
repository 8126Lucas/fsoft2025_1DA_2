//
// Created by ruben on 21/05/2025.
//

#include "Revenue.h"
#include "Utils.h"
#include "FinancialContainer.h"
#include "FinancialView.h"

Revenue::Revenue() : id(0), amount(0) {}

Revenue::Revenue(const int id, Order *order, Date date, double amount) {
    this->id = id;
    this->order = order;
    this->date = date;
    this->amount = amount;
}

Revenue::~Revenue() {}

int Revenue::getID() const {
    return id;
}

Order *Revenue::getOrder() const {
    return order;
}

Date Revenue::getDate() const {
    return date;
}

double Revenue::getAmount() const {
    return amount;
}


void Revenue::setID(int id) {
    this->id = id;
}

void Revenue::setOrder(Order *order) {
    this->order = order;
}

void Revenue::setDate(Date date) {
    this->date = date;
}

void Revenue::setAmount(double amount) {
    this->amount = amount;
}