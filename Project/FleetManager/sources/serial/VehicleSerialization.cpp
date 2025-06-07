//
// Created by lucas on 02/06/2025.
//

#include "VehicleSerialization.h"
#include "Inspection.h"
#include "Insurance.h"

void VehicleSerialization::toJSON(json &j, const CATEGORY &category) {
    switch (category) {
        case TRUCK:
            j["category"] = "TRUCK";
            break;
        case VAN:
            j["category"] = "VAN";
            break;
    }
}

CATEGORY VehicleSerialization::fromJSON(const json &j) {
    string stringCategory = j["category"].get<string>();
    CATEGORY category;
    if (stringCategory == "TRUCK") {category = TRUCK;}
    else {category = VAN;}
    return category;
}

void VehicleSerialization::toJSON(json &j, const Vehicle &vehicle) {
    toJSON(j, vehicle.getCategory());
    j["brand"] = vehicle.getBrand();
    j["model"] = vehicle.getModel();
    j["year"] = vehicle.getYear();
    j["licensePlate"] = vehicle.getLicensePlate();
    j["mileage"] = vehicle.getMileage();
    j["fuel"] = vehicle.getFuel();
    j["available"] = vehicle.getAvailability();
    if (vehicle.getInsurance() != nullptr) {
        j["insuranceID"] = vehicle.getInsurance()->getID();
        string string_startDate = vehicle.getInsurance()->getStartDate().dateToString();
        j["insuranceStartDate"] = string_startDate;
        string string_endDate = vehicle.getInsurance()->getEndDate().dateToString();
        j["insuranceEndDate"] = string_endDate;
        j["insuranceMonthlyCost"] = vehicle.getInsurance()->getMonthlyCost();
        string string_today = vehicle.getInsurance()->getToday().dateToString();
        j["insuranceToday"] = string_today;
    }
    else {
        j["insuranceID"] = -1;
        j["insuranceStartDate"] = "no date";
        j["insuranceEndDate"] = "no date";
        j["insuranceMonthlyCost"] = -1;
        j["insuranceToday"] = "no date";
    }
    if (vehicle.getInspection() != nullptr) {
        j["inspectionID"] = vehicle.getInspection()->getID();
        string string_date = vehicle.getInspection()->getDate().dateToString();
        j["inspectionDate"] = string_date;
        j["inspectionCost"] = vehicle.getInspection()->getCost();
        string string_today = vehicle.getInspection()->getToday().dateToString();
        j["inspectionToday"] = string_today;
    }
    else {
        j["inspectionID"] = -1;
        j["inspectionDate"] = "no date";
        j["inspectionCost"] = -1;
        j["inspectionToday"] = "no date";
    }
    if (vehicle.getVSL() != nullptr) {j["vslID"] = vehicle.getVSL()->getID();}
    else {j["vslID"] = -1;}
}

void VehicleSerialization::fromJSON(const json &j, Vehicle &vehicle) {
    vehicle.setCategory(fromJSON(j));
    vehicle.setBrand(j["brand"]);
    vehicle.setModel(j["model"]);
    vehicle.setYear(j["year"]);
    vehicle.setLicensePlate(j["licensePlate"]);
    vehicle.setMileage(j["mileage"]);
    vehicle.setFuel(j["fuel"]);
    vehicle.setAvailability(j["available"]);
    if (j["insuranceID"] != -1) {
        Insurance *insurance = new Insurance();
        insurance->setID(j["insuranceID"]);
        Date date_startDate = date_startDate.stringToDate(j["insuranceStartDate"]);
        insurance->setStartDate(date_startDate);
        Date date_endDate = date_endDate.stringToDate(j["insuranceEndDate"]);
        insurance->setEndDate(date_endDate);
        insurance->setMonthlyCost(j["insuranceMonthlyCost"]);
        Date date_today = date_today.stringToDate(j["insuranceToday"]);
        insurance->setToday(date_today);
        vehicle.setInsurance(insurance);
    }
    else {vehicle.setInsurance(nullptr);}
    if (j["inspectionID"] != -1) {
        Inspection *inspection = new Inspection();
        inspection->setID(j["inspectionID"]);
        Date date_date = date_date.stringToDate(j["inspectionDate"]);
        inspection->setDate(date_date);
        inspection->setCost(j["inspectionCost"]);
        Date date_today = date_today.stringToDate(j["inspectionToday"]);
        inspection->setToday(date_today);
        vehicle.setInspection(inspection);
    }
    else {vehicle.setInspection(nullptr);}
    if (j["vslID"] != -1) {
        vehicle.setVSL(nullptr);
    }
    else {vehicle.setVSL(nullptr);}
}

void VehicleSerialization::toJSON(json &j, const Truck &truck) {
    toJSON(j, static_cast<const Vehicle &>(truck));
    j["weightCapacity"] = truck.getWeightCapacity();
}

void VehicleSerialization::fromJSON(const json &j, Truck &truck) {
    fromJSON(j, static_cast<Vehicle &>(truck));
    truck.setWeightCapacity(j["weightCapacity"]);
}

void VehicleSerialization::toJSON(json &j, const Van &van) {
    toJSON(j, static_cast<const Vehicle &>(van));
    j["spaceCapacity"] = van.getSpaceCapacity();
}

void VehicleSerialization::fromJSON(const json &j, Van &van) {
    fromJSON(j, static_cast<Vehicle &>(van));
    van.setSpaceCapacity(j["spaceCapacity"]);
}
