//
// Created by ruben on 21/05/2025.
//

#include "Expense.h"
#include "Utils.h"
#include "FinancialContainer.h"
#include "FinancialView.h"

Expense::Expense() : id(0), trip(nullptr), amount(0.0), type(FUEL) {}

Expense::Expense(const int id, Trip *trip, Date date, double amount, TYPE type) {
    this->id = id;
    this->trip = trip;
    this->date = date;
    this->amount = amount;
    this->type = type;
}

Expense::~Expense() {}

int Expense::getID() const {
    return id;
}

Trip *Expense::getTrip() const {
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

void Expense::setID(int id) {
    this->id = id;
}

void Expense::setTrip(Trip *trip) {
    this->trip = trip;
}

void Expense::setDate(Date date) {
    this->date = date;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
}

void Expense::setType(TYPE type) {
    this->type = type;
}