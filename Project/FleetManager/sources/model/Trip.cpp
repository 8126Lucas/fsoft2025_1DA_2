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

Order *Trip::getOrder() const {
  return this->order;
}

int Trip::getID() const {
  return this->id;
}

STATE Trip::getState() const{
  return this->state;
}

Driver *Trip::getDriver() const{
  return this->driver;
}

Vehicle *Trip::getVehicle() const{
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

double Trip::getKM() const{
  return kilometers;
}

double Trip::getFines() const{
  return fines;
}

double Trip::getTolls() const{
  return tolls;
}

double Trip::getFuelCost() const{
  return fuelCost;
}

double Trip::getFuel() const
{
  return fuel;
}

double Trip::getCost() const{
  return cost;
}





