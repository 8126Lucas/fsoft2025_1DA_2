//
// Created by lucas on 07/06/2025.
//

#include "DataContainer.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include "NonExistingDataException.h"

// Por fazer DataContainer::DataContainer() {}

void DataContainer::loadVehicles() {
    ifstream file(vehicleFilePath);
    try {
        if (!file.is_open()) {throw NonExistingDataException("Vehicle JSON File");}
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    json j;
    file >> j;
    VehicleSerialization serializer;
    if (j.contains("trucks")) {
        for (const basic_json<> &truckJSON : j["trucks"]) {
            Truck truck;
            serializer.fromJSON(truckJSON, truck);
            containerVehicle->add(truck);
        }
    }
    if (j.contains("vans")) {
        for (const basic_json<> &vanJSON : j["vans"]) {
            Van van;
            serializer.fromJSON(vanJSON, van);
            containerVehicle->add(van);
        }
    }
    file.close();
}

void DataContainer::loadVSLs() {
    ifstream file(vslFilePath);
    try {
        if (!file.is_open()) {throw NonExistingDataException("Vehicle Storage Location JSON File");}
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    json j;
    file >> j;
    VehicleStorageLocationSerialization serializer;
    if (j.contains("vsls")) {
        for (const basic_json<> &vslJSON : j["vsls"]) {
            VehicleStorageLocation vsl;
            serializer.fromJSON(vslJSON, vsl);
            containerVSL->add(vsl);
        }
    }
    file.close();
}

void DataContainer::loadDrivers() {
    ifstream file(driverFilePath);
    try {
        if (!file.is_open()) {throw NonExistingDataException("Driver JSON File");}
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    json j;
    file >> j;
    DriverSerialization serializer;
    if (j.contains("drivers")) {
        for (const basic_json<> &driverJSON : j["drivers"]) {
            Driver driver;
            serializer.fromJSON(driverJSON, driver);
            containerDriver->add(driver);
        }
    }
    file.close();
}

void DataContainer::loadFinancials() {
    ifstream file(financialFilePath);
    try {
        if (!file.is_open()) {throw NonExistingDataException("Financial JSON File");}
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    json j;
    file >> j;
    FinancialSerialization serializer;
    if (j.contains("expenses")) {
        for (const basic_json<> &expenseJSON : j["expenses"]) {
            Expense expense;
            serializer.fromJSON(expenseJSON, expense);
            containerFinancial->addExpense(expense);
        }
    }
    if (j.contains("revenues")) {
        for (const basic_json<> &revenueJSON : j["revenues"]) {
            Revenue revenue;
            serializer.fromJSON(revenueJSON, revenue);
            containerFinancial->addRevenue(revenue);
        }
    }
    file.close();
}

void DataContainer::loadTrips() {
    ifstream file(tripFilePath);
    try {
        if (!file.is_open()) {throw NonExistingDataException("Trip JSON File");}
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    json j;
    file >> j;
    TripSerialization serializer;
    if (j.contains("trips")) {
        for (const basic_json<> &tripJSON : j["trips"]) {
            Trip trip;
            serializer.fromJSON(tripJSON, trip);
            containerTrip->add(trip);
        }
    }
    file.close();
}

void DataContainer::loadOrders() {
    ifstream file(orderFilePath);
    try {
        if (!file.is_open()) {throw NonExistingDataException("Order JSON File");}
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
    json j;
    file >> j;
    OrderSerialization serializer;
    if (j.contains("orders")) {
        for (const basic_json<> &orderJSON : j["orders"]) {
            Order order;
            serializer.fromJSON(orderJSON, order);
            containerOrder->add(order);
        }
    }
    file.close();
}


void DataContainer::loadAllData() {
    loadVehicles();
    loadVSLs();
    loadDrivers();
    loadFinancials();
    loadTrips();
    loadOrders();
}

void DataContainer::saveAllData() {
    VehicleSerialization serializerVehicle;
    VehicleStorageLocationSerialization serializerVSL;
    DriverSerialization serializerDriver;
    FinancialSerialization serializerFinancial;
    TripSerialization serializerTrip;
    OrderSerialization serializerOrder;

    json dataVehicle;
    json truckArray = json::array();
    for (const Truck &truck : containerVehicle->listTrucks()) {
        json truckJSON;
        serializerVehicle.toJSON(truckJSON, truck);
        truckArray.push_back(truckJSON);
    }
    dataVehicle["trucks"] = truckArray;
    json vanArray = json::array();
    for (const Van &van : containerVehicle->listVans()) {
        json vanJSON;
        serializerVehicle.toJSON(vanJSON, van);
        vanArray.push_back(vanJSON);
    }
    dataVehicle["vans"] = vanArray;

    ofstream vehicleOutputFile(vehicleFilePath);
    try {
        if (!vehicleOutputFile.is_open()) {
            throw NonExistingDataException("Vehicle JSON File");
        }
        vehicleOutputFile << setw(4) << dataVehicle << endl;
        vehicleOutputFile.close();
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }

    json dataVSL;
    json vslArray = json::array();
    for (const VehicleStorageLocation &vsl : containerVSL->listVSL()) {
        json vslJSON;
        serializerVSL.toJSON(vslJSON, vsl);
        vslArray.push_back(vslJSON);
    }
    dataVSL["vsls"] = vslArray;

    ofstream vslOutputFile(vslFilePath);
    try {
        if (!vslOutputFile.is_open()) {
            throw NonExistingDataException("Vehicle Storage Location JSON File");
        }
        vslOutputFile << setw(4) << dataVSL << endl;
        vslOutputFile.close();
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }

    json dataDriver;
    json driverArray = json::array();
    for (const Driver &driver : containerDriver->listDrivers()) {
        json driverJSON;
        serializerDriver.toJSON(driverJSON, driver);
        driverArray.push_back(driverJSON);
    }
    dataDriver["drivers"] = driverArray;

    ofstream driverOutputFile(driverFilePath);
    try {
        if (!driverOutputFile.is_open()) {
            throw NonExistingDataException("Driver JSON File");
        }
        driverOutputFile << setw(4) << dataDriver << endl;
        driverOutputFile.close();
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }

    json dataFinancial;
    json expenseArray = json::array();
    for (const Expense &expense : containerFinancial->listExpense()) {
        json expenseJSON;
        serializerFinancial.toJSON(expenseJSON, expense);
        expenseArray.push_back(expenseJSON);
    }
    dataFinancial["expenses"] = expenseArray;
    json revenueArray = json::array();
    for (const Revenue &revenue : containerFinancial->listRevenue()) {
        json revenueJSON;
        serializerFinancial.toJSON(revenueJSON, revenue);
        revenueArray.push_back(revenueJSON);
    }
    dataFinancial["revenues"] = revenueArray;

    ofstream financialOutputFile(financialFilePath);
    try {
        if (!financialOutputFile.is_open()) {
            throw NonExistingDataException("Financial JSON File");
        }
        financialOutputFile << setw(4) << dataFinancial << endl;
        financialOutputFile.close();
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }

    json dataTrip;
    json tripArray = json::array();
    for (const Trip &trip : containerTrip->listTrips()) {
        json tripJSON;
        serializerTrip.toJSON(tripJSON, trip);
        tripArray.push_back(tripJSON);
    }
    dataTrip["trips"] = tripArray;

    ofstream tripOutputFile(tripFilePath);
    try {
        if (!tripOutputFile.is_open()) {
            throw NonExistingDataException("Trip JSON File");
        }
        tripOutputFile << setw(4) << dataTrip << endl;
        tripOutputFile.close();
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }

    json dataOrder;
    json orderArray = json::array();
    for (const Order &order : containerOrder->listOrders()) {
        json orderJSON;
        serializerOrder.toJSON(orderJSON, order);
        orderArray.push_back(orderJSON);
    }
    dataOrder["orders"] = orderArray;

    ofstream orderOutputFile(orderFilePath);
    try {
        if (!orderOutputFile.is_open()) {
            throw NonExistingDataException("Order JSON File");
        }
        orderOutputFile << setw(4) << dataOrder << endl;
        orderOutputFile.close();
    } catch (NonExistingDataException &error) {
        cout << error.what() << endl;
    }
}