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