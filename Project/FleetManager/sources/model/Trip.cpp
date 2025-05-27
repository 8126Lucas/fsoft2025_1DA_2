//
// Created by vitor on 5/20/25.
//

#include "Trip.h"
#include "TripContainer.h"
#include <Utils.h>

using namespace std;

Trip::Trip() :  id(), kilometers(0), fuel(0) {
}

Trip::Trip(Order order, double kilometers, double fuel, double fuelCost,double fines, double cost,
       double tolls){

  this->order = order;
  this->kilometers = kilometers;
  this->fuel = fuel;
  this->fuelCost = fuelCost;
  this->fines = fines;
  this->cost = cost;
  this->tolls = tolls;

}

Trip::~Trip() {}

int Trip::getID() {
  return this->id;
}

STATE Trip::getState(){
  return this->state;
}

Driver Trip::getDriver() {
  Driver driver;
  return driver;
}

void Trip::setState(STATE newState){
  this->state = newState; //Valor do estado que for inserido
}

void Trip::createTrip(Trip &Trip)
{

}
void Trip::startTrip(Trip &trip) {
  trip.state = INCOMING;
}

void Trip::completeTrip(Trip &trip){
  trip.state = DELIVERED;
}

void Trip::failedTrip(Trip &trip){
  trip.state = FAILED;
}

double Trip::getKM() {
  return kilometers;
}

double Trip::getFines(){
  return fines;
}

double Trip::getTolls(){
  return tolls;
}

double Trip::getFuelCost(){
  return fuelCost;
}

double Trip::getFuel()
{
  return fuel;
}

double Trip::calculateCost(){
  return cost;
}




