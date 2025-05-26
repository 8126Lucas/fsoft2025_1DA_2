//
// Created by ruben on 21/05/2025.
//

#include "Revenue.h"
#include "Utils.h"
#include "FinancialContainer.h"
#include "FinancialView.h"

Revenue::Revenue() : amount(0) {}

Revenue::Revenue(const int id, Order order, Date date, double amount) {
    this->id = id;
    this->order = order;
    this->date = date;
    this->amount = amount;
}

Revenue::~Revenue() {}

Revenue Revenue::recordRevenue(int id, Order order, Date date, double amount) {
    Revenue revenue(id, order, date, amount);

    FinancialContainer::addRevenue(revenue);

    return revenue;
}

Revenue Revenue::addRevenue(RevenueView revenueView) {
    Revenue revenue = revenueView.addRevenue();
    return revenue;
}

int Revenue::removeRevenue(RevenueView revenueView) {
    int id = revenueView.removeRevenue();
    return id;
}

int Revenue::getID() const {
    return id;
}

Order Revenue::getOrder() const {
    return order;
}

Date Revenue::getDate() const {
    return date;
}

double Revenue::getAmount() const {
    return amount;
}