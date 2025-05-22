//
// Created by ruben on 20/05/2025.
//

#ifndef HEADERS_MODEL_EXPENSE_H
#define HEADERS_MODEL_EXPENSE_H

#include <string>
#include <vector>
#include "Date.h"
#include "Trip.h"

enum TYPE{
    Fuel = 1,
    Inspection = 2,
    Insurance = 3,
};

class Expense {
private:
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
    void addExpense();
    void removeExpense();

    int getId();
    Trip getTrip() const;
    Date getDate() const;
    double getAmount() const;
    TYPE getType() const;
};

#endif //HEADERS_MODEL_EXPENSE_H