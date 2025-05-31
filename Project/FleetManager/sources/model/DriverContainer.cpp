//
// Created by ruben on 19/05/2025.
//

#include "DriverContainer.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"

list<Driver>::iterator DriverContainer::search(int id) {
  list<Driver>::iterator it = this->drivers.begin();
  for (; it != this->drivers.end(); ++it) {
    if (it->getID() == id) {
      return it;
    }
  }
  return drivers.end();
}

Driver *DriverContainer::get(int id) {
  list<Driver>::iterator it = search(id);
  if(it != this->drivers.end()) {
    return &(*it);
  }
  throw NonExistingDataException("Driver ID");
}

void DriverContainer::add(Driver &driver) {
  list<Driver>::iterator it = search(driver.getID());
  if (it != this->drivers.end()) {
    string msg = "Driver (id): " + to_string(driver.getID());
    throw DuplicatedDataException(msg);
  }
  this->drivers.push_back(driver);
}


void DriverContainer::remove(int id) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    this->drivers.erase(it);
  }
  else {
    string msg = "Driver (id): " + to_string(id);
    throw NonExistingDataException(msg);
  }
}

list<Driver> DriverContainer::listDrivers() {
  list<Driver> newList(this->drivers);
  return newList;
}

list<Driver> DriverContainer::listAvailableDrivers(bool available) {
  list<Driver> newList;
  list<Driver>::iterator it = this->drivers.begin();
  for (; it != this->drivers.end(); ++it) {
    if (it->getAvailability() == available) {
      newList.push_back(*it);
    }
  }
  return newList;
}

void DriverContainer::update(int id, Vacation vacation) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    it->getVacations().push_back(&vacation);
  }
  else {
    string msg = "Driver(id): " + to_string(id);
    throw NonExistingDataException(msg);
  }
}

void DriverContainer::updateAvailability(int id, bool available) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    it->setAvailability(available);
  }
  else {
    string msg = "Driver (id): " + id;
    throw NonExistingDataException(msg);
  }
}