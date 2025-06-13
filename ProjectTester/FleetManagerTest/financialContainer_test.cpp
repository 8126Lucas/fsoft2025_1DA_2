//
// Created by ruben on 13/06/2025.
//
#include "Expense.h"
#include "Revenue.h"
#include "FinancialContainer.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "Date.h"

class FinancialContainerTest : public ::testing::Test {
protected:
    void SetUp() override {
        financialContainer = new FinancialContainer();
    }
    void TearDown() override {
        delete financialContainer;
        financialContainer = nullptr;
    }
    FinancialContainer* financialContainer;
};

TEST_F(FinancialContainerTest, RecordValidExpense) {
    Order* order = new Order(1, 1, Date(1,1,2025), "Porto", "Lisboa", 10, 15, 100, IN_PROGRESS);
    char driverLicense = 'B';
    Driver* driver = new Driver(1, driverLicense, 30);
    Vehicle* vehicle = new Vehicle(VAN, "Seat", "Ibiza", 2000, "BBBBBB", 2500, 20, true);
    Date tripDate(1,1,2025);
    Trip *trip = new Trip();
    trip->setID(1);
    trip->setOrder(order);
    trip->setDriver(driver);
    trip->setVehicle(vehicle);
    Expense *expense = new Expense(1, trip, Date(1,1,2025), 150.50, FUEL);
    testing::internal::CaptureStdout();
    financialContainer->addExpense(*expense);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(output, success_message);
    EXPECT_EQ(financialContainer->listExpense().size(), 1);
    delete order;
    delete driver;
    delete vehicle;
    delete trip;
    delete expense;
}

TEST_F(FinancialContainerTest, RecordDuplicatedExpense) {
    Order* order = new Order(1, 1, Date(1,1,2025), "Porto", "Lisboa", 10, 15, 100, IN_PROGRESS);
    char driverLicense = 'B';
    Driver* driver = new Driver(1, driverLicense, 30);
    Vehicle* vehicle = new Vehicle(VAN, "Seat", "Ibiza", 2000, "BBBBBB", 2500, 20, true);
    Date tripDate(1,1,2025);
    Trip *trip = new Trip();
    trip->setID(1);
    trip->setOrder(order);
    trip->setDriver(driver);
    trip->setVehicle(vehicle);
    Expense *expense = new Expense(1, trip, Date(1,1,2025), 150.50, FUEL);
    financialContainer->addExpense(*expense);
    testing::internal::CaptureStdout();
    financialContainer->addExpense(*expense);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Expense (id): 1\" duplicated !!\n");
    EXPECT_EQ(financialContainer->listExpense().size(), 1);
    delete trip;
    delete expense;
}

//recordInvalidExpense

//removeExpense

TEST_F(FinancialContainerTest, RemoveValidExpense) {
    Order* order = new Order(1, 1, Date(1,1,2025), "Porto", "Lisboa", 10, 15, 100, IN_PROGRESS);
    char driverLicense = 'B';
    Driver* driver = new Driver(1, driverLicense, 30);
    Vehicle* vehicle = new Vehicle(VAN, "Seat", "Ibiza", 2000, "BBBBBB", 2500, 20, true);
    Date tripDate(1,1,2025);
    Trip *trip = new Trip();
    trip->setID(1);
    trip->setOrder(order);
    trip->setDriver(driver);
    trip->setVehicle(vehicle);
    Expense *expense = new Expense(1, trip, Date(1,1,2025), 150.50, FUEL);
    financialContainer->addExpense(*expense);
    testing::internal::CaptureStdout();
    financialContainer->removeExpense(1);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(financialContainer->listExpense().size(), 0);
    delete trip;
    delete expense;
}

//listExpenses

//listExpensesByType

TEST_F(FinancialContainerTest, RecordValidRevenue) {
    Order *order = new Order(1, 1, Date(1,1,2025),"Porto", "Lisboa", 10, 15, 100, IN_PROGRESS);
    Revenue *revenue = new Revenue(1, order, Date(1,1,2025), 100);
    testing::internal::CaptureStdout();
    financialContainer->addRevenue(*revenue);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(financialContainer->listRevenue().size(), 1);
    delete order;
    delete revenue;
}

TEST_F(FinancialContainerTest, RecordDuplicatedRevenue) {
    Order *order = new Order(1, 1, Date(1,1,2025),"Porto", "Lisboa", 10, 15, 100, IN_PROGRESS);
    Revenue *revenue = new Revenue(1, order, Date(1,1,2025), 100);
    financialContainer->addRevenue(*revenue);
    testing::internal::CaptureStdout();
    financialContainer->addRevenue(*revenue);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Revenue (id): 1\" duplicated !!\n");
    EXPECT_EQ(financialContainer->listRevenue().size(), 1);
    delete order;
    delete revenue;
}

//recordInvalidRevenue

//removeRevenue

TEST_F(FinancialContainerTest, RemoveValidRevenue) {
    Order *order = new Order(1, 1, Date(1,1,2025),"Porto", "Lisboa", 10, 15, 100, IN_PROGRESS);
    Revenue *revenue = new Revenue(1, order, Date(1,1,2025), 100);
    financialContainer->addRevenue(*revenue);
    testing::internal::CaptureStdout();
    financialContainer->removeRevenue(1);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(financialContainer->listRevenue().size(), 0);
    delete order;
    delete revenue;
}

//listRevenues

//listTransactions

//showBalance