//
// Created by vitor on 5/20/25.
//

#include "Trip.h"
#include "TripContainer.h"
#include <Utils.h>

using namespace std;

int Trip::getID() {
  return this->id;
}

STATE Trip::getState(){
  return this->state;
}

void Trip::setState(STATE s){
  this->state = s; //Valor do estado que for inserido
}

void Trip::startTrip(Trip &trip) {
  trip.state = INCOMING;
}

void Trip::completeTrip(Trip &trip){
  trip.state = DELIVERED;
}




