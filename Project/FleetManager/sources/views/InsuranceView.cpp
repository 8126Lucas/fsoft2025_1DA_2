//
// Created by lucas on 22/05/2025.
//

#include "InsuranceView.h"
#include "Utils.h"



Insurance InsuranceView::addInsurance() {
    Insurance insurance = Utils::setInsurance();
    return insurance;
}

int InsuranceView::removeInsurance() {
    const int id = Utils::getInt("Insurance ID");
    return id;
}
