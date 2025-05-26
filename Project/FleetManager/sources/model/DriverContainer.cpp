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
    if ((*it) == id) {
      return it;
    }
  }
  return it;
}

Driver *DriverContainer::get(int id) {
  list<Driver>::iterator it = search(id);
  if(it != this->drivers.end()) {
    return &(*it);
  }
  return NULL;
}

void DriverContainer::add(Driver &driver) {
  list<Driver>::iterator it = search(driver.getId());
  if (it != this->drivers.end()) {
    string msg = "Driver (id): " + to_string(driver.getId());
    throw DuplicatedDataException(msg);
  }
  this->drivers.push_back(driver);
}


void DriverContainer::remove(int id) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    this->drivers.erase(it);
  }
  else if (this->drivers.empty()) {
    string msg = "Driver (id): ";
    throw NonExistingDataException(msg);
  }
  else {
    string msg = "Driver (id): " + to_string(id);
    throw NonExistingDataException(msg);
  }
}

list<Driver> DriverContainer::list() {
  list<Driver> newList(this->drivers);
  return newList;
}

list<Driver> DriverContainer::list(bool available) {
  list<Driver> newList;
  list<Driver>::iterator it = this->drivers.begin();
  for (; it != this->drivers.end(); ++it) {
    if (it->getAvailability() == true) {
      newList.push_back(*it);
    }
  }
  return newList;
}

void DriverContainer::update(int id, const Vacation vacation) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    it->setVacation(vacation);
  }
  else {
    string msg = "Driver(id): " + to_string(id);
    throw NonExistingDataException(msg);
  }
}

void DriverContainer::updateTimeToRetire(int id) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    it->updateTimeToRetire();
  }
  else {
    string msg = "Driver (id): " + to_string(id);
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