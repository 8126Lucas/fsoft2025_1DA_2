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
  list<Driver>::iterator it = search(driver);
  if (it != this->drivers.end()) {
    this->drivers.push_back(driver);
  }
  else {
    string msg = "Driver: " + driver.getId();
    throw DuplicatedDataException(msg);
  }
}

void DriverContainer::remove(int id) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    this->drivers.erase(it);
  }
  else {
    string msg = "Driver: " + id;
    throw NonExistingDataException(msg);
  }
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
//update da vacation