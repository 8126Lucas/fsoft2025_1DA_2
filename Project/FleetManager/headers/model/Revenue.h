//
// Created by ruben on 20/05/2025.
//

#ifndef HEADERS_MODEL_REVENUE_H
#define HEADERS_MODEL_REVENUE_H

#include <string>
#include <vector>
#include "Date.h"
#include "Order.h"

class Revenue {
protected:
    int id;
    Order order;
    Date date;
    double amount;

public:
    Revenue();

    Revenue(int id, Order order, Date date, double amount);

    ~Revenue();

    Revenue recordRevenue(int id, Order order, Date date, double amount);
    void removeRevenue();

    int getID() const;
    Order getOrder() const;
    Date getDate() const;
    double getAmount() const;
};

#endif //HEADERS_MODEL_REVENUE_H