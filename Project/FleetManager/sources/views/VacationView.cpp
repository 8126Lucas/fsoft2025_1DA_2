//
// Created by ruben on 26/05/2025.
//

#include "VacationView.h"

#include "InvalidDataException.h"
#include "Utils.h"

Vacation *VacationView::addVacation(DriverContainer &container) {
    Vacation *vacation = new Vacation();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            Date today = Date::getToday();
            int id = Utils::getInt("Vacation ID");
            Driver *driver = Utils::getDriver(container, "Driver's ID");
            Date startDate = Utils::getDate("Start Date");
            Date endDate = Utils::getDate("End Date");
            vacation->setID(id);
            vacation->setDriver(driver);
            vacation->setStartDate(startDate);
            vacation->setEndDate(endDate);
            if (startDate > today || endDate < today) {
                vacation->setStatus(false);
                vacation->getDriver()->setAvailability(true);
            } else {
                vacation->setStatus(true);
                vacation->getDriver()->setAvailability(false);
            }
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);

    return vacation;
}

int VacationView::removeVacation() {
    const int id = Utils::getInt("Vacation ID");
    return id;
}