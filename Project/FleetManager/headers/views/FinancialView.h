//
// Created by ruben on 21/05/2025.
//

#ifndef HEADERS_VIEWS_FINANCIALVIEW_H
#define HEADERS_VIEWS_FINANCIALVIEW_H
#include <list>
#include "Expense.h"
#include "Revenue.h"
#include "FinancialContainer.h"
#include "TripContainer.h"
#include "OrderContainer.h"

class FinancialView {
public:
    static Expense recordExpense(TripContainer &containerTrip);
    static int removeExpense();
    static Expense *getExpense(FinancialContainer *container);
    static Revenue recordRevenue(OrderContainer &containerOrder);
    static Revenue *getRevenue(FinancialContainer *container);
    static int removeRevenue();
    // static void *getRevenue(FinancialContainer *container);
    static int getExpenseID();
    static int getRevenueID();

    static void printExpense(Expense *expense);
    static void printRevenue(const Revenue *revenue);
    static void printExpenses(list<Expense> &expenses);
    void printExpensesByType(list<Expense> &expenses, TYPE type);
    static void printRevenues(list<Revenue> &revenues);
    void printAllFinancialRecords(list<Expense> &expenses, list<Revenue> &revenues);

    void printBalance(FinancialContainer &containerFinancial, Date startDate, Date endDate);
    void printInvalidTypeError();
};

#endif //HEADERS_VIEWS_FINANCIALVIEW_H
