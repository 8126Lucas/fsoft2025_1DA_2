//
// Created by lucas on 02/06/2025.
//

#ifndef HEADERS_SERIAL_VEHICLESERIALIZATION_H
#define HEADERS_SERIAL_VEHICLESERIALIZATION_H
#include <nlohmann/json.hpp>
#include "Insurance.h"
#include "Inspection.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Van.h"
#include "VehicleView.h"
#include "VSLContainer.h"

using namespace nlohmann;

void toJson(json &j, const CATEGORY &category) {
    switch (category) {
        case TRUCK:
            j = "TRUCK";
            break;
        case VAN:
            j = "VAN";
            break;
    }
}

void fromJson(const json &j, CATEGORY &category) {
    string stringCategory = j.get<string>();
    if (stringCategory == "TRUCK") {category = TRUCK;}
    else {category = VAN;}
}

void toJson(json &j, const Vehicle &vehicle) {
    j["category"] = vehicle.getCategory();
    j["brand"] = vehicle.getBrand();
    j["model"] = vehicle.getModel();
    j["year"] = vehicle.getYear();
    j["licensePlate"] = vehicle.getLicensePlate();
    j["mileage"] = vehicle.getMileage();
    j["fuel"] = vehicle.getFuel();
    j["available"] = vehicle.getAvailability();
    if (vehicle.getInsurance() != nullptr) {
        j["insuranceID"] = vehicle.getInsurance()->getID();
        j["insuranceStartDate"] = vehicle.getInsurance()->getStartDate();
        j["insuranceEndDate"] = vehicle.getInsurance()->getEndDate();
        j["insuranceMonthlyCost"] = vehicle.getInsurance()->getMonthlyCost();
        j["insuranceToday"] = vehicle.getInsurance()->getToday();
    }
    else {
        j["insuranceID"] = -1;
        j["insuranceStartDate"] = "no date";
        j["insuranceEndDate"] = "no date";
        j["insuranceMonthlyCost"] = -1;
        j["insuranceToday"] = "no date";
    }
    if (vehicle.getInspection != nullptr) {
        j["inspectionID"] = vehicle.getInspection()->getID();
        j["inspectionDate"] = vehicle.getInspection()->getDate();
        j["inspectionCost"] = vehicle.getInspection()->getCost();
        j["inspectionToday"] = vehicle.getInspection()->getToday();
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

void fromJson(const json &j, Vehicle &vehicle) {
    vehicle.setCategory(j["category"]);
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
        insurance->setStartDate(j["insuranceStartDate"]);
        insurance->setEndDate(j["insuranceEndDate"]);
        insurance->setMonthlyCost(j["insuranceMonthlyCost"]);
        insurance->setToday(j["insuranceToday"]);
    }
    if (j["inspectionID"] != -1) {
        Inspection *inspection = new Inspection();
        inspection->setID(j["inspectionID"]);
        inspection->setDate(j["inspectionDate"]);
        inspection->setCost(j["inspectionCost"]);
        inspection->setToday(j["inspectionToday"]);
    }
    // if (j["vslID"] != -1) {
    //     VehicleStorageLocation *vsl = new VehicleStorageLocation();
    //     vehicle.setVSL())
    // }
}

void toJson(json &j, const Truck &truck) {
    toJson(j, static_cast<const Vehicle &>(truck));
    j["weightCapacity"] = truck.getWeightCapacity();
}

void fromJson(const json &j, Truck &truck) {
    fromJson(j, static_cast<Vehicle &>(truck));
    truck.setWeightCapacity(j["weightCapacity"]);
}

void toJson(json &j, const Van &van) {
    toJson(j, static_cast<const Vehicle &>(van));
    j["spaceCapacity"] = van.getSpaceCapacity();
}

void fromJson(const json &j, Van &van) {
    fromJson(j, static_cast<Vehicle &>(van));
    van.setSpaceCapacity(j["weightCapacity"]);
}





#endif //HEADERS_SERIAL_VEHICLESERIALIZATION_H
