//
// Created by ruben on 06/06/2025.
//

#ifndef HEADERS_SERIAL_FINANCIALSERIALIZATION_H
#define HEADERS_SERIAL_FINANCIALSERIALIZATION_H
#include <nlohmann/json.hpp>
#include "Expense.h"
#include "OrderContainer.h"
#include "Revenue.h"
#include "TripContainer.h"

using namespace nlohmann;

class FinancialSerialization {
public:
    void toJSON(json &j, const TYPE &type);
    TYPE fromJSON(const json &j);
    void toJSON(json &j, const Expense &expense);
    void fromJSON(const json &j, Expense &expense, TripContainer &tripContainer);
    void toJSON(json &j, const Revenue &revenue);
    void fromJSON(const json &j, Revenue &revenue, OrderContainer &orderContainer);

};

#endif //HEADERS_SERIAL_FINANCIALSERIALIZATION_H
