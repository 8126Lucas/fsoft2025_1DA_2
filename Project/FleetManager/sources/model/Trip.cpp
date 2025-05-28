//
// Created by vitor on 5/20/25.
//

#include "Trip.h"
#include "TripContainer.h"
#include <Utils.h>

using namespace std;

Trip::Trip() : state(), id(), order(nullptr), driver(nullptr), vehicle(nullptr), kilometers(0), fuel(0), fuelCost(0),
               fines(0),
               cost(0),
               tolls(0) {
}

Trip::Trip(Order *order, double kilometers, double fuel, double fuelCost,double fines, double cost,
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

Driver *Trip::getDriver() {
  return this->driver;
}

Vehicle *Trip::getVehicle() {
  return this->vehicle;
}

void Trip::setState(STATE newState){
  this->state = newState;
}

void Trip::setID(int id) {
  this->id = id;
}

void Trip::setOrder(Order *order) {
  this->order = order;
}

void Trip::setDriver(Driver *driver) {
  this->driver = driver;
}

void Trip::setVehicle(Vehicle *vehicle) {
  this->vehicle = vehicle;
}

void Trip::setKM(double kilometers) {
  this->kilometers = kilometers;
}

void Trip::setFuel(double fuel) {
  this->fuel = fuel;
}

void Trip::setFuelCost(double fuelCost) {
  this->fuelCost = fuelCost;
}

void Trip::setFines(double fines) {
  this->fines = fines;
}

void Trip::setCost(double cost) {
this->cost = cost;
}

void Trip::setTolls(double tolls) {
  this->tolls = tolls;
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

double Trip::getCost(){
  return cost;
}





