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
#include "TripContainer.h"
#include "Truck.h"
#include "Van.h"
#include "Vehicle.h"
#include "OrderContainer.h"
#include "DriverContainer.h"


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

Vehicle *Utils::getVehicle(VehicleContainer &container, const string &label) {
  string licensePlate = getString(label);
  Vehicle *vehicle = container.get(licensePlate);
  return vehicle;
}

Order *Utils::getOrder(OrderContainer &container, const string &label) {
  int id = getInt(label);
  Order *order = container.get(id);
  return order;
}

Driver *Utils::getDriver(DriverContainer &container, const string &label) {
  int id = getInt(label);
  Driver *driver = container.get(id);
  return driver;
}

Trip *Utils::getTrip(TripContainer &container, const string &label) {
  int id = getInt(label);
  Trip *trip = container.getTrip(id);
  return trip;
}

// Trip *Utils::getOrder(int order &label){ // verificar depois
//   int order = getInt(label);
//   Trip *trip = TripContainer::get(order);
//   return order;
// }

// Trip utils::setTrip() {
//   Trip trip = Trip();
//   bool flag_error = false;
//     do{
//       try{
//         flag_error = false;
//         int id = Utils::getInt("Trip ID");
//         Date date = utils::getDate("Date");
//         int order = Utils::getOrder("Order ID");)
//         string driver = Utils::getDriver("Driver");
//         string vehicle = Utils::getVehicle("Vehicle's License Plate");
//       }
//     }
//
// }

