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

void FinancialSerialization::fromJSON(const json &j, TYPE &type) {
    string stringType = j.get<string>();
    if (stringType == "FUEL") {type = FUEL;}
    if (stringType == "INSPECTION") {type = INSPECTION;}
    if (stringType == "INSURANCE") {type = INSURANCE;}
    if (stringType == "TOLL") {type = TOLL;}
    if (stringType == "FINE") {type = FINE;}
}

void FinancialSerialization::toJSON(json &j, const Expense &expense) {
    j["id"] = expense.getID();
    j["trip"] = expense.getTrip()->getID();
    string string_date = expense.getDate().dateToString();
    j["expenseDate"] = string_date;
    j["amount"] = expense.getAmount();
    j["type"] = expense.getType();
}

void FinancialSerialization::fromJSON(const json &j, Expense &expense) {
    expense.setID(j["id"]);
    expense.setTrip(j["trip"]);
    Date date = date.stringToDate(j["expenseDate"]);
    expense.setDate(date);
    expense.setAmount(j["amount"]);
    expense.setType(j["type"]);
}

void FinancialSerialization::toJSON(json &j, const Revenue &revenue) {
    j["id"] = revenue.getID();
    j["order"] = revenue.getOrder()->getOrderID();
    string string_date = revenue.getDate().dateToString();
    j["revenueDate"] = string_date;
    j["amount"] = revenue.getAmount();
}

void FinancialSerialization::fromJSON(const json &j, Revenue &revenue) {
    revenue.setID(j["id"]);
    revenue.setOrder(j["order"]);
    Date date = date.stringToDate(j["revenueDate"]);
    revenue.setDate(date);
    revenue.setAmount(j["amount"]);
}