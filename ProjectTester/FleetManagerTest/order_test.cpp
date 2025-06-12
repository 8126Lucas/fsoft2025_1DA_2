//
// Created by dinis on 6/11/25.
//
#include "Order.h"
#include "OrderContainer.h"
#include "Date.h"
#include "gtest/gtest.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"

class OrderTest : public ::testing::Test {
protected:
    void SetUp() override {
        order = new Order();
    }

    void TearDown() override {
        delete order;
        order = nullptr;
    }

    Order* order;
};


TEST_F(OrderTest, ConstructorAndInicialization) {
    EXPECT_EQ(order->getOrderID(), 0);
    EXPECT_EQ(order->getClientID(), 0);
    EXPECT_EQ(order->getSourceAddress(), "");
    EXPECT_EQ(order->getDestinationAddress(), "");
    EXPECT_EQ(order->getCargoSpace(), 0.0);
    EXPECT_EQ(order->getCargoWeight(), 0.0);
    EXPECT_EQ(order->getShippingValue(), 0.0);
    EXPECT_EQ(order->getStatus(), IN_PROGRESS);
}

TEST_F(OrderTest, TestSetOrder) {
    order->setOrderID(123);
    order->setClientID(456);
    order->setSourceAddress("Source Address");
    order->setDestinationAddress("Destination Address");
    order->setCargoSpace(50.0);
    order->setCargoWeight(75.5);
    order->setShippingValue(1000.0);
    order->setStatus(COMPLETED);

    EXPECT_EQ(order->getOrderID(), 123);
    EXPECT_EQ(order->getClientID(), 456);
    EXPECT_EQ(order->getSourceAddress(), "Source Address");
    EXPECT_EQ(order->getDestinationAddress(), "Destination Address");
    EXPECT_EQ(order->getCargoSpace(), 50.0);
    EXPECT_EQ(order->getCargoWeight(), 75.5);
    EXPECT_EQ(order->getShippingValue(), 1000.0);
    EXPECT_EQ(order->getStatus(), COMPLETED);
}

TEST_F(OrderTest, TestOrderStatusDefault) {
    Order* newOrder = new Order();
    EXPECT_EQ(newOrder->getStatus(), IN_PROGRESS);
    delete newOrder;
}

TEST_F(OrderTest, TestOrderStatusChange) {
    order->setStatus(COMPLETED);
    EXPECT_EQ(order->getStatus(), COMPLETED);

    order->setStatus(IN_PROGRESS);
    EXPECT_EQ(order->getStatus(), IN_PROGRESS);
}

