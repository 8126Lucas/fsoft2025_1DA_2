//
// Created by Vitor on 25/05/2025.
//
#include <iostream>
#include "Trip.h"
#include "TripContainer.h"
#include "TripView.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"

using namespace std;

Trip TripView::addTrip(OrderContainer &containerOrder) {
    Trip trip = Trip();
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int tripID = Utils::getInt("Trip ID");
            Order *order = Utils::getOrder(containerOrder , "Order ID");
            double cost = Utils::getDouble("Cost");
            trip.setState(SUPRESSED);
            trip.setID(tripID);
            trip.setOrder(order);
            trip.setDriver(nullptr);
            trip.setVehicle(nullptr);
            trip.setKM(0);
            trip.setFuel(0);
            trip.setFuelCost(0);
            trip.setFines(0);
            trip.setTolls(0);
            trip.setCost(cost);
        }catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    }while (flag_error);
    return trip;
}

Trip *TripView::getTrip(TripContainer *container){
    int id = getId();
    Trip *trip = container->getTrip(id);
    return trip;
}

int TripView::getId(){
    int id = Utils::getInt("Trip ID");
    return id;
}

void TripView::printTrip(Trip *trip){
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Trip " << trip->getID() << " *** \n";
            cout << "Distance: " << trip->getKM() <<" KM \n";
            cout << "Fuel: " << trip->getFuel() << "\n";
            cout << "Tolls: " << trip->getTolls() << "€ \n";
            cout << "Fuel Cost: " << trip->getFuelCost() << "€\n";
            cout << "Total Cost: " << trip->getCost() << "€\n";
        } catch(NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    }while(flag_error);
}

void TripView::printListTrips(list<Trip> &trips) {
    if (trips.empty()) {
        cout << "Trip list is empty.\n";
    }else {
        cout << "\n*** List of Trips: " << trips.size() << " ***\n\n";
        list<Trip>::iterator it = trips.begin();
        for (; it != trips.end(); ++it) {
            printTrip(&*it);
        }
        cout << "\n\n";
    }

}



void TripView::startTrip(TripContainer &containerTrip, DriverContainer &containerDriver, VehicleContainer &containerVehicle) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            Trip *trip = Utils::getTrip(containerTrip, "Trip ID");
            if (trip == nullptr) {
                throw NonExistingDataException();
            }
            Driver *driver = Utils::getDriver(containerDriver , "Driver ID");
            if (driver == nullptr) {
                throw NonExistingDataException();
            }
            if (driver != nullptr && driver->getAvailability() == false) {
                throw InvalidDataException("Driver is not available. ID");
            }
            double fuel = Utils::getDouble("Fuel Spent (%)");
            Vehicle *vehicle = Utils::getVehicle(containerVehicle , "Vehicle's License Plate");

            if (vehicle != nullptr && fuel > vehicle->getFuel()) {
                throw InvalidDataException("Vehicle does not have enough fuel. License Plate");
            }
            if (driver != nullptr && vehicle != nullptr && (driver->getLicense() == 'B' && vehicle->getCategory() == TRUCK
                || driver->getLicense() == 'C' && vehicle->getCategory() == VAN)) {
                throw InvalidDataException("Driver is not equipped for this Trip. License");
            }
            if (vehicle != nullptr && vehicle->getAvailability() == false ) {
                throw InvalidDataException("Vehicle is not available. License Plate");
            }

            trip->setState(INCOMING);
            trip->setFuel(fuel);
            trip->setVehicle(vehicle);
            trip->setDriver(driver);
            driver->setAvailability(false);
            vehicle->setAvailability(false);
        }catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }catch (NonExistingDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    }while (flag_error);
}

void TripView::endTrip(TripContainer &containerTrip, DriverContainer &containerDriver, VehicleContainer &containerVehicle) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            Trip *trip = Utils::getTrip(containerTrip, "Trip ID");
            double km = Utils::getDouble("Kilometers");

            double fuelCost = Utils::getDouble("Fuel Cost (€)");
            double fines = Utils::getDouble("Fines (€)");
            double tolls = Utils::getDouble("Tolls (€)");
            trip->setState(DELIVERED);
            trip->setKM(km);
            trip->setFuelCost(fuelCost);
            trip->setFines(fines);
            trip->setTolls(tolls);

            trip->getVehicle()->setAvailability(true);
            trip->getDriver()->setAvailability(true);
        }catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    }while (flag_error);
}

void TripView::failTrip(Trip *trip) {
    bool flag_error = false;
    do {
        try {
            trip->setState(FAILED);
            trip->setCost(trip->getCost() * 1.05);
            if (trip->getVehicle() != nullptr && trip->getDriver() != nullptr) {
                trip->getVehicle()->setAvailability(true);
                trip->getDriver()->setAvailability(true);
            }
        }catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }

    }while (flag_error);
}