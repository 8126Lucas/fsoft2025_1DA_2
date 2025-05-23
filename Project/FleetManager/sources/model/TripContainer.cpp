//
// Created by vitor on 5/20/25.
//

#include <list>
#include "Trip.h"
#include "Utils.h"
#include "TripContainer.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"

using namespace std;

list<Trip>::iterator TripContainer::search(int id) {
  std::list<Trip>::iterator it = this->trips.begin();
  for(; it != this->trips.end(); ++it) {
    if((*it) == id) {
      return it; // foi encontrado o ID
    }
  }
};

void TripContainer::add(Trip &trip) {
    std::list<Trip>::iterator it = this->trips.begin();
    if (it == this->trips.end()) {
      this->trips.push_back(trip);
    }else{
      string msg = "Trip already exists.";
      throw DuplicatedDataException(msg);
      }
};

void TripContainer::complete(Trip &trip) {
  trip.setState(DELIVERED);
}

void TripContainer::start(Trip &trip) {
  trip.setState(INCOMING);
};

void TripContainer::failed(Trip &trip) {
  trip.setState(FAILED);
}

list<Trip> TripContainer::list(){
  std::list<Trip> newList(this->trips);
  return newList;
}

list<Trip> TripContainer::list(Driver &driver){
  std::list<Trip> driverList;
  std::list<Trip>::iterator it = this->trips.begin();
  for(; it != this->trips.end(); ++it) {
    if(*it == driver.getId()) {
      driverList.push_back(*it);
    }
  }
  return driverList;
}

list<Trip> TripContainer::list(STATE state){
  std::list<Trip> Trips;
  std::list<Trip>::iterator it = search(state);
  for(; it != this->trips.end(); ++it){
    if (it->getState() == state){
      Trips.push_back(*it);}
  }
}

/*void TripContainer::updateState(int id, STATE newState)  --
{
  list<Trip>::iterator it = search(id);
  if (it != this->trips.end())
  {
    it->setState(newState);
  }else{
    string msg = "Trip does not exists.";
  }
}*/





