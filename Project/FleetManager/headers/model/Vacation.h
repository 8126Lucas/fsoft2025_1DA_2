//
// Created by ruben on 17/05/2025.
//

#ifndef HEADERS_MODEL_VACATION_H
#define HEADERS_MODEL_VACATION_H

#include "Date.h"
#include "VacationView.h"

class Driver;

class Vacation {
private:
    int id;
    Driver *driver;
    Date startDate;
    Date endDate;
    Date today = Date::getToday();
    bool status;

public:
    Vacation();
    Vacation(int id, Driver *driver, const Date startDate, const Date endDate, bool status);
    Vacation(Driver *driver, const Date& start, const Date& end, const Date& today);

    Vacation addVacation(VacationView vacationView);
    int removeVacation(VacationView vacationView);

    int getID() const;
    Driver getDriver() const;
    Date getStartDate() const;
    Date getEndDate() const;
    bool getStatus() const;
    bool isOnVacation();
    int getRemainingDays() const;
    void updateToday();
};

#endif //HEADERS_MODEL_VACATION_H