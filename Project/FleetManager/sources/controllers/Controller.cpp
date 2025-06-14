//
// Created by lucas on 15/05/2025.
//

#include "Controller.h"
#include <iostream>
#include "Utils.h"
#include <list>

using namespace std;

Controller::Controller(Enterprise &enterprise): model(enterprise) {}

void Controller::run() {
    this->model.getDataContainer().loadAllData();
    int op = -1;
    do {
        op = this->view.menuEnterprise();
        switch (op) {
            case 1:
                runVehicle();
                break;
            case 2:
                runDriver();
                break;
            case 3:
                runTrip();
                break;
            case 4:
                runFinancial();
                break;
            case 5:
                runOrder();
                break;
        }
    } while (op != 0);
    this->model.getDataContainer().saveAllData();
}

void Controller::runVehicle() {
    int op = -1;
    do {
        op = this->view.menuVehicle();
        switch (op) {
            case 1: {
                int category = Utils::getInt("Category (Truck - 1 / Van - 2)");
                if (category == 1) {
                    Truck *truck = this->vehicleView.addTruck();
                    VehicleContainer &container = this->model.getVehicleContainer();
                    container.add(truck);
                }
                if (category == 2) {
                    Van *van = this->vehicleView.addVan();
                    VehicleContainer &container = this->model.getVehicleContainer();
                    container.add(van);
                }
            }
                break;
            case 2: {
                string licensePlate = this->vehicleView.removeVehicle();
                VehicleContainer &container = this->model.getVehicleContainer();
                container.remove(licensePlate);
            }
                break;
            case 3: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Truck*> trucks = container.listTrucks();
                list<Van*> vans = container.listVans();
                this->vehicleView.printListTrucks(trucks);
                this->vehicleView.printListVans(vans);
            }
                break;
            case 4: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Truck*> trucks = container.listTrucks(true);
                list<Van*> vans = container.listVans(true);
                this->vehicleView.printListTrucks(trucks);
                this->vehicleView.printListVans(vans);
            }
                break;
            case 5: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Truck*> trucks = container.listTrucks(false);
                list<Van*> vans = container.listVans(false);
                this->vehicleView.printListTrucks(trucks);
                this->vehicleView.printListVans(vans);
            }
                break;
            case 6: {
                string licensePlate = Utils::getString("Vehicle's License Plate");
                VehicleContainer &container = this->model.getVehicleContainer();
                Vehicle *vehicle = container.get(licensePlate);
                double addedFuel = this->vehicleView.addFuel(vehicle);
                container.updateFuel(licensePlate, addedFuel);
            }
                break;
            case 7: {
                VehicleContainer &container = this->model.getVehicleContainer();
                Insurance *insurance = this->insuranceView.addInsurance(container);
                string licensePlate = insurance->getVehicle()->getLicensePlate();
                container.update(licensePlate, insurance);
            }
                break;
            case 8: {
                VehicleContainer &container = this->model.getVehicleContainer();
                Insurance *insurance = nullptr;
                string licensePlate = this->insuranceView.removeInsurance();
                container.update(licensePlate, insurance);
            }
                break;
            case 9: {
                VehicleContainer &container = this->model.getVehicleContainer();
                Inspection *inspection = this->inspectionView.addInspection(container);
                string licensePlate = inspection->getVehicle()->getLicensePlate();
                container.update(licensePlate, inspection);
            }
                break;
            case 10: {
                VehicleContainer &container = this->model.getVehicleContainer();
                Inspection *inspection = nullptr;
                string licensePlate = this->inspectionView.removeInspection();
                container.update(licensePlate, inspection);
            }
                break;
            case 11: {
                VehicleStorageLocation *vsl = this->vslView.addVSL();
                VSLContainer &container = this->model.getVSLContainer();
                container.add(vsl);
            }
                break;
            case 12: {
                int id = this->vslView.removeVSL();
                VSLContainer &container = this->model.getVSLContainer();
                container.remove(id);
            }
                break;
            case 13: {
                VSLContainer &container = this->model.getVSLContainer();
                list<VehicleStorageLocation*> locations = container.listVSL();
                this->vslView.printListVSL(locations);
            }
                break;
            case 14: {
                VSLContainer &container = this->model.getVSLContainer();
                int vslID = Utils::getInt("VSL ID");
                VehicleStorageLocation *vsl = container.get(vslID);
                this->vslView.printListStoredVehicles(*vsl);
            }
                break;
            case 15: {
                VSLContainer &containerVSL = this->model.getVSLContainer();
                VehicleContainer &containerVehicle = this->model.getVehicleContainer();
                Vehicle *vehicle = this->vehicleView.getVehicle(&containerVehicle);
                VehicleStorageLocation *vsl = this->vslView.getVSL(&containerVSL);
                this->vslView.addVehicleToStorage(vsl, vehicle);
                string licensePlate = vehicle->getLicensePlate();
                containerVehicle.update(licensePlate, vsl);
            }
                break;
            case 16: {
                VSLContainer &containerVSL = this->model.getVSLContainer();
                VehicleContainer &containerVehicle = this->model.getVehicleContainer();
                Vehicle *vehicle = this->vehicleView.getVehicle(&containerVehicle);
                VehicleStorageLocation *vsl = this->vslView.getVSL(&containerVSL);
                VehicleStorageLocation *newVSL = nullptr;
                string licensePlate = vehicle->getLicensePlate();
                this->vslView.removeVehicleFromStorage(vsl, vehicle);
                containerVehicle.update(licensePlate, newVSL);
            }
                break;
        }
    } while (op != 0);
}

void Controller::runTrip() {
    int op = -1;
    do {
        op = this->view.menuTrip();
        switch (op) {
            case 1: {
                OrderContainer &containerOrder = this->model.getOrderContainer();

                Trip trip = this->tripView.addTrip(containerOrder);
                TripContainer &containerTrip = this->model.getTripContainer();
                containerTrip.add(trip);
            }
            break;
            case 2: {
                TripContainer &containerTrip = this->model.getTripContainer();
                DriverContainer &containerDriver = this->model.getDriverContainer();
                VehicleContainer &containerVehicle = this->model.getVehicleContainer();
                this->tripView.startTrip(containerTrip, containerDriver, containerVehicle);
            }
            break;
            case 3: {
                DriverContainer &containerDriver = this->model.getDriverContainer();
                VehicleContainer &containerVehicle = this->model.getVehicleContainer();
                TripContainer &containerTrip = this->model.getTripContainer();

                this->tripView.endTrip(containerTrip, containerDriver, containerVehicle);

            }
            break;
            case 4: {
                TripContainer &containerTrip = this->model.getTripContainer();
                int id = Utils::getInt("Trip ID");
                Trip *trip = containerTrip.getTrip(id);
                this->tripView.failTrip(trip);

            }
            break;
            case 5: {
                TripContainer &containerTrip = this->model.getTripContainer();
                list<Trip> listTrips = containerTrip.listTrips();
                this->tripView.printListTrips(listTrips);
            }
            break;
            case 6: {
                DriverContainer &containerDriver = this->model.getDriverContainer();
                TripContainer &containerTrip = this->model.getTripContainer();
                Driver *driver = Utils::getDriver(containerDriver, "Driver ID");
                list<Trip> listTrips = containerTrip.listTripsByDriver(*driver);
                this->tripView.printListTrips(listTrips);
            }
            break;
            case 7: {
                TripContainer &containerTrip = this->model.getTripContainer();
                list<Trip> listFailed = containerTrip.listTripsByState(FAILED);
                list<Trip> listSupressed = containerTrip.listTripsByState(SUPRESSED);
                list<Trip> listIncoming = containerTrip.listTripsByState(INCOMING);
                if (!listFailed.empty()) {
                    this->tripView.printListTrips(listFailed);
                }
                if (!listSupressed.empty()) {
                    this->tripView.printListTrips(listSupressed);
                }
                if (!listIncoming.empty()) {
                    this->tripView.printListTrips(listIncoming);
                }
            }
            break;
            case 8: {
                TripContainer &containerTrip = this->model.getTripContainer();
                list<Trip> listDelivered = containerTrip.listTripsByState(DELIVERED);
                this->tripView.printListTrips(listDelivered);
            }
            break;
        }
    } while (op != 0);
}

void Controller::runDriver() {
    int op = -1;
    do {
        op = this->view.menuDriver();
        switch (op) {
            case 1: {
                Driver driver = this->driverView.addDriver();
                DriverContainer &containerDriver = this->model.getDriverContainer();
                containerDriver.add(driver);
            }
                break;
            case 2: {
                int id = this->driverView.removeDriver();
                DriverContainer &containerDriver = this->model.getDriverContainer();
                containerDriver.remove(id);
            }
                break;
            case 3: {
                DriverContainer &containerDriver = this->model.getDriverContainer();
                list<Driver> listDrivers = containerDriver.listDrivers();
                this->driverView.printDrivers(listDrivers);
            }
                break;
            case 4: {
                DriverContainer &containerDriver = this->model.getDriverContainer();
                list<Driver> listDrivers = containerDriver.listAvailableDrivers(true);
                this->driverView.printAvailableDrivers(listDrivers);
            }
                break;
            case 5: {
                DriverContainer &containerDriver = this->model.getDriverContainer();
                list<Driver> listDrivers = containerDriver.listAvailableDrivers(false);
                this->driverView.printUnavailableDrivers(listDrivers);
            }
                break;
            case 6: {
                DriverContainer &containerDriver = this->model.getDriverContainer();
                Vacation *vacation = this->vacationView.addVacation(containerDriver);
                containerDriver.update(vacation->getDriver()->getID(), vacation);
            }
        }
    } while (op != 0);
}

void Controller::runFinancial() {
    int op = -1;
    do {
        op = this->view.menuFinancial();
        switch (op) {
            case 1: {
                TripContainer &containerTrip = this->model.getTripContainer();
                Expense expense = this->financialView.recordExpense(containerTrip);
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                containerFinancial.addExpense(expense);
            }
                break;
            case 2: {
                int id = this->financialView.removeExpense();
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                containerFinancial.removeExpense(id);
            }
                break;
            case 3: {
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                list<Expense> listExpenses = containerFinancial.listExpense();
                this->financialView.printExpenses(listExpenses);
            }
                break;
            case 4: {
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                int type = Utils::getInt("Type (FUEL/INSPECTION/INSURANCE/TOLL/FINE)");
                TYPE expenseType;
                if (type >= 1 && type <= 5) {
                    expenseType = static_cast<TYPE>(type);
                    list<Expense> listExpenses = containerFinancial.listExpensesByType(expenseType);
                    this->financialView.printExpensesByType(listExpenses, expenseType);
                }
                else {
                    this->financialView.printInvalidTypeError();
                }
            }
                break;
            case 5: {
                OrderContainer &containerOrder = this->model.getOrderContainer();
                Revenue revenue = this->financialView.recordRevenue(containerOrder);
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                containerFinancial.addRevenue(revenue);
            }
                break;
            case 6: {
                int id = this->financialView.removeRevenue();
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                containerFinancial.removeRevenue(id);
            }
                break;
            case 7: {
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                list<Revenue> listRevenues = containerFinancial.listRevenue();
                this->financialView.printRevenues(listRevenues);
            }
                break;
            case 8: {
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                list<Expense> listExpenses = containerFinancial.listExpense();
                list<Revenue> listRevenues = containerFinancial.listRevenue();
                this->financialView.printAllFinancialRecords(listExpenses, listRevenues);
            }
                break;
            case 9: {
                FinancialContainer &containerFinancial = this->model.getFinancialContainer();
                Date startDate = Utils::getDate("Start Date");
                Date endDate = Utils::getDate("End Date");
                this->financialView.printBalance(containerFinancial, startDate, endDate);
            }
                break;
        }
    } while (op != 0);
}

void Controller::runOrder() {
    int op = -1;
    do {
        op = this->view.menuOrder();
        switch (op) {
            case 1: {
                Order order = this->orderView.addOrder();
                OrderContainer &containerOrder = this->model.getOrderContainer();
                containerOrder.add(order);
            }
                break;
            case 2: {
                int id = this->orderView.removeOrder();
                OrderContainer &containerOrder = this->model.getOrderContainer();
                containerOrder.remove(id);
            }
                break;
            case 3: {
                OrderContainer &containerOrder = this->model.getOrderContainer();
                int id = Utils::getInt("Order ID");
                Order *order = containerOrder.get(id);
                this->orderView.completeOrder(order);
            }
                break;
            case 4: {
                OrderContainer &containerOrder = this->model.getOrderContainer();
                list<Order> listOrder = containerOrder.listOrders();
                this->orderView.printOrders(listOrder);
            }
                break;
            case 5: {
                OrderContainer &containerOrder = this->model.getOrderContainer();
                list<Order> listOrder = containerOrder.listUncompleted();
                this->orderView.printUncompletedOrders(listOrder);
            }
                break;
            case 6: {
                OrderContainer &containerOrder = this->model.getOrderContainer();
                list<Order> listOrder = containerOrder.listCompleted();
                this->orderView.printCompletedOrders(listOrder);
            }
                break;
            case 7: {
                int clientID = Utils::getInt("Client ID");
                OrderContainer &containerOrder = this->model.getOrderContainer();
                list<Order> listOrder = containerOrder.listOrdersByClient(clientID);
                this->orderView.printOrdersByClient(listOrder);
            }
                break;
        }
    } while (op != 0);
}