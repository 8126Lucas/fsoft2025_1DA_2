//
// Created by ruben on 20/05/2025.
//

#ifndef HEADERS_MODEL_FINANCIALCONTAINER_H
#define HEADERS_MODEL_FINANCIALCONTAINER_H

#include <vector>
#include <list>
#include "Expense.h"
#include "Revenue.h"

using namespace std;

class FinancialContainer {
private:
    list<Expense> expenses;
    list<Expense>::iterator search(Expense &expense);
    list<Expense>::iterator searchExpense(int id);

    list<Revenue> revenues;
    list<Revenue>::iterator search(Revenue &revenue);
    list<Revenue>::iterator searchRevenue(int id);
public:
    Expense *getExpense(int id);
    void addExpense(Expense &expense);
    void removeExpense(Expense &expense);
    list<Expense> listExpense();
    list<Expense> listExpensesByType(TYPE type);

    Revenue *getRevenue(int id);
    void addRevenue(Revenue &revenue);
    void removeRevenue(Revenue &revenue);
    list<Revenue> listRevenue();
};

#endif //HEADERS_MODEL_FINANCIALCONTAINER_H