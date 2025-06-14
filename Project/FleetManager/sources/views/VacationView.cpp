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

            int id;
            bool flag_error_id = false;
            do {
                try {
                    flag_error_id = false;
                    id = Utils::getInt("Vacation ID");
                    if (id <= 0) {
                        throw InvalidDataException("Vacation (id): " + to_string(id));
                    }
                } catch (const InvalidDataException &error) {
                    flag_error_id = true;
                    cout << error.what() << endl;
                }
            } while (flag_error_id);

            Driver *driver = Utils::getDriver(container, "Driver's ID");
            Date startDate = Utils::getDate("Start Date");
            Date endDate = Utils::getDate("End Date");

            vacation->setID(id);
            vacation->setDriver(driver);
            vacation->setStartDate(startDate);
            vacation->setEndDate(endDate);
            if ((startDate < today || startDate == today) && (endDate > today || endDate == today)) {
                vacation->setStatus(true);
                vacation->getDriver()->setAvailability(false);
            } else {
                vacation->setStatus(false);
                vacation->getDriver()->setAvailability(true);
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