//
// Created by lucas on 15/05/2025.
//

#include "Utils.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <list>
#include <vector>
#include <type_traits>

#include "InvalidDataException.h"
#include "Truck.h"
#include "Van.h"
#include "Vehicle.h"

using namespace std;

int Utils::getInt(const string &label) {
  int number;
  bool flag_error = false;
  do {
    cout << label << ": ";
    flag_error = false;
    cin >> number;
    if(cin.fail()) {
      cout << "That's not a number! Please enter a number.\n";
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      flag_error = true;
    }
  } while(flag_error);
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return number;
}

double Utils::getDouble(const string &label) {
  double number;
  bool flag_error = false;
  do {
    cout << label << ": ";
    flag_error = false;
    cin >> number;
    if(cin.fail()) {
      cout << "That's not a number! Please enter a number.\n";
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      flag_error = true;
    }
  } while(flag_error);
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return number;
}

string Utils::getString(const string &label) {
  string input;
  cout << label << ": ";
  getline(cin, input);
  return input;
}

Date Utils::getDate(const string &label) {
  Date date;
  string input;
  char seperator = '/';
  vector<int> numbers;
  std::stringstream stream(input);
  string item;
  bool flag_error = false;
  cout << label <<" (DD/MM/YYYY): ";
  do {
    flag_error = false;
    numbers.clear();
    getline(cin, input);

    while (getline(stream, item, seperator)) {
      try {
        numbers.push_back(stoi(item));
      } catch (InvalidDataException &error) {
        flag_error = true;
        break;
      }
    }
    if (numbers.size() == 3) {
      if (!date.setDate(numbers[0], numbers[1], numbers[2])) {
        flag_error = true;
        break;
      }
    }
    else {flag_error = true;}
  } while (flag_error);

  return date;
}

Vehicle *Utils::getVehicle(const string &label) {
  string licensePlate = getString(label);
  Vehicle *vehicle = VehicleContainer::get(licensePlate);
  return vehicle;
}




VehicleStorageLocation Utils::setVSL() {
  VehicleStorageLocation vsl = VehicleStorageLocation();
  bool flag_error = false;
  do {
    try {
      flag_error = false;
      int id = Utils::getInt("ID");
      string name = Utils::getString("Name");
      string address = Utils::getString("Address");
      int capacity = Utils::getInt("Capacity");
      int currentVehicleCount = 0;
      vsl = VehicleStorageLocation(id, name, address, capacity, currentVehicleCount);
    } catch (InvalidDataException &error) {
      flag_error = true;
    }
  } while (flag_error);

  return vsl;
}

Insurance Utils::setInsurance() {
  Insurance insurance = Insurance();
  bool flag_error = false;
  do {
    try {
      flag_error = false;
      int id = Utils::getInt("Insurance ID");
      Vehicle *vehicle = Utils::getVehicle("Vehicle's License Plate");
      Date startDate = Utils::getDate("Start Date");
      Date endDate = Utils::getDate("End Date");
      double monthlyCost = Utils::getDouble("Monthly Cost");
      insurance = Insurance(id, vehicle, startDate, endDate, monthlyCost);
    } catch (InvalidDataException &error) {
      flag_error = true;
    }
  } while (flag_error);

  return insurance;
}

Inspection Utils::setInspection() {
  Inspection inspection = Inspection();
  bool flag_error = false;
  do {
    try {
      flag_error = false;
      int id = Utils::getInt("Inspection ID");
      Vehicle *vehicle = Utils::getVehicle("Vehicle's License Plate");
      Date date = Utils::getDate("Date");
      double cost = Utils::getDouble("Cost");
      inspection = Inspection(id, vehicle, date, cost);
    } catch (InvalidDataException &error) {
      flag_error = true;
    }
  } while (flag_error);

  return inspection;
}

Trip *Utils::getOrder(int order &label){ // verificar depois
  int order = getInt(label);
  Trip *trip = TripContainer::get(order);
  return order;
}

Trip utils::setTrip() {
  Trip trip = Trip();
  bool flag_error = false;
    do{
      try{
        flag_error = false;
        int id = Utils::getInt("Trip ID");
        Date date = utils::getDate("Date");
        int order = Utils::getOrder("Order ID");)
        string driver = Utils::getDriver("Driver");
        string vehicle = Utils::getVehicle("Vehicle's License Plate");
      }
    }

}

