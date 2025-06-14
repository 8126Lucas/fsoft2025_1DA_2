#include "OrderContainer.h"
#include "Date.h"
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"

class OrderContainerTest : public ::testing::Test {
protected:
    void SetUp() override {
        orderContainer = new OrderContainer();
    }

    void TearDown() override {
        delete orderContainer;
        orderContainer = nullptr;
    }

    OrderContainer* orderContainer;
};

TEST_F(OrderContainerTest, AddValidOrder) {
    Order order(1, 100, Date(), "Porto", "Lisbon", 10, 100, 500, IN_PROGRESS);
    testing::internal::CaptureStdout();
    orderContainer->add(order);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(orderContainer->listOrders().size(), 1);
}

TEST_F(OrderContainerTest, AddDuplicatedOrder) {
    Order order(1, 100, Date(), "Porto", "Lisbon", 10, 100, 500, IN_PROGRESS);
    orderContainer->add(order);
    testing::internal::CaptureStdout();
    orderContainer->add(order);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Order: 1\" duplicated !!\n");
    EXPECT_EQ(orderContainer->listOrders().size(), 1);
}

TEST_F(OrderContainerTest, RemoveValidOrder) {
    Order order(1, 100, Date(), "Porto", "Lisbon", 10, 100, 500, IN_PROGRESS);
    orderContainer->add(order);
    testing::internal::CaptureStdout();
    orderContainer->remove(1);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(orderContainer->listOrders().size(), 0);
}

TEST_F(OrderContainerTest, RemoveNonExistingOrder) {
    testing::internal::CaptureStdout();
    orderContainer->remove(1);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Order: 1\" does not exist !!\n");
    EXPECT_EQ(orderContainer->listOrders().size(), 0);
}