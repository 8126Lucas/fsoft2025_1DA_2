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

Trip TripView::addTrip(){
    Trip trip = utils::setTrip();
    return trip;
}

Trip Tripview::getTrip(TripContainer *container){
    int id = getId();
    Trip trip = container->getTrip(id);
    return trip;
}

int getId(){
    int id = Utils::getId("TripID");
    return id;
}

void TripView::printTrip(const Trip *trip){
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Trip " << trip->getId() << " *** \n";
            cout << "Distance: " << trip->getKM() <<" KM \n";
            cout << "Fuel: " << trip->getFuel() << "\n";
            cout << "Tolls: " << trip->getTolls() << "€ \n";
            cout << "Fuel Cost: " << trip->getFuelCost() << "€\n";
            cout << "Total Cost: " << trip->calculateCost() << "€\n";
        } catch(NonExistingDataException &error) {
            flag_error = true;
        }
    }while(flag_error);
}

