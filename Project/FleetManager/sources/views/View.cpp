//
// Created by lucas on 15/05/2025.
//

#include "View.h"
#include <iostream>
#include "Utils.h"
#include <list>
#include "InvalidDataException.h"

using namespace std;

View::View() {}

int View::menuEnterprise() {
  int op = -1;
  do {
    cout << "******* Login Menu *******\n\n";
    cout << "1. Fleet Manager\n";
    cout << "2. Driver Manager\n";
    cout << "3. Trip Manager\n";
    cout << "4. Financial Manager\n";
    cout << "5. Order Manager\n\n";
    cout << "0. Exit\n\n";
    op = Utils::getInt("Your Option");
  } while(op < 0 || op > 5);
  return op;
}

int View::menuVehicle() {
  int op = -1;
  do {
    cout << "******* Fleet Manager's Menu *******\n\n";
    cout << "1. Add Vehicle\n";
    cout << "2. Remove Vehicle\n";
    cout << "3. List Vehicles\n";
    cout << "4. List Available Vehicles\n";
    cout << "-------------------------------\n";
    cout << "5. Add Insurance\n";
    cout << "6. Remove Insurance\n";
    cout << "7. Add Inspection\n";
    cout << "8. Remove Inspection\n";
    cout << "-------------------------------\n";
    cout << "9. Add Storage Location\n";
    cout << "10. Remove Storage Location\n";
    cout << "11. List Storage Locations\n";
    cout << "12. List Stored Vehicles\n";
    cout << "-------------------------------\n";
    cout << "13. Add Vehicle To Storage\n";
    cout << "14. Remove Vehicle From Storage\n\n";
    cout << "0. Go Back\n\n";
    op = Utils::getInt("Your Option");
  } while(op < 0 || op > 14);
  return op;
}

int View::menuDriver() {
  int op = -1;
  do {
    cout << "******* Driver Manager's Menu *******\n\n";
    cout << "1. Add Driver\n";
    cout << "2. Remove Driver\n";
    cout << "3. List Drivers\n";
    cout << "4. List Available Driver\n";
    cout << "5. Add Vacation\n\n";
    cout << "0. Go Back\n\n";
    op = Utils::getInt("Your Option");
  } while(op < 0 || op > 5);
  return op;
}

int View::menuTrip() {
  int op = -1;
  do {
    cout << "******* Trip Manager's Menu *******\n\n";
    cout << "1. Create Trip\n";
    cout << "2. Start Trip\n";
    cout << "3. Complete Trip\n";
    cout << "4. List Uncompleted Trips\n";
    cout << "5. List Completed Trips\n\n";
    cout << "0. Go Back\n\n";
    op = Utils::getInt("Your Option");
  } while(op < 0 || op > 5);
  return op;
}

int View::menuFinancial() {
  int op = -1;
  do {
    cout << "******* Financial Manager's Menu *******\n\n";
    cout << "1. Record Expense\n";
    cout << "2. List Expenses\n";
    cout << "3. List Expenses By Type\n";
    cout << "-------------------------------\n";
    cout << "4. Record Revenue\n";
    cout << "5. List Revenue\n";
    cout << "-------------------------------\n";
    cout << "6. List Transactions\n";
    cout << "7. Show Balance\n\n";
    cout << "0. Go Back\n\n";
    op = Utils::getInt("Your Option");
  } while(op < 0 || op > 7);
  return op;
}

int View::menuOrder() {
  int op = -1;
  do {
    cout << "******* Order Manager's Menu *******\n\n";
    cout << "1. Add Order\n";
    cout << "2. Remove Order\n";
    cout << "3. Complete Order\n";
    cout << "4. List Uncompleted Orders\n";
    cout << "5. List Completed Orders\n";
    cout << "6. List Orders By Type\n\n";
    cout << "0. Go Back\n\n";
    op = Utils::getInt("Your Option");
  } while(op < 0 || op > 6);
  return op;
}