//
// Created by ruben on 26/05/2025.
//

#include "FinancialContainer.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"

list<Expense>::iterator FinancialContainer::searchExpense(int id) {
    list<Expense>::iterator it = this->expenses.begin();
    for (; it != this->expenses.end(); ++it) {
        if ((*it).getId() == id) {
            return it;
        }
    }
    return it;
}

list<Revenue>::iterator FinancialContainer::searchRevenue(int id) {
    list<Revenue>::iterator it = this->revenues.begin();
    for (; it != this->revenues.end(); ++it) {
        if ((*it).getId() == id) {
            return it;
        }
    }
    return it;
}

Expense *FinancialContainer::getExpense(int id) {
    list<Expense>::iterator it = searchExpense(id);
    if(it != this->expenses.end()) {
        return &(*it);
    }
    return NULL;
}

void FinancialContainer::addExpense(Expense &expense) {
    list<Expense>::iterator it = searchExpense(expense.getId());
    if (it != this->expenses.end()) {
        string msg = "Expense (id): " + to_string(expense.getId());
        throw DuplicatedDataException(msg);
    }
    this->expenses.push_back(expense);
}

void FinancialContainer::removeExpense(Expense &expense) {
    list<Expense>::iterator it = searchExpense(expense.getId());
    if (it != this->expenses.end()) {
        this->expenses.erase(it);
    }
    else {
        string msg = "Expense (id): " + to_string(expense.getId());
        throw NonExistingDataException(msg);
    }
}

list<Expense> FinancialContainer::listExpense() {
    list<Expense> newList(this->expenses);
    return newList;
}

//acabar
list<Expense> FinancialContainer::listExpensesByType(TYPE type) {
    list<Expense> newList(this->expenses);
    return newList;
}

Revenue *FinancialContainer::getRevenue(int id) {
    list<Revenue>::iterator it = searchRevenue(id);
    if(it != this->revenues.end()) {
        return &(*it);
    }
    return NULL;
}

void FinancialContainer::addRevenue(Revenue &revenue) {
    list<Revenue>::iterator it = searchRevenue(revenue.getId());
    if (it != this->revenues.end()) {
        string msg = "Revenue (id): " + to_string(revenue.getId());
        throw DuplicatedDataException(msg);
    }
    this->revenues.push_back(revenue);
}

void FinancialContainer::removeRevenue(Revenue &revenue) {
    list<Revenue>::iterator it = searchRevenue(revenue.getId());
    if (it != this->revenues.end()) {
        this->revenues.erase(it);
    }
    else {
        string msg = "Revenue (id): " + to_string(revenue.getId());
        throw NonExistingDataException(msg);
    }
}

list<Revenue> FinancialContainer::listRevenue() {
    list<Revenue> newList(this->revenues);
    return newList;
}