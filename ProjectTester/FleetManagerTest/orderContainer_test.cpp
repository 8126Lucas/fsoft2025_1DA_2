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
    EXPECT_EQ(output, "!! Error: \"Order (id): 1\" duplicated !!\n");
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
    EXPECT_EQ(output, "!! Error: \"Order (id): 1\" does not exist !!\n");
    EXPECT_EQ(orderContainer->listOrders().size(), 0);
}

TEST_F(OrderContainerTest, TestListOrders) {
    Order *order1 = new Order(1, 500, Date(), "Porto", "Lisbon", 50, 500, 2500, COMPLETED);
    Order *order2 = new Order(2, 600, Date(), "Porto", "Lisbon", 60, 600, 3000, IN_PROGRESS);
    orderContainer->add(*order1);
    orderContainer->add(*order2);
    list<Order> Orders = orderContainer->listOrders();
    EXPECT_EQ(Orders.size(), 2);
    delete order1;
    delete order2;
}

TEST_F(OrderContainerTest, TestUncompletedOrders) {
    Order *order1 = new Order(1, 300, Date(), "Porto", "Lisbon", 30, 300, 1500, IN_PROGRESS);
    Order *order2 = new Order(2, 400, Date(), "Porto", "Lisbon", 40, 400, 2000, COMPLETED);
    Order *order3 = new Order(3, 500, Date(), "Porto", "Lisbon", 50, 500, 2500, COMPLETED);
    order2->setStatus(IN_PROGRESS);
    orderContainer->add(*order1);
    orderContainer->add(*order2);
    orderContainer->add(*order3);
    list<Order> uncompletedOrders = orderContainer->listUncompleted();
    EXPECT_EQ(uncompletedOrders.size(), 2);
    delete order1;
    delete order2;
    delete order3;
}

TEST_F(OrderContainerTest, TestCompletedOrders) {
    Order *order1 = new Order(1, 300, Date(), "Porto", "Lisbon", 30, 300, 1500, IN_PROGRESS);
    Order *order2 = new Order(2, 400, Date(), "Porto", "Lisbon", 40, 400, 2000, IN_PROGRESS);
    Order *order3 = new Order(3, 500, Date(), "Porto", "Lisbon", 50, 500, 2500, COMPLETED);
    order2->setStatus(COMPLETED);
    orderContainer->add(*order1);
    orderContainer->add(*order2);
    orderContainer->add(*order3);
    list<Order> completedOrders = orderContainer->listCompleted();
    EXPECT_EQ(completedOrders.size(), 2);
    delete order1;
    delete order2;
    delete order3;
}

TEST_F(OrderContainerTest, TestOrdersByClient) {
    Order *order1 = new Order(1, 300, Date(), "Porto A", "Lisbon A", 30, 300, 1500, IN_PROGRESS);
    Order *order2 = new Order(2, 400, Date(), "Porto B", "Lisbon B", 40, 400, 2000, IN_PROGRESS);
    Order *order3 = new Order(3, 400, Date(), "Porto C", "Lisbon C", 50, 500, 2500, COMPLETED);
    orderContainer->add(*order1);
    orderContainer->add(*order2);
    orderContainer->add(*order3);
    list<Order> ordersByClient = orderContainer->listOrdersByClient(400);
    EXPECT_EQ(ordersByClient.size(), 2);
    delete order1;
    delete order2;
    delete order3;
}