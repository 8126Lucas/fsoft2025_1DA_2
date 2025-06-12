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

// Fixture class for testing Order
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

/*TEST_F(OrderTest, TestAddOrderToContainer) {
    OrderContainer container;
    Order tempOrder;
    tempOrder.setOrderID(1);

    container.add(tempOrder);
    EXPECT_NO_THROW(container.get(1));

    ASSERT_THROW(container.add(tempOrder), DuplicatedDataException);
}*/

TEST_F(OrderTest, TestRemoveOrderFromContainer) {
    OrderContainer container;
    Order Order;
    Order.setOrderID(1);
    container.add(Order);

    EXPECT_NO_THROW(container.remove(1));
    EXPECT_THROW(container.get(1), NonExistingDataException);
}

TEST_F(OrderTest, TestFindOrderInContainer) {
    OrderContainer container;
    Order tempOrder1(1, 100, Date(), "SOURCE A", "DESTINATION A", 0.0, 0.0, 0.0, COMPLETED);
    Order tempOrder2(2, 200, Date(), "SOURCE B", "DESTINATION B", 0.0, 0.0, 0.0, IN_PROGRESS);
    container.add(tempOrder1);
    container.add(tempOrder2);

    EXPECT_NO_THROW(container.get(2));
    EXPECT_EQ(container.get(2)->getSourceAddress(), "SOURCE B");
    EXPECT_THROW(container.get(3), NonExistingDataException);
}

TEST_F(OrderTest, TestListOrders) {
    OrderContainer container;
    Order order1(1, 2200, Date(), "SOURCE A", "DESTINATION A", 10.0, 100.0, 500.0, COMPLETED);
    Order order2(2, 4400, Date(), "SOURCE B", "DESTINATION B", 20.0, 200.0, 1000.0, IN_PROGRESS);

    container.add(order1);
    container.add(order2);

    std::list<Order> allOrders = container.listOrders();
    EXPECT_EQ(allOrders.size(), 2);

    std::list<Order> completedOrders = container.listCompleted();
    EXPECT_EQ(completedOrders.size(), 1);
    EXPECT_EQ(completedOrders.begin()->getOrderID(), 1);

    std::list<Order> uncompletedOrders = container.listUncompleted();
    EXPECT_EQ(uncompletedOrders.size(), 1);
    EXPECT_EQ(uncompletedOrders.begin()->getOrderID(), 2);
}

TEST_F(OrderTest, TestListOrdersByClient) {
    OrderContainer container;
    Order order1(1, 100, Date(), "Source A", "Dest A", 10.0, 100.0, 500.0, COMPLETED);
    Order order2(2, 101, Date(), "Source B", "Dest B", 20.0, 200.0, 1000.0, IN_PROGRESS);
    Order order3(3, 100, Date(), "Source C", "Dest C", 30.0, 300.0, 1500.0, IN_PROGRESS);

    container.add(order1);
    container.add(order2);
    container.add(order3);

    std::list<Order> Client100 = container.listOrdersByClient(100);
    EXPECT_EQ(Client100.size(), 2);

    std::list<Order> Client101 = container.listOrdersByClient(101);
    EXPECT_EQ(Client101.size(), 1);
}