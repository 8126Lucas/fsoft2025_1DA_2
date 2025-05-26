//
// Created by ruben on 24/05/2025.
//

#include <iostream>
#include "FinancialView.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include "Expense.h"
#include "Revenue.h"
#include "FinancialContainer.h"

using namespace std;

Expense FinancialView::recordExpense() {
    Expense expense = Utils::setExpense();
    return expense;
}

Expense *FinancialView::getExpense(FinancialContainer *container) {
    int id = getExpenseId();
    Expense *expense = container->getExpense(id);
    return expense;
}

Revenue FinancialView::recordRevenue() {
    Revenue revenue = Utils::setRevenue();
    return revenue;
}

Revenue *FinancialView::getRevenue(FinancialContainer *container) {
    int id = getRevenueId();
    Revenue *revenue = container->getRevenue(id);
    return revenue;
}

int FinancialView::getExpenseId() {
    int id = Utils::getInt("Id");
    return id;
}

int FinancialView::getRevenueId() {
    int id = Utils::getInt("Id");
    return id;
}

void FinancialView::printExpense(Expense *expense) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Expense " << expense->getId() << " ***\n";
            cout << "Trip: " << expense->getTrip() << endl;
            cout << "Date: " << expense->getDate() << endl;
            cout << "Amount: " << expense->getAmount() << endl;
            if (expense->getType() == 1) {
                cout << "Type: Fuel Expense\n";
            } else if (expense->getType() == 2) {
                cout << "Type: Inspection Expense\n";
            } else if (expense->getType() == 3) {
                cout << "Type: Insurance Expense\n";
            } else if (expense->getType() == 4) {
                cout << "Type: Toll Expense\n";
            } else if (expense->getType() == 5) {
                cout << "Type: Fine Expense\n";
            }
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void FinancialView::printRevenue(Revenue *revenue) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Revenue " << revenue->getId() << " ***\n";
            cout << "Order: " << revenue->getOrder() << endl;
            cout << "Date: " << revenue->getDate() << endl;
            cout << "Amount: " << revenue->getAmount() << endl;
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void FinancialView::printExpenses(list<Expense> &expenses) {
    list<Expense>::iterator it = expenses.begin();
    for (; it != expenses.end(); ++it) {
        printExpense(&*it);
    }
}

void FinancialView::printRevenues(list<Revenue> &revenues) {
    list<Revenue>::iterator it = revenues.begin();
    for (; it != revenues.end(); ++it) {
        printRevenue(&*it);
    }
}

