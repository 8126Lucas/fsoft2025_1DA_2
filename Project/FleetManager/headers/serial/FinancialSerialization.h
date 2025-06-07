//
// Created by ruben on 06/06/2025.
//

#ifndef HEADERS_SERIAL_FINANCIALSERIALIZATION_H
#define HEADERS_SERIAL_FINANCIALSERIALIZATION_H
#include <nlohmann/json.hpp>
#include "Expense.h"
#include "Revenue.h"

using namespace nlohmann;

class FinancialSerialization {
public:
    void toJSON(json &j, const TYPE &type);
    void fromJSON(const json &j, TYPE &type);
    void toJSON(json &j, const Expense &expense);
    void fromJSON(const json &j, Expense &expense);
    void toJSON(json &j, const Revenue &revenue);
    void fromJSON(const json &j, Revenue &revenue);

};

#endif //HEADERS_SERIAL_FINANCIALSERIALIZATION_H
