//
// Created by ruben on 06/06/2025.
//

#include "FinancialSerialization.h"
#include "Expense.h"
#include "Revenue.h"

void FinancialSerialization::toJSON(json &j, const TYPE &type) {
    switch (type) {
        case FUEL:
            j = "FUEL";
            break;
        case INSPECTION:
            j = "INSPECTION";
            break;
        case INSURANCE:
            j = "INSURANCE";
            break;
        case TOLL:
            j = "TOLL";
            break;
        case FINE:
            j = "FINE";
            break;
    }
}

TYPE FinancialSerialization::fromJSON(const json &j) {
    string stringType = j.get<string>();
    if (stringType == "FUEL") {return FUEL;}
    if (stringType == "INSPECTION") {return INSPECTION;}
    if (stringType == "INSURANCE") {return INSURANCE;}
    if (stringType == "TOLL") {return TOLL;}
    if (stringType == "FINE") {return FINE;}
}

void FinancialSerialization::toJSON(json &j, const Expense &expense) {
    j["id"] = expense.getID();
    j["trip"] = expense.getTrip()->getID();
    string string_date = expense.getDate().dateToString();
    j["expenseDate"] = string_date;
    j["amount"] = expense.getAmount();
    toJSON(j["type"], expense.getType());
}

void FinancialSerialization::fromJSON(const json &j, Expense &expense, TripContainer &tripContainer) {
    expense.setID(j["id"]);
    const int tripID = j["trip"].get<int>();
    Trip* trip = tripContainer.getTrip(tripID);
    expense.setTrip(trip);
    Date date = date.stringToDate(j["expenseDate"]);
    expense.setDate(date);
    expense.setAmount(j["amount"]);
    expense.setType(fromJSON(j["type"]));
}

void FinancialSerialization::toJSON(json &j, const Revenue &revenue) {
    j["id"] = revenue.getID();
    j["order"] = revenue.getOrder()->getOrderID();
    string string_date = revenue.getDate().dateToString();
    j["revenueDate"] = string_date;
    j["amount"] = revenue.getAmount();
}

void FinancialSerialization::fromJSON(const json &j, Revenue &revenue, OrderContainer &orderContainer) {
    revenue.setID(j["id"]);
    const int orderID = j["order"].get<int>();
    Order* order = orderContainer.get(orderID);
    revenue.setOrder(order);
    Date date = date.stringToDate(j["revenueDate"]);
    revenue.setDate(date);
    revenue.setAmount(j["amount"]);
}