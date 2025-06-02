//
// Created by lucas on 22/05/2025.
//

#include "InspectionView.h"

#include "InvalidDataException.h"
#include "Utils.h"

Inspection *InspectionView::addInspection(VehicleContainer &container) {
    Inspection *inspection = new Inspection();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int id = Utils::getInt("Inspection ID");
            Vehicle *vehicle = Utils::getVehicle(container, "Vehicle's License Plate");
            Date date = Utils::getDate("Date");
            double cost = Utils::getDouble("Cost");
            inspection->setID(id);
            inspection->setVehicle(vehicle);
            inspection->setDate(date);
            inspection->setCost(cost);
            inspection->setToday();
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);

    return inspection;
}

string InspectionView::removeInspection() {
    string licensePlate = Utils::getString("Vehicle's License Plate");
    return licensePlate;
}