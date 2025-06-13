//
// Created by vitor on 5/20/25.
//

#include <list>
#include "Trip.h"
#include "Utils.h"
#include "TripContainer.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"

using namespace std;

list<Trip>::iterator TripContainer::search(int id) {
  list<Trip>::iterator it = this->trips.begin();
  for(; it != this->trips.end(); ++it) {
    if(it->getID() == id) {
      return it;
    }
  }
  return trips.end();
}

void TripContainer::add(Trip &trip) {
  try{
    list<Trip>::iterator it = this->trips.begin();
    if (it == this->trips.end()) {
      this->trips.push_back(trip);
    }else{
      string msg = "Trip already exists.";
      throw DuplicatedDataException(msg);
    }
  }catch(DuplicatedDataException &error) {
    cout << error.what() << endl;
  }
}

list<Trip> TripContainer::listTrips(){
  std::list<Trip> newList(this->trips);
  return newList;
}

list<Trip> TripContainer::listTripsByDriver(Driver &driver){
  std::list<Trip> driverList;
  std::list<Trip>::iterator it = this->trips.begin();
  for(; it != this->trips.end(); ++it) {
    if(it->getDriver()->getID() == driver.getID()) {
      driverList.push_back(*it);
    }
  }
  return driverList;
}

list<Trip> TripContainer::listTripsByState(STATE state){
  std::list<Trip> trips;
  std::list<Trip>::iterator it = this->trips.begin();
  for(; it != this->trips.end(); ++it){
    if (it->getState() == state){
      trips.push_back(*it);
    }
  }
  return trips;
}

Trip *TripContainer::getTrip(const int id)
{
  try
  {
    list<Trip>::iterator it = search(id);
    if (it != this->trips.end())
    {
      return &(*it);
    }
    throw NonExistingDataException("Trip ID");
  } catch (NonExistingDataException &error)
  {
    cout << error.what() << endl;
  }
  return nullptr;
}

void TripContainer::update(Trip &trip) {
  try {
    list<Trip>::iterator it = search(trip.getID());
    if (it != this->trips.end()) {
      this->trips.erase(it);
      this->trips.push_back(trip);
    }
    else {
      string msg = "Trip: " + to_string(trip.getID());
      throw NonExistingDataException(msg);
    }
  } catch (NonExistingDataException &error) {
    cout << error.what() << endl;
  }
}





