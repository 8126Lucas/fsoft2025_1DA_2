//
// Created by ruben on 17/05/2025.
//

#ifndef VACATION_H
#define VACATION_H

#include "date.h"
#include <vector>
#include "Driver.h"

class Vacation {
private:
    Driver driver;
    Date startDate;
    Date endDate;
    Date today;
    bool status;

public:
    Vacation(Driver driver, const Date& start, const Date& end, const Date& today);

    //funções auxiliares
    bool isActive();
    int getRemainingDays();
};

#endif //VACATION_H