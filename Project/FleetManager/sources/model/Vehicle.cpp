//
// Created by lucas on 17/05/2025.
//

#include "Vehicle.h"
#include "Utils.h"
#include "VehicleContainer.h"
#include "VehicleView.h"

Vehicle::Vehicle() : category(), year(0), mileage(0), fuel(0), available(true) {
}

Vehicle::Vehicle(const CATEGORY category, const string &brand, const string &model, const int year,
                 const string &licensePlate, const double mileage, const double fuel,
                 const bool available) {
    this->category = category;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->licensePlate = licensePlate;
    this->mileage = mileage;
    this->fuel = fuel;
    this->available = available;
}

Vehicle::~Vehicle() {}


void Vehicle::addVehicle() {
    Vehicle vehicle = VehicleView::getVehicle();
    VehicleContainer::add(vehicle);
}

void Vehicle::removeVehicle() {
    string licensePlate = VehicleView::getLicensePlate();
    VehicleContainer::remove(licensePlate);
}

string &Vehicle::getLicensePlate() {
    return licensePlate;
}

bool Vehicle::getAvailability() const {
    return available;
}

void Vehicle::setInsurance(const Insurance insurance) {
    this->insurance = insurance;
}

void Vehicle::setInspection(const Inspection inspection) {
    this->inspection = inspection;
}

void Vehicle::setVSL(const VehicleStorageLocation vsl) {
    this->vsl = vsl;
}

