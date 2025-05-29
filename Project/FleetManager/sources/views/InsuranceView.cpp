//
// Created by lucas on 22/05/2025.
//

#include "InsuranceView.h"

#include "InvalidDataException.h"
#include "Utils.h"

Insurance InsuranceView::addInsurance(VehicleContainer &container) {
    Insurance insurance = Insurance();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("Insurance ID");
            Vehicle *vehicle = Utils::getVehicle(container, "Vehicle's License Plate");
            Date startDate = Utils::getDate("Start Date");
            Date endDate = Utils::getDate("End Date");
            double monthlyCost = Utils::getDouble("Monthly Cost");
            insurance.setID(id);
            insurance.setVehicle(vehicle);
            insurance.setStartDate(startDate);
            insurance.setEndDate(endDate);
            insurance.setMonthlyCost(monthlyCost);
        } catch (InvalidDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
    return insurance;
}

string InsuranceView::removeInsurance() {
    string licensePlate = Utils::getString("Vehicle's License Plate");
    return licensePlate;
}
