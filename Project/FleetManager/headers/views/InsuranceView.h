//
// Created by lucas on 5/22/25.
//

#ifndef HEADERS_VIEWS_INSURANCEVIEW_H
#define HEADERS_VIEWS_INSURANCEVIEW_H
#include "Insurance.h"
#include "VehicleContainer.h"


class InsuranceView {
public:
    Insurance addInsurance(VehicleContainer &container);
    string removeInsurance();
};

#endif //HEADERS_VIEWS_INSURANCEVIEW_H
