//
// Created by lucas on 15/05/2025.
//

#include "Utils.h"
#include <iostream>
#include <limits>

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