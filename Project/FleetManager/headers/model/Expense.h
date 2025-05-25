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
    FUEL = 1,
    INSPECTION = 2,
    INSURANCCE = 3,
    TOLL = 4,
    FINE = 5,
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

    Expense recordExpense(int id, Trip trip, Date date, double amount, TYPE type);
    void removeExpense();

    int getId() const;
    Trip getTrip() const;
    Date getDate() const;
    double getAmount() const;
    TYPE getType() const;
};

#endif //HEADERS_MODEL_EXPENSE_H