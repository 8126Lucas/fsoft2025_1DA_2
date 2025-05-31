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

Expense FinancialView::recordExpense(TripContainer &containerTrip) {
    Expense expense = Expense();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("ID");
            Trip *trip = Utils::getTrip(containerTrip, "Trip ID");
            Date date = Utils::getDate("Date");
            double amount = Utils::getDouble("Amount");
            TYPE type = static_cast<TYPE>(Utils::getInt("Type (FUEL/INSPECTION/INSURANCE/TOLL/FINE - 1->5)"));

            expense.setID(id);
            expense.setTrip(trip);
            expense.setDate(date);
            expense.setAmount(amount);
            expense.setType(type);
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
    return expense;
}

int FinancialView::removeExpense() {
    int id = Utils::getInt("Expense ID");
    return id;
}

Revenue FinancialView::recordRevenue(OrderContainer &containerOrder) {
    Revenue revenue = Revenue();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("ID");
            Order *order = Utils::getOrder(containerOrder, "Order ID");
            Date date = Utils::getDate("Date");
            double amount = Utils::getDouble("Amount");

            revenue.setID(id);
            revenue.setOrder(order);
            revenue.setDate(date);
            revenue.setAmount(amount);
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
    return revenue;
}

int FinancialView::removeRevenue() {
    int id = Utils::getInt("Revenue ID");
    return id;
}

// Expense *FinancialView::getExpense(FinancialContainer *container) {
//     int id = getExpenseID();
//     // Expense *expense = container->getExpense(id);
//     Expense expense = Expense();
//     return expense;
// }


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
            cout << "Trip: " << expense->getTrip()->getID() << endl;
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
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
}

void FinancialView::printRevenue(const Revenue *revenue) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Revenue " << revenue->getID() << " ***\n";
            cout << "Order: " << revenue->getOrder()->getOrderId() << endl;
            cout << "Date: " << revenue->getDate() << endl;
            cout << "Amount: " << revenue->getAmount() << endl;
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
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

void FinancialView::printBalance(FinancialContainer &containerFinancial, Date startDate, Date endDate) {
    double totalExpenses = containerFinancial.getExpensesTotal(startDate, endDate);
    double totalRevenues = containerFinancial.getRevenuesTotal(startDate, endDate);
    double balance = containerFinancial.getBalance(startDate, endDate);
    cout << "\nTotal Expenses (" << startDate << "-" << endDate << "): " << totalExpenses << endl;
    cout << "Total Revenues (" << startDate << "-" << endDate << "): " << totalRevenues << endl;
    cout << "Balance (" << startDate << "-" << endDate << "): " << balance << endl;
}
