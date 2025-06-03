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
        j["insuranceEndDate"] = vehicle.getInsurance()->getEndDate();
        j["insuranceMonthlyCost"] = vehicle.getInsurance()->getMonthlyCost();
    }
    else {
        j["insuranceID"] = -1;
        j["insuranceEndDate"] = "no date";
        j["insuranceMonthlyCost"] = -1;
    }
    if (vehicle.getInspection != nullptr) {
        j["inspectionID"] = vehicle.getInspection()->getID();
        j["inspectionDate"] = vehicle.getInspection()->getDate();
        j["inspectionCost"] = vehicle.getInspection()->getCost();
    }
    else {
        j["inspectionID"] = -1;
        j["inspectionDate"] = "no date";
        j["inspectionCost"] = -1;
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
