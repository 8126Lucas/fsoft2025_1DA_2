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
        if ((*it).getID() == id) {
            return it;
        }
    }
    return expenses.end();
}

list<Revenue>::iterator FinancialContainer::searchRevenue(int id) {
    list<Revenue>::iterator it = this->revenues.begin();
    for (; it != this->revenues.end(); ++it) {
        if ((*it).getID() == id) {
            return it;
        }
    }
    return revenues.end();
}

Expense *FinancialContainer::getExpense(int id) {
    try {
        list<Expense>::iterator it = searchExpense(id);
        if(it != this->expenses.end()) {
            return &(*it);
        }
        throw NonExistingDataException("Expense ID");
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    return nullptr;
}

void FinancialContainer::addExpense(Expense &expense) {
    try {
        list<Expense>::iterator it = searchExpense(expense.getID());
        if (it != this->expenses.end()) {
            throw DuplicatedDataException("Expense (id): " + to_string(expense.getID()));
        }
        this->expenses.push_back(expense);
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

void FinancialContainer::removeExpense(int id) {
    try
    {
        list<Expense>::iterator it = searchExpense(id);
        if (it != this->expenses.end()) {
            this->expenses.erase(it);
        } else {
            throw NonExistingDataException("Expense (id): " + to_string(id));
        }

    } catch (NonExistingDataException &error)
        {
            cout << error.what() << endl;
        }
}

list<Expense> FinancialContainer::listExpense() {
    list<Expense> newList(this->expenses);
    return newList;
}

list<Expense> FinancialContainer::listExpensesByType(TYPE type) {
    list<Expense> newList;
    list<Expense>::iterator it = this->expenses.begin();
    for (; it != this->expenses.end(); ++it) {
        if (it->getType() == type) {
            newList.push_back(*it);
        }
    }
    return newList;
}

Revenue *FinancialContainer::getRevenue(int id) {
    try {
        list<Revenue>::iterator it = searchRevenue(id);
        if(it != this->revenues.end()) {
            return &(*it);
        }
        throw NonExistingDataException("Revenue ID" + to_string(id));
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}

void FinancialContainer::addRevenue(Revenue &revenue) {
    try {
        list<Revenue>::iterator it = searchRevenue(revenue.getID());
        if (it != this->revenues.end()) {
            throw DuplicatedDataException("Revenue (id): " + to_string(revenue.getID()));
        }
        this->revenues.push_back(revenue);
    } catch (DuplicatedDataException &error) {
        cout << error.what() << endl;
    }
}

void FinancialContainer::removeRevenue(int id) {
    try
    {
        list<Revenue>::iterator it = searchRevenue(id);
        if (it != this->revenues.end()) {
            this->revenues.erase(it);
        } else {
            throw NonExistingDataException("Revenue (id): " + to_string(id));
        }
    } catch (NonExistingDataException &error)
        {
            cout << error.what() << endl;
        }
}

list<Revenue> FinancialContainer::listRevenue() {
    list<Revenue> newList(this->revenues);
    return newList;
}

double FinancialContainer::getExpensesTotal(Date startDate, Date endDate) {
    double totalExpenses = 0;
    list<Expense>::iterator it = this->expenses.begin();
    for (; it != this->expenses.end(); ++it) {
        if ((startDate < it->getDate() || startDate == it->getDate()) && (it->getDate() < endDate || endDate == it->getDate())) {
            totalExpenses += it->getAmount();
        }
    }
    return totalExpenses;
}

double FinancialContainer::getRevenuesTotal(Date startDate, Date endDate) {
    double totalRevenues = 0;
    list<Revenue>::iterator it = this->revenues.begin();
    for (; it != this->revenues.end(); ++it) {
        if ((startDate < it->getDate() || startDate == it->getDate()) && (it->getDate() < endDate || endDate == it->getDate())) {
            totalRevenues += it->getAmount();
        }
    }
    return totalRevenues;
}

double FinancialContainer::getBalance(Date startDate, Date endDate) {
    double totalExpenses = 0, totalRevenues = 0;
    list<Expense>::iterator expenseIT = this->expenses.begin();
    list<Revenue>::iterator revenueIT = this->revenues.begin();
    for (; expenseIT != expenses.end(); ++expenseIT) {
        if ((startDate < expenseIT->getDate() || startDate == expenseIT->getDate()) && (expenseIT->getDate() < endDate || endDate == expenseIT->getDate())) {
            totalExpenses += expenseIT->getAmount();
        }
    }
    for (; revenueIT != revenues.end(); ++revenueIT) {
        if ((startDate < revenueIT->getDate() || startDate == revenueIT->getDate()) && (revenueIT->getDate() < endDate || endDate == revenueIT->getDate())) {
            totalRevenues += revenueIT->getAmount();
        }
    }
    return totalRevenues - totalExpenses;
}