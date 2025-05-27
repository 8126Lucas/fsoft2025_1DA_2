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
    return Expense();
}

Expense *FinancialView::getExpense(FinancialContainer *container) {
    int id = getExpenseID();
    // Expense *expense = container->getExpense(id);
    Expense expense = Expense();
    return &expense;
}

void FinancialView::recordRevenue() {
}

// void *FinancialView::getRevenue(FinancialContainer *container) {
//     int id = getRevenueID();
//     // Revenue *revenue = container->getRevenue(id);
//     // Revenue revenue = Revenue();
//     // return &revenue;
// }

int FinancialView::getExpenseID() {
    int id = Utils::getInt("ID");
    return id;
}

int FinancialView::getRevenueID() {
    int id = Utils::getInt("ID");
    return id;
}

void FinancialView::printExpense(Expense *expense) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Expense " << expense->getID() << " ***\n";
            cout << "Trip: " << expense->getTrip().getID() << endl;
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

void FinancialView::printRevenue(const Revenue *revenue) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            // cout << "*** Revenue " << revenue->getID() << " ***\n";
            // cout << "Order: " << revenue->getOrder().getOrderId() << endl;
            // cout << "Date: " << revenue->getDate() << endl;
            // cout << "Amount: " << revenue->getAmount() << endl;
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

