//
// Created by ruben on 11/06/2025.
//

#include "Expense.h"
#include "Revenue.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"
#include "Date.h"

class expenseTest : public ::testing::Test {
protected:
    void SetUp() override {
        expense = new Expense;
    }
    void TearDown() override {
        delete expense;
        expense = nullptr;
    }
    Expense* expense;
};

TEST_F(expenseTest, ConstructorAndInicialization) {
    EXPECT_EQ(expense->getID(), 0);
    EXPECT_EQ(expense->getTrip(), nullptr);
    Date emptyDate;
    EXPECT_EQ(expense->getDate(), emptyDate);
    EXPECT_EQ(expense->getAmount(), 0.0);
    EXPECT_EQ(expense->getType(), FUEL);
}

TEST_F(expenseTest, testSetExpense) {
    int newId = 100;
    Trip* testTrip = new Trip();
    Date newDate(1, 1, 2025);
    double newAmount = 100.0;
    TYPE newType = INSURANCE;

    expense->setID(newId);
    expense->setTrip(testTrip);
    expense->setDate(newDate);
    expense->setAmount(newAmount);
    expense->setType(newType);

    EXPECT_EQ(expense->getID(), newId);
    EXPECT_EQ(expense->getTrip(), testTrip);
    EXPECT_EQ(expense->getDate(), newDate);
    EXPECT_DOUBLE_EQ(expense->getAmount(), newAmount);
    EXPECT_EQ(expense->getType(), newType);

    delete testTrip;
}

TEST_F(expenseTest, TestAllExpenseTypes) {
    expense->setType(FUEL);
    EXPECT_EQ(expense->getType(), FUEL);

    expense->setType(INSPECTION);
    EXPECT_EQ(expense->getType(), INSPECTION);

    expense->setType(INSURANCE);
    EXPECT_EQ(expense->getType(), INSURANCE);

    expense->setType(TOLL);
    EXPECT_EQ(expense->getType(), TOLL);

    expense->setType(FINE);
    EXPECT_EQ(expense->getType(), FINE);
}

class revenueTest : public ::testing::Test {
protected:
    void SetUp() override {
        revenue = new Revenue;
    }
    void TearDown() override {
        delete revenue;
        revenue = nullptr;
    }
    Revenue* revenue;
};

TEST_F(revenueTest, ConstructorAndInicialization) {
    EXPECT_EQ(revenue->getID(), 0);
    EXPECT_EQ(revenue->getOrder(), nullptr);
    Date emptyDate;
    EXPECT_EQ(revenue->getDate(), emptyDate);
    EXPECT_EQ(revenue->getAmount(), 0.0);
}

TEST_F(revenueTest, testSetRevenue) {
    int newId = 100;
    Order* testOrder = new Order();
    Date newDate(1, 1, 2025);
    double newAmount = 100.0;

    revenue->setID(newId);
    revenue->setOrder(testOrder);
    revenue->setDate(newDate);
    revenue->setAmount(newAmount);

    EXPECT_EQ(revenue->getID(), newId);
    EXPECT_EQ(revenue->getOrder(), testOrder);
    EXPECT_EQ(revenue->getDate(), newDate);
    EXPECT_DOUBLE_EQ(revenue->getAmount(), newAmount);

    delete testOrder;
}