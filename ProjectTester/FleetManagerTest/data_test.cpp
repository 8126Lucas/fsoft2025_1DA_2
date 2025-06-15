//
// Created by lucas on 14/06/2025.
//

#include "DataContainer.h"
#include "gtest/gtest.h"
#include <filesystem>
#include <fstream>

class DataTest : public testing::Test {
protected:
    void SetUp() override {
        filesystem::create_directory("dummy-json-data");
        containerVehicle = new VehicleContainer();
        containerVSL = new VSLContainer();
        containerDriver = new DriverContainer();
        containerFinancial = new FinancialContainer();
        containerTrip = new TripContainer();
        containerOrder = new OrderContainer();
        containerData = new DataContainer(
            containerVehicle,
            containerVSL,
            containerDriver,
            containerFinancial,
            containerTrip,
            containerOrder,
            "dummy-json-data/vehicle.json",
            "dummy-json-data/vsl.json",
            "dummy-json-data/driver.json",
            "dummy-json-data/financial.json",
            "dummy-json-data/trip.json",
            "dummy-json-data/order.json");
        makeDummyJSONData();
    }
    void TearDown() override {
        delete containerVehicle;
        delete containerVSL;
        delete containerDriver;
        delete containerFinancial;
        delete containerTrip;
        delete containerOrder;
        delete containerData;
        containerData = nullptr;
        filesystem::remove_all("dummy-json-data");
    }
    VehicleContainer *containerVehicle;
    VSLContainer *containerVSL;
    DriverContainer *containerDriver;
    FinancialContainer *containerFinancial;
    TripContainer *containerTrip;
    OrderContainer *containerOrder;
    DataContainer *containerData;

    void makeDummyJSONData() {
        ofstream fileOrder("dummy-json-data/order.json");
        fileOrder << R"({
            "orders": [
                {
                    "cargoSpace": 4.0,
                    "cargoWeight": 400.0,
                    "client": 3,
                    "date": "6/12/2000",
                    "destinationAddress": "Contomil",
                    "id": 1,
                    "shippingValue": 128.99,
                    "sourceAddress": "Ermesinde",
                    "status": "IN_PROGRESS"
                },
                {
                    "cargoSpace": 0.5,
                    "cargoWeight": 35.0,
                    "client": 1,
                    "date": "1/3/2005",
                    "destinationAddress": "FCUP",
                    "id": 2,
                    "shippingValue": 41.99,
                    "sourceAddress": "ISEP",
                    "status": "COMPLETED"
                },
                {
                    "cargoSpace": 0.5,
                    "cargoWeight": 50.0,
                    "client": 1,
                    "date": "14/6/2025",
                    "destinationAddress": "Lisboa",
                    "id": 3,
                    "shippingValue": 350.0,
                    "sourceAddress": "Ermesinde",
                    "status": "IN_PROGRESS"
                },
                {
                    "cargoSpace": 3.0,
                    "cargoWeight": 15.0,
                    "client": 2,
                    "date": "22/1/2020",
                    "destinationAddress": "Ermesinde",
                    "id": 4,
                    "shippingValue": 87.99,
                    "sourceAddress": "Amarante",
                    "status": "IN_PROGRESS"
                }
            ]
        })" << endl;
        fileOrder.close();

        ofstream fileVehicle("dummy-json-data/vehicle.json");
        fileVehicle << R"({
            "trucks": [
                {
                    "available": true,
                    "brand": "AAA",
                    "category": "TRUCK",
                    "fuel": 80.0,
                    "inspectionCost": 30.0,
                    "inspectionDate": "10/6/2025",
                    "inspectionID": 1,
                    "inspectionToday": "14/6/2025",
                    "insuranceEndDate": "11/6/2026",
                    "insuranceID": 1,
                    "insuranceMonthlyCost": 30.0,
                    "insuranceStartDate": "11/6/2025",
                    "insuranceToday": "14/6/2025",
                    "licensePlate": "AA-AA-AA",
                    "mileage": 140000.0,
                    "model": "AAA",
                    "weightCapacity": 100.0,
                    "vslID": 1,
                    "year": 2009
                }
            ],
            "vans": [
                {
                    "available": true,
                    "brand": "BBB",
                    "category": "VAN",
                    "fuel": 80.0,
                    "inspectionCost": 30.0,
                    "inspectionDate": "10/6/2025",
                    "inspectionID": 2,
                    "inspectionToday": "14/6/2025",
                    "insuranceEndDate": "11/6/2026",
                    "insuranceID": 2,
                    "insuranceMonthlyCost": 30.0,
                    "insuranceStartDate": "11/6/2025",
                    "insuranceToday": "14/6/2025",
                    "licensePlate": "BB-BB-BB",
                    "mileage": 140000.0,
                    "model": "BBB",
                    "spaceCapacity": 100.0,
                    "vslID": 1,
                    "year": 2025
                }
            ]
        })" << endl;
        fileVehicle.close();

        ofstream fileVSL("dummy-json-data/vsl.json");
        fileVSL << R"({
            "vsls": [
                {
                    "address": "Rua da VSL 1",
                    "capacity": 4,
                    "currentVehicleCount": 2,
                    "id": 1,
                    "name": "VSL 1",
                    "vehicles": [
                        {
                            "vehicleLicensePlate": "AA-AA-AA"
                        },
                        {
                            "vehicleLicensePlate": "BB-BB-BB"
                        }
                    ]
                }
            ]
        })" << endl;
        fileVSL.close();

        ofstream fileDriver("dummy-json-data/driver.json");
        fileDriver << R"({
            "drivers": [
                {
                    "age": 67,
                    "available": true,
                    "id": 1,
                    "license": "B",
                    "timeToRetire": 0,
                    "vacations": []
                },
                {
                    "age": 25,
                    "available": true,
                    "id": 2,
                    "license": "C",
                    "timeToRetire": 40,
                    "vacations": []
                }
            ]
        })" << endl;
        fileDriver.close();


        ofstream fileTrip("dummy-json-data/trip.json");
        fileTrip << R"({
            "trips": [
                {
                    "cost": 200.0,
                    "driverID": 1,
                    "fines": 0.0,
                    "fuel": 0.0,
                    "fuelCost": 0.0,
                    "id": 4,
                    "km": 0.0,
                    "orderID": 4,
                    "state": "INCOMING",
                    "tolls": 0.0,
                    "vehicleLicensePlate": "AA-AA-AA"
                },
                {
                    "cost": 200.0,
                    "driverID": -1,
                    "fines": 0.0,
                    "fuel": 0.0,
                    "fuelCost": 0.0,
                    "id": 2,
                    "km": 0.0,
                    "orderID": 1,
                    "state": "DELIVERED",
                    "tolls": 0.0,
                    "vehicleLicensePlate": "No Vehicle"
                },
                {
                    "cost": 200.0,
                    "driverID": -1,
                    "fines": 0.0,
                    "fuel": 0.0,
                    "fuelCost": 0.0,
                    "id": 3,
                    "km": 0.0,
                    "orderID": 2,
                    "state": "SUPRESSED",
                    "tolls": 0.0,
                    "vehicleLicensePlate": "No Vehicle"
                }
            ]
        })" << endl;
        fileTrip.close();

        ofstream fileFinancial("dummy-json-data/financial.json");
        fileFinancial << R"({
            "expenses": [
                {
                    "amount": 34.99,
                    "expenseDate": "1/6/2025",
                    "id": 1,
                    "trip": 4,
                    "type": "FUEL"
                }
            ],
            "revenues": [
                {
                    "amount": 120.0,
                    "id": 1,
                    "order": 4,
                    "revenueDate": "1/6/2025"
                }
    ]
        })" << endl;
        fileFinancial.close();

    }
};


TEST_F(DataTest, LoadAllData) {
    containerData->loadAllData();

    EXPECT_EQ(containerVehicle->listTrucks().size(), 1);
    string licensePlateTruck = "AA-AA-AA";
    EXPECT_NE(containerVehicle->get(licensePlateTruck), nullptr);
    EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getYear(), 2009);
    EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getVSL()->getID(), 1);
    EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getInspection()->getID(), 1);
    EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getInsurance()->getID(), 1);
    EXPECT_EQ(containerVehicle->listVans().size(), 1);
    string licensePlateVan = "BB-BB-BB";
    EXPECT_NE(containerVehicle->get(licensePlateVan), nullptr);
    EXPECT_EQ(containerVehicle->get(licensePlateVan)->getYear(), 2025);
    EXPECT_EQ(containerVehicle->get(licensePlateVan)->getVSL()->getID(), 1);
    EXPECT_EQ(containerVehicle->get(licensePlateVan)->getInspection()->getID(), 2);
    EXPECT_EQ(containerVehicle->get(licensePlateVan)->getInsurance()->getID(), 2);

    EXPECT_EQ(containerVSL->listVSL().size(), 1);
    EXPECT_NE(containerVSL->get(1), nullptr);
    EXPECT_EQ(containerVSL->get(1)->getVehicleCount(), 2);
    EXPECT_EQ(containerVSL->get(1)->getStoredVehicles(1).size(), 2);
    EXPECT_NE(containerVSL->get(1)->getStoredVehicles(1).front(), nullptr);
    EXPECT_EQ(containerVSL->get(1)->getStoredVehicles(1).front()->getLicensePlate(), "AA-AA-AA");
    EXPECT_NE(containerVSL->get(1)->getStoredVehicles(1).back(), nullptr);
    EXPECT_EQ(containerVSL->get(1)->getStoredVehicles(1).back()->getLicensePlate(), "BB-BB-BB");

    EXPECT_EQ(containerDriver->listDrivers().size(), 2);
    EXPECT_NE(containerDriver->get(1), nullptr);
    EXPECT_EQ(containerDriver->get(1)->getLicense(), 'B');
    EXPECT_TRUE(containerDriver->get(1)->getVacations().empty());
    EXPECT_NE(containerDriver->get(2), nullptr);
    EXPECT_EQ(containerDriver->get(2)->getLicense(), 'C');
    EXPECT_TRUE(containerDriver->get(2)->getVacations().empty());

    EXPECT_EQ(containerFinancial->listExpense().size(), 1);
    EXPECT_NE(containerFinancial->getExpense(1), nullptr);
    Date dateExpense(1, 6, 2025);
    EXPECT_EQ(containerFinancial->getExpense(1)->getDate(), dateExpense);
    EXPECT_NE(containerFinancial->getExpense(1)->getTrip(), nullptr);
    EXPECT_EQ(containerFinancial->getExpense(1)->getTrip()->getID(), 4);
    EXPECT_EQ(containerFinancial->getExpense(1)->getType(), FUEL);
    EXPECT_EQ(containerFinancial->listRevenue().size(), 1);
    EXPECT_NE(containerFinancial->getRevenue(1), nullptr);
    Date dateRevenue(1, 6, 2025);
    EXPECT_EQ(containerFinancial->getRevenue(1)->getDate(), dateRevenue);
    EXPECT_NE(containerFinancial->getRevenue(1)->getOrder(), nullptr);
    EXPECT_EQ(containerFinancial->getRevenue(1)->getOrder()->getOrderID(), 4);

    EXPECT_EQ(containerTrip->listTrips().size(), 3);
    EXPECT_NE(containerTrip->getTrip(4), nullptr);
    EXPECT_EQ(containerTrip->getTrip(4)->getState(), INCOMING);
    string licensePlate1 = "AA-AA-AA";
    EXPECT_EQ(containerTrip->getTrip(4)->getVehicle()->getLicensePlate(), licensePlate1);
    EXPECT_EQ(containerTrip->getTrip(4)->getOrder()->getOrderID(), 4);
    EXPECT_EQ(containerTrip->getTrip(4)->getDriver()->getID(), 1);
    EXPECT_NE(containerTrip->getTrip(2), nullptr);
    EXPECT_EQ(containerTrip->getTrip(2)->getState(), DELIVERED);
    EXPECT_EQ(containerTrip->getTrip(2)->getVehicle(), nullptr);
    EXPECT_EQ(containerTrip->getTrip(2)->getOrder()->getOrderID(), 1);
    EXPECT_EQ(containerTrip->getTrip(2)->getDriver(), nullptr);
    EXPECT_NE(containerTrip->getTrip(3), nullptr);
    EXPECT_EQ(containerTrip->getTrip(3)->getState(), SUPRESSED);
    EXPECT_EQ(containerTrip->getTrip(3)->getVehicle(), nullptr);
    EXPECT_EQ(containerTrip->getTrip(3)->getOrder()->getOrderID(), 2);
    EXPECT_EQ(containerTrip->getTrip(3)->getDriver(), nullptr);

    EXPECT_EQ(containerOrder->listOrders().size(), 4);
    EXPECT_NE(containerOrder->get(1), nullptr);
    EXPECT_EQ(containerOrder->get(1)->getStatus(), IN_PROGRESS);
    Date date1(6, 12, 2000);
    EXPECT_EQ(containerOrder->get(1)->getDate(), date1);
    EXPECT_EQ(containerOrder->get(1)->getClientID(), 3);
    EXPECT_NE(containerOrder->get(2), nullptr);
    EXPECT_EQ(containerOrder->get(2)->getStatus(), COMPLETED);
    Date date2(1, 3, 2005);
    EXPECT_EQ(containerOrder->get(2)->getDate(), date2);
    EXPECT_EQ(containerOrder->get(2)->getClientID(), 1);
    EXPECT_NE(containerOrder->get(3), nullptr);
    EXPECT_EQ(containerOrder->get(3)->getStatus(), IN_PROGRESS);
    Date date3(14, 6, 2025);
    EXPECT_EQ(containerOrder->get(3)->getDate(), date3);
    EXPECT_EQ(containerOrder->get(3)->getClientID(), 1);
    EXPECT_NE(containerOrder->get(4), nullptr);
    EXPECT_EQ(containerOrder->get(4)->getStatus(), IN_PROGRESS);
    Date date4(22, 1, 2020);
    EXPECT_EQ(containerOrder->get(4)->getDate(), date4);
    EXPECT_EQ(containerOrder->get(4)->getClientID(), 2);
}

TEST_F(DataTest, SaveAllData) {
    containerData->loadAllData();

    Date dateOrder(1, 1, 2020);
    Order *order = new Order(999, 999, dateOrder, "ABC", "DEF", 10, 100, 1000, IN_PROGRESS);
    containerOrder->add(*order);
    Truck *truck = new Truck(TRUCK, "CCC", "CCC", 2000, "CC-CC-CC", 120, 98, 120, true);
    containerVehicle->add(truck);
    string vslName = "Nome";
    string vslAddress = "Morada";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    containerVSL->add(vsl);
    char driverLicense('C');
    Driver *driver = new Driver(999, driverLicense, 20);
    containerDriver->add(*driver);
    Trip *trip = new Trip(INCOMING, 999, order, 200);
    containerTrip->add(*trip);
    Date dateExpense(1, 1, 2020);
    Expense *expense = new Expense(999, trip, dateExpense, 200, TOLL);
    containerFinancial->addExpense(*expense);
    Date dateRevenue(1, 1, 2020);
    Revenue *revenue = new Revenue(999, order, dateRevenue, 20000);
    containerFinancial->addRevenue(*revenue);

    containerData->saveAllData();

    VehicleContainer *loadedContainerVehicle = new VehicleContainer();
    VSLContainer *loadedContainerVSL = new VSLContainer();
    DriverContainer *loadedContainerDriver = new DriverContainer();
    FinancialContainer *loadedContainerFinancial = new FinancialContainer();
    TripContainer *loadedContainerTrip = new TripContainer();
    OrderContainer *loadedContainerOrder = new OrderContainer();

    DataContainer *loadedContainerData = new DataContainer(
        loadedContainerVehicle,
        loadedContainerVSL,
        loadedContainerDriver,
        loadedContainerFinancial,
        loadedContainerTrip,
        loadedContainerOrder,
        "dummy-json-data/vehicle.json",
        "dummy-json-data/vsl.json",
        "dummy-json-data/driver.json",
        "dummy-json-data/financial.json",
        "dummy-json-data/trip.json",
        "dummy-json-data/order.json");

    loadedContainerData->loadAllData();

    EXPECT_EQ(loadedContainerVehicle->listTrucks().size(), 2);
    string licensePlateTruck = "CC-CC-CC";
    EXPECT_NE(loadedContainerVehicle->get(licensePlateTruck), nullptr);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getYear(), 2000);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getVSL(), nullptr);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getInspection(), nullptr);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getInsurance(), nullptr);
    EXPECT_EQ(loadedContainerVehicle->listVans().size(), 1);

    EXPECT_EQ(loadedContainerVSL->listVSL().size(), 2);
    EXPECT_NE(loadedContainerVSL->get(999), nullptr);
    EXPECT_EQ(loadedContainerVSL->get(999)->getVehicleCount(), 0);

    EXPECT_EQ(loadedContainerDriver->listDrivers().size(), 3);
    EXPECT_NE(loadedContainerDriver->get(999), nullptr);
    EXPECT_EQ(loadedContainerDriver->get(999)->getLicense(), 'C');
    EXPECT_TRUE(loadedContainerDriver->get(999)->getVacations().empty());

    EXPECT_EQ(loadedContainerTrip->listTrips().size(), 4);
    EXPECT_NE(loadedContainerTrip->getTrip(999), nullptr);
    EXPECT_EQ(loadedContainerTrip->getTrip(999)->getState(), INCOMING);
    EXPECT_EQ(loadedContainerTrip->getTrip(999)->getOrder()->getOrderID(), 999);

    EXPECT_EQ(loadedContainerFinancial->listExpense().size(), 2);
    EXPECT_NE(loadedContainerFinancial->getExpense(999)->getTrip(), nullptr);
    EXPECT_EQ(loadedContainerFinancial->getExpense(999)->getType(), TOLL);
    Date dateExpenseEQ(1, 1, 2020);
    EXPECT_EQ(loadedContainerFinancial->getExpense(999)->getDate(), dateExpenseEQ);
    EXPECT_EQ(loadedContainerFinancial->listRevenue().size(), 2);
    EXPECT_NE(loadedContainerFinancial->getRevenue(999)->getOrder(), nullptr);
    Date dateRevenueEQ(1, 1, 2020);
    EXPECT_EQ(loadedContainerFinancial->getRevenue(999)->getDate(), dateRevenueEQ);

    EXPECT_EQ(containerOrder->listOrders().size(), 5);
    EXPECT_NE(containerOrder->get(999), nullptr);
    EXPECT_EQ(containerOrder->get(999)->getStatus(), IN_PROGRESS);
    Date dateOrderEQ(1, 1, 2020);
    EXPECT_EQ(containerOrder->get(999)->getDate(), dateOrderEQ);
    EXPECT_EQ(containerOrder->get(999)->getClientID(), 999);

    delete loadedContainerVehicle;
    delete loadedContainerVSL;
    delete loadedContainerDriver;
    delete loadedContainerFinancial;
    delete loadedContainerTrip;
    delete loadedContainerOrder;
    delete loadedContainerData;
}