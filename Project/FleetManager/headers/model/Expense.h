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
    INSURANCE = 3,
    TOLL = 4,
    FINE = 5,
};

class Expense {
private:
    int id;
    Trip *trip;
    Date date;
    double amount;
    TYPE type;

public:
    Expense();

    Expense(int id, Trip *trip, Date date, double amount, TYPE type);

    ~Expense();

    int getID() const;
    Trip *getTrip();
    Date getDate() const;
    double getAmount() const;
    TYPE getType() const;

    void setID(int id);
    void setTrip(Trip *trip);
    void setDate(Date date);
    void setAmount(double amount);
    void setType(TYPE type);
};

#endif //HEADERS_MODEL_EXPENSE_H