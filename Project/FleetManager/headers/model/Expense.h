//
// Created by ruben on 20/05/2025.
//

#ifndef HEADERS_MODEL_EXPENSE_H
#define HEADERS_MODEL_EXPENSE_H

#include <string>
#include <vector>
#include "Date.h"
#include "Trip.h"

enum class TYPE{
    Fuel = 1,
    Inspection = 2,
    Insurance = 3,
  };

class Expense {
protected:
    int id;
    Trip trip;
    Date date;
    double amount;
    TYPE type;

public:
    Expense();

    Expense(int id, Trip trip, Date date, double amount, TYPE type);

    ~Expense();

    Expense recordExpense();

    //Provisório
    void listExpenses();
    void listExpensesByType();
};

#endif //HEADERS_MODEL_EXPENSE_H