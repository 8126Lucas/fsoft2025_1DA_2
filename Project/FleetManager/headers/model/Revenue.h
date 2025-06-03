//
// Created by ruben on 20/05/2025.
//

#ifndef HEADERS_MODEL_REVENUE_H
#define HEADERS_MODEL_REVENUE_H

#include "Date.h"
#include "Order.h"

class Revenue {
protected:
    int id;
    Order *order;
    Date date;
    double amount;

public:
    Revenue();

    Revenue(int id, Order *order, Date date, double amount);

    ~Revenue();

    int getID() const;
    Order *getOrder() const;
    Date getDate() const;
    double getAmount() const;

    void setID(int id);
    void setOrder(Order *order);
    void setDate(Date date);
    void setAmount(double amount);
};

#endif //HEADERS_MODEL_REVENUE_H