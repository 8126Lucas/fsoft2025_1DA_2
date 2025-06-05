//
// Created by lucas on 17/05/2025.
//

#include "Vehicle.h"

#include "InvalidDataException.h"
#include "Truck.h"
#include "Utils.h"
#include "Van.h"
#include "VehicleContainer.h"
#include "VehicleView.h"

Vehicle::Vehicle() : category(), year(0), mileage(0), fuel(0), available(true) {
}

Vehicle::Vehicle(const CATEGORY category, const string &brand, const string &model, const int year,
                 const string &licensePlate, double mileage, double fuel, bool available) {
    this->category = category;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->licensePlate = licensePlate;
    this->mileage = mileage;
    this->fuel = fuel;
    this->available = available;
}

Vehicle::~Vehicle() {
    delete inspection;
    delete insurance;
}

CATEGORY Vehicle::getCategory() const {
    return category;
}

string Vehicle::getBrand() const {
    return brand;
}

string Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

string Vehicle::getLicensePlate() const {
    return licensePlate;
}

double Vehicle::getMileage() const {
    return mileage;
}

double Vehicle::getFuel() const {
    return fuel;
}

bool Vehicle::getAvailability() const {
    return available;
}
Insurance *Vehicle::getInsurance() const {
    return insurance;
}

Inspection *Vehicle::getInspection() const {
    return inspection;
}

VehicleStorageLocation *Vehicle::getVSL() const {
    return vsl;
}

int Vehicle::getInsuranceID() const {
    return insurance->getID();
}

int Vehicle::getInspectionID() const {
    return inspection->getID();
}

int Vehicle::getVSLID() const {
    return vsl->getID();
}

void Vehicle::setCategory(const CATEGORY category) {
    this->category = category;
}

void Vehicle::setBrand(const string &brand) {
    this->brand = brand;
}

void Vehicle::setModel(const string &model) {
    this->model = model;
}

void Vehicle::setYear(const int year) {
    this->year = year;
}

void Vehicle::setLicensePlate(const string &licensePlate) {
    this->licensePlate = licensePlate;
}

void Vehicle::setMileage(const double mileage) {
    this->mileage = mileage;
}

void Vehicle::setFuel(const double fuel) {
    this->fuel = fuel;
}

void Vehicle::setInsurance(Insurance *insurance) {
    this->insurance = insurance;
}

void Vehicle::setInspection(Inspection *inspection) {
    this->inspection = inspection;

}

void Vehicle::setVSL(VehicleStorageLocation *vsl) {
    this->vsl = vsl;
}

void Vehicle::setAvailability(bool available) {
    this->available = available;
}

void Vehicle::addFuel(double addedFuel) {
    this->fuel += addedFuel;
}

bool Vehicle::isFuelEnough(Trip &trip) {
    if (this->fuel > trip.getFuel()) {return true;}
    return false;
}

void Vehicle::updateMileage(Trip &trip) {
    this->mileage += trip.getKM();
}

void Vehicle::insuranceAlert() {
    if (this->insurance->isExpired()) {
        if (Truck *truck = dynamic_cast<Truck *>(this)) {
            VehicleView::insuranceAlert(truck);
        }
        else if (Van *van = dynamic_cast<Van *>(this)) {
            VehicleView::insuranceAlert(van);
        }
    }
}

void Vehicle::inspectionAlert() {
    if (this->insurance->isExpired()) {
        if (Truck *truck = dynamic_cast<Truck *>(this)) {
            VehicleView::inspectionAlert(truck);
        }
        else if (Van *van = dynamic_cast<Van *>(this)) {
            VehicleView::inspectionAlert(van);
        }
    }
}

void Vehicle::fuelAlert(Trip &trip) {
    if (!this->isFuelEnough(trip)) {
        if (Truck *truck = dynamic_cast<Truck *>(this)) {
            VehicleView::inspectionAlert(truck);
        }
        else if (Van *van = dynamic_cast<Van *>(this)) {
            VehicleView::inspectionAlert(van);
        }
    }
}


bool Vehicle::isAvailable() const {
    if (this->available) {return true;}
    return false;
}
