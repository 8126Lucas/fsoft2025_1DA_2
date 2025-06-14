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
#include <cctype>
#include "NonExistingDataException.h"
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
    if(cin.fail() || number < 0) {
      cout << "That's not a valid number! Please enter a valid number.\n";
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
    if(cin.fail() || number < 0.0) {
      cout << "That's not a valid number! Please enter a valid number.\n";
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      flag_error = true;
    }
    if (label == "Fuel (%)" && (number > 100.0 || number < 0.0)) {
      cout << "That's not valid percentage! Please try again.\n";
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

char Utils::getChar(const string &label) {
  string input;
  bool flag_error = false;
  do {
    cout << label << ": ";
    cin >> input;
    if (cin.fail() || input.length() != 1 || !isalpha(input[0])) {
      cout << "That's not a character! Please enter a character.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      flag_error = true;
    }
    else {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      flag_error = false;
    }
  } while (flag_error);
  return input[0];
}

Date Utils::getDate(const string &label) {
  Date date;
  string input;
  char seperator = '/';
  vector<int> numbers;

  bool flag_error = false;
  cout << label <<" (DD/MM/YYYY): ";
  do {
    flag_error = false;
    numbers.clear();
    getline(cin, input);
    stringstream stream(input);
    string item;

    while (getline(stream, item, seperator)) {
      try {
        numbers.push_back(stoi(item));
      } catch (InvalidDataException &error) {
        cout << error.what() << endl;
        flag_error = true;
        break;
      }
    }
    if (!flag_error) {
      if (numbers.size() == 3) {
        if (!date.setDate(numbers[0], numbers[1], numbers[2])) {
          flag_error = true;
          throw(InvalidDataException("Date"));
        }
      }
      else {flag_error = true;}
    }
  } while (flag_error);

  return date;
}

Vehicle *Utils::getVehicle(VehicleContainer &container, const string &label) {
  Vehicle *vehicle = new Vehicle();
  bool valid = false;
  do {
    try {
      string licensePlate = getString(label);
      vehicle = container.get(licensePlate);
      valid = true;
    } catch (const NonExistingDataException &error) {
      cout << error.what() << endl;
      cout << "Please try again!\n";
      valid = false;
    }
  } while (!valid);
  return vehicle;
}

Order *Utils::getOrder(OrderContainer &container, const string &label) {
  Order *order = new Order();
  bool valid = false;
  do {
    try {
      int id = getInt(label);
      order = container.get(id);
      valid = true;
    } catch (const NonExistingDataException &error) {
      cout << error.what() << endl;
      cout << "Please try again!\n";
      valid = false;
    }
  } while (!valid);
  return order;
}

Driver *Utils::getDriver(DriverContainer &container, const string &label) {
  Driver *driver = new Driver();
  bool valid = false;
  do {
    try {
      int id = getInt(label);
      driver = container.get(id);
      valid = true;
    } catch (const NonExistingDataException &error) {
      cout << error.what() << endl;
      cout << "Please try again!\n";
      valid = false;
    }
  } while (!valid);
  return driver;
}

Trip *Utils::getTrip(TripContainer &container, const string &label) {
  Trip *trip = new Trip();
  bool valid = false;
  do {
    try {
      int id = getInt(label);
      trip = container.getTrip(id);
      valid = true;
    } catch (const NonExistingDataException &error) {
      cout << error.what() << endl;
      cout << "Please try again!\n";
      valid = false;
    }
  } while (!valid);
  return trip;
}


