//
// Created by ruben on 26/05/2025.
//

#ifndef HEADERS_VIEWS_VACATIONVIEW_H
#define HEADERS_VIEWS_VACATIONVIEW_H
#include "Vacation.h"

class VacationView {
public:
    static Vacation addVacation(DriverContainer &container);
    static int removeVacation();
};

#endif //HEADERS_VIEWS_VACATIONVIEW_H
