//
// Created by ruben on 26/05/2025.
//

#include "VacationView.h"

#include "InvalidDataException.h"
#include "Utils.h"

Vacation VacationView::addVacation(DriverContainer &container) {
    Vacation vacation = Vacation();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("Vacation ID");
            Driver *driver = Utils::getDriver(container, "Driver's ID");
            Date startDate = Utils::getDate("startDate");
            Date endDate = Utils::getDate("endDate");
            bool status = Utils::getBool("Status");
            vacation.setID(id);
            vacation.setDriver(*driver);
            vacation.setStartDate(startDate);
            vacation.setEndDate(endDate);
            vacation.setStatus(status);
        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);

    return vacation;
}

int VacationView::removeVacation() {
    const int id = Utils::getInt("Vacation ID");
    return id;
}