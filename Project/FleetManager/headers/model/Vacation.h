//
// Created by ruben on 17/05/2025.
//

#ifndef HEADERS_MODEL_VACATION_H
#define HEADERS_MODEL_VACATION_H
#include "Date.h"

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
    Vacation(int id, Driver *driver, Date startDate, Date endDate, bool status);
    ~Vacation();

    int getID() const;
    Driver *getDriver() const;
    Date getStartDate() const;
    Date getEndDate() const;
    bool getStatus() const;

    void setID(int id);
    void setDriver(Driver &driver);
    void setStartDate(Date startDate);
    void setEndDate(Date endDate);
    void setStatus(bool status);

    bool isOnVacation();
    int getRemainingDays() const;
    void updateToday();
};

#endif //HEADERS_MODEL_VACATION_H