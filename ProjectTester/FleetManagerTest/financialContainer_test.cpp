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
    Order* order = new Order(1, 1, Date(1,1,2025), "Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
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
    Order* order = new Order(1, 1, Date(1,1,2025), "Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
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

TEST_F(FinancialContainerTest, RemoveValidExpense) {
    Order* order = new Order(1, 1, Date(1,1,2025), "Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
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

TEST_F(FinancialContainerTest, RemoveNonExistingExpense) {
    testing::internal::CaptureStdout();
    financialContainer->removeExpense(1);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Expense (id): 1\" does not exist !!\n");
    EXPECT_EQ(financialContainer->listExpense().size(), 0);
}

TEST_F(FinancialContainerTest, TestListExpenses) {
    Trip *trip = new Trip();
    Expense *expense1 = new Expense(1, trip, Date(1,1,2025), 100.50, FUEL);
    Expense *expense2 = new Expense(2, trip, Date(2,1,2025), 200.75, TOLL);
    Expense *expense3 = new Expense(3, trip, Date(3,1,2025), 150.25, INSPECTION);
    financialContainer->addExpense(*expense1);
    financialContainer->addExpense(*expense2);
    financialContainer->addExpense(*expense3);
    list<Expense> expenses = financialContainer->listExpense();
    EXPECT_EQ(expenses.size(), 3);
    delete trip;
    delete expense1;
    delete expense2;
    delete expense3;
}

TEST_F(FinancialContainerTest, TestListExpensesByType) {
    Trip *trip = new Trip();
    Expense *expenseFuel1 = new Expense(1, trip, Date(1,1,2025), 100.50, FUEL);
    Expense *expenseFuel2 = new Expense(2, trip, Date(2,1,2025), 150.75, FUEL);
    Expense *expenseInspection = new Expense(3, trip, Date(3,1,2025), 200.00, INSPECTION);
    Expense *expenseInsurance = new Expense(4, trip, Date(4,1,2025), 500.00, INSURANCE);
    Expense *expenseToll1 = new Expense(5, trip, Date(5,1,2025), 25.50, TOLL);
    Expense *expenseToll2 = new Expense(6, trip, Date(6,1,2025), 30.00, TOLL);
    Expense *expenseFine = new Expense(7, trip, Date(7,1,2025), 150.00, FINE);
    financialContainer->addExpense(*expenseFuel1);
    financialContainer->addExpense(*expenseFuel2);
    financialContainer->addExpense(*expenseInspection);
    financialContainer->addExpense(*expenseInsurance);
    financialContainer->addExpense(*expenseToll1);
    financialContainer->addExpense(*expenseToll2);
    financialContainer->addExpense(*expenseFine);
    list<Expense> fuelExpenses = financialContainer->listExpensesByType(FUEL);
    EXPECT_EQ(fuelExpenses.size(), 2);
    list<Expense> inspectionExpenses = financialContainer->listExpensesByType(INSPECTION);
    EXPECT_EQ(inspectionExpenses.size(), 1);
    list<Expense> insuranceExpenses = financialContainer->listExpensesByType(INSURANCE);
    EXPECT_EQ(insuranceExpenses.size(), 1);
    list<Expense> tollExpenses = financialContainer->listExpensesByType(TOLL);
    EXPECT_EQ(tollExpenses.size(), 2);
    list<Expense> fineExpenses = financialContainer->listExpensesByType(FINE);
    EXPECT_EQ(fineExpenses.size(), 1);
    delete trip;
    delete expenseFuel1;
    delete expenseFuel2;
    delete expenseInspection;
    delete expenseInsurance;
    delete expenseToll1;
    delete expenseToll2;
    delete expenseFine;
}

TEST_F(FinancialContainerTest, RecordValidRevenue) {
    Order *order = new Order(1, 1, Date(1,1,2025),"Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
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
    Order *order = new Order(1, 1, Date(1,1,2025),"Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
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

TEST_F(FinancialContainerTest, RemoveValidRevenue) {
    Order *order = new Order(1, 1, Date(1,1,2025),"Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
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

TEST_F(FinancialContainerTest, RemoveNonExistingRevenue) {
    testing::internal::CaptureStdout();
    financialContainer->removeRevenue(1);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Revenue (id): 1\" does not exist !!\n");
    EXPECT_EQ(financialContainer->listRevenue().size(), 0);
}

TEST_F(FinancialContainerTest, TestListRevenues) {
    Order *order1 = new Order(1, 1, Date(1,1,2025), "Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
    Order *order2 = new Order(2, 2, Date(2,1,2025), "Lisbon", "Porto", 12, 18, 150, IN_PROGRESS);
    Order *order3 = new Order(3, 3, Date(3,1,2025), "Braga", "Faro", 15, 20, 200, IN_PROGRESS);
    Revenue *revenue1 = new Revenue(1, order1, Date(1,1,2025), 100.00);
    Revenue *revenue2 = new Revenue(2, order2, Date(2,1,2025), 150.00);
    Revenue *revenue3 = new Revenue(3, order3, Date(3,1,2025), 200.00);
    financialContainer->addRevenue(*revenue1);
    financialContainer->addRevenue(*revenue2);
    financialContainer->addRevenue(*revenue3);
    list<Revenue> revenues = financialContainer->listRevenue();
    EXPECT_EQ(revenues.size(), 3);
    delete order1;
    delete order2;
    delete order3;
    delete revenue1;
    delete revenue2;
    delete revenue3;
}

TEST_F(FinancialContainerTest, TestListTransactions) {
    Trip *trip = new Trip();
    Order *order1 = new Order(1, 1, Date(1,1,2025), "Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
    Order *order2 = new Order(2, 2, Date(2,1,2025), "Lisbon", "Porto", 12, 18, 150, IN_PROGRESS);
    Expense *expense1 = new Expense(1, trip, Date(1,1,2025), 100, FUEL);
    Expense *expense2 = new Expense(2, trip, Date(15,1,2025), 200, TOLL);
    Expense *expense3 = new Expense(3, trip, Date(31,1,2025), 150, INSPECTION);
    Revenue *revenue1 = new Revenue(1, order1, Date(5,1,2025), 300);
    Revenue *revenue2 = new Revenue(2, order2, Date(20,1,2025), 450);
    financialContainer->addExpense(*expense1);
    financialContainer->addExpense(*expense2);
    financialContainer->addExpense(*expense3);
    financialContainer->addRevenue(*revenue1);
    financialContainer->addRevenue(*revenue2);
    double totalExpenses = financialContainer->getExpensesTotal(Date(1,1,2025), Date(31,1,2025));
    EXPECT_DOUBLE_EQ(totalExpenses, 450);
    double totalRevenues = financialContainer->getRevenuesTotal(Date(1,1,2025), Date(31,1,2025));
    EXPECT_DOUBLE_EQ(totalRevenues, 750);
    double balance = financialContainer->getBalance(Date(1,1,2025), Date(31,1,2025));
    EXPECT_DOUBLE_EQ(balance, 300);
    delete trip;
    delete order1;
    delete order2;
    delete expense1;
    delete expense2;
    delete expense3;
    delete revenue1;
    delete revenue2;
}

TEST_F(FinancialContainerTest, TestShowBalance) {
    Trip *trip = new Trip();
    Order *order1 = new Order(1, 1, Date(1,1,2025), "Porto", "Lisbon", 10, 15, 100, IN_PROGRESS);
    Order *order2 = new Order(2, 2, Date(2,2,2025), "Lisbon", "Porto", 12, 18, 150, IN_PROGRESS);
    Expense *expense1 = new Expense(1, trip, Date(1,1,2025), 100, FUEL);
    Expense *expense2 = new Expense(2, trip, Date(15,2,2025), 200, TOLL);
    Revenue *revenue1 = new Revenue(1, order1, Date(5,1,2025), 300);
    Revenue *revenue2 = new Revenue(2, order2, Date(20,2,2025), 450);
    financialContainer->addExpense(*expense1);
    financialContainer->addExpense(*expense2);
    financialContainer->addRevenue(*revenue1);
    financialContainer->addRevenue(*revenue2);
    EXPECT_DOUBLE_EQ(financialContainer->getBalance(Date(1,1,2025), Date(31,1,2025)), 200);
    EXPECT_DOUBLE_EQ(financialContainer->getBalance(Date(1,2,2025), Date(28,2,2025)), 250);
    EXPECT_DOUBLE_EQ(financialContainer->getBalance(Date(1,1,2025), Date(28,2,2025)), 450);
    delete trip;
    delete order1;
    delete order2;
    delete expense1;
    delete expense2;
    delete revenue1;
    delete revenue2;
}