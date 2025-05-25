//
// Created by ruben on 21/05/2025.
//

#ifndef HEADERS_VIEWS_FINANCIALVIEW_H
#define HEADERS_VIEWS_FINANCIALVIEW_H
#include <list>
#include "Expense.h"
#include "Revenue.h"

class FinancialView {
public:
    static Expense recordExpense();
    static Expense getExpense(FinancialContainer *container);
    static Revenue recordRevenue();
    static Revenue getRevenue(FinancialContainer *container);
    static int getExpenseId();
    static int getRevenueId();
    static void printExpense(const Expense *expense);
    static void printRevenue(const Revenue *revenue);
    static void printExpenses(list<Expense> &expenses);
    static void printRevenues(list<Revenue> &revenues);
};

#endif //HEADERS_VIEWS_FINANCIALVIEW_H
