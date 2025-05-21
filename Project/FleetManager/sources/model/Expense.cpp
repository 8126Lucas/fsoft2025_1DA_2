//
// Created by ruben on 21/05/2025.
//

#include "Expense.h"
#include "Utils.h"
#include "FinancialContainer.h"
#include "FinancialView.h"

Expense::Expense() : trip(), amount(0) {}

Expense::Expense(const int id, Trip trip, Date date, double amount, TYPE type) {
    this->id = id;
    this->trip = trip;
    this->date = date;
    this->amount = amount;
    this->type = type;
}

Expense::~Expense() {}