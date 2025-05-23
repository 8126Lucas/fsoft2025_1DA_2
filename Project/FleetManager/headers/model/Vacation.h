//
// Created by ruben on 17/05/2025.
//

#ifndef HEADERS_MODEL_VACATION_H
#define HEADERS_MODEL_VACATION_H

#include "Date.h"
#include "VacationView.h"
#include "Driver.h"

class Vacation {
private:
    int id;
    Driver *driver;
    Date startDate;
    Date endDate;
    Date today = Date::getToday();
    bool status;

public:
    Vacation(Driver *driver, const Date& start, const Date& end, const Date& today);

    Vacation addVacation(VacationView vacationView);
    int removeVacation(VacationView vacationView);

    int getId();
    bool isOnVacation();
    int getRemainingDays() const;
    void updateToday();
};

#endif //HEADERS_MODEL_VACATION_H