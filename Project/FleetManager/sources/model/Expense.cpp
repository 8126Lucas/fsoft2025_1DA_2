//
// Created by ruben on 21/05/2025.
//

#include "Expense.h"
#include "Utils.h"
#include "FinancialContainer.h"
#include "FinancialView.h"

Expense::Expense() : amount(0) {}

Expense::Expense(const int id, Trip trip, Date date, double amount, TYPE type) {
    this->id = id;
    this->trip = trip;
    this->date = date;
    this->amount = amount;
    this->type = type;
}

Expense::~Expense() {}

Expense Expense::recordExpense(int id, Trip trip, Date date, double amount, TYPE type) {
    Expense expense(id, trip, date, amount, type);

    FinancialContainer::addExpense(expense);

    return expense;
}

int Expense::removeExpense(ExpenseView expenseView) {
    int id = expenseView.removeExpense();
    return id;
}

int Expense::getId() const {
    return id;
}

Trip Expense::getTrip() const {
    return trip;
}

Date Expense::getDate() const {
    return date;
}

double Expense::getAmount() const {
    return amount;
}

TYPE Expense::getType() const {
    return type;
}