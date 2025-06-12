//
// Created by ruben on 11/06/2025.
//

#include "Expense.h"
#include "Revenue.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"
#include "Date.h"

class ExpenseTest : public ::testing::Test {
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

TEST_F(ExpenseTest, ConstructorAndInicialization) {
    EXPECT_EQ(expense->getID(), 0);
    EXPECT_EQ(expense->getTrip(), nullptr);
    Date emptyDate;
    EXPECT_EQ(expense->getDate(), emptyDate);
    EXPECT_EQ(expense->getAmount(), 0.0);
    EXPECT_EQ(expense->getType(), FUEL);
}

TEST_F(ExpenseTest, testSetExpense) {
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

TEST_F(ExpenseTest, TestAllExpenseTypes) {
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

//recordExpense

TEST_F(ExpenseTest, TestRecordExpense) {

}

//removeExpense

TEST_F(ExpenseTest, TestRemoveExpense) {

}

//listExpenses

TEST_F(ExpenseTest, TestListExpenses) {

}

//listExpensesByType

TEST_F(ExpenseTest, TestListExpensesByType) {

}

class RevenueTest : public ::testing::Test {
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

TEST_F(RevenueTest, ConstructorAndInicialization) {
    EXPECT_EQ(revenue->getID(), 0);
    EXPECT_EQ(revenue->getOrder(), nullptr);
    Date emptyDate;
    EXPECT_EQ(revenue->getDate(), emptyDate);
    EXPECT_EQ(revenue->getAmount(), 0.0);
}

TEST_F(RevenueTest, testSetRevenue) {
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

//recordRevenue

TEST_F(RevenueTest, testRecordRevenue) {

}

//removeRevenue

TEST_F(RevenueTest, testRemoveRevenue) {

}

//listRevenues

TEST_F(RevenueTest, testListRevenues) {

}

//listTransactions

TEST_F(RevenueTest, testListTransactions) {

}

//showBalance

TEST_F(RevenueTest, testShowBalance) {

}