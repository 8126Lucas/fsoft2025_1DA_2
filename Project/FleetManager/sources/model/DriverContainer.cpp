//
// Created by ruben on 19/05/2025.
//

#include "DriverContainer.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
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
  try {
    if (driver.getID() < 0 || driver.getID() == 0) {
      throw InvalidDataException("Driver (id): " + to_string(driver.getID()));
    }
    list<Driver>::iterator it = search(driver.getID());
    if (it != this->drivers.end()) {
      throw DuplicatedDataException("Driver (id): " + to_string(driver.getID()));
    }
    this->drivers.push_back(driver);
  } catch (DuplicatedDataException &error) {
    cout << error.what() << endl;
  }
}


void DriverContainer::remove(int id) {
  try
  {
      if (id <= 0) {
        throw InvalidDataException("Driver (id): " + to_string(id));
      }
      list<Driver>::iterator it = search(id);
      if (it != this->drivers.end()) {
        this->drivers.erase(it);
      } else {
        throw NonExistingDataException("Driver (id): " + to_string(id));
      }
  } catch (NonExistingDataException &error)
      {
        cout << error.what() << endl;
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

void DriverContainer::addVacation(Vacation *vacation) {
  try {
    if (vacation->getID() <= 0) {
      throw InvalidDataException("Vacation (id): " + to_string(vacation->getID()));
    }

    Driver* vacationDriver = vacation->getDriver();
    if (vacationDriver == nullptr) {
      throw InvalidDataException("Vacation (id): " + to_string(vacation->getID()));
    }

    list<Driver>::iterator driverIt = search(vacationDriver->getID());
    if (driverIt == drivers.end()) {
      throw NonExistingDataException("Driver (id): " + to_string(vacationDriver->getID()));
    }

    list<Vacation*>::const_iterator it = driverIt->getVacations().begin();
    for (; it != driverIt->getVacations().end(); ++it) {
      if (*it != nullptr) {
        if ((*it)->getID() == vacation->getID()) {
          throw DuplicatedDataException("Vacation (id): " + to_string(vacation->getID()));
        }
      }
    }

    driverIt->setVacation(vacation);

  } catch (DuplicatedDataException &error) {
    cout << error.what() << endl;
  }
}

void DriverContainer::update(int id, Vacation *vacation) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    it->getVacations().push_back(vacation);
  } else {
    throw NonExistingDataException("Driver(id): " + to_string(id));
  }
}

void DriverContainer::updateAvailability(int id, bool available) {
  list<Driver>::iterator it = search(id);
  if (it != this->drivers.end()) {
    it->setAvailability(available);
  } else {
    throw NonExistingDataException("Driver (id): " + id);
  }
}