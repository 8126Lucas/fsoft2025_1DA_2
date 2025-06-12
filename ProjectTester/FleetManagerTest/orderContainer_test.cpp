#include "OrderContainer.h"
#include "Date.h"
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "NonExistingDataException.h"

class OrderContainerTest : public ::testing::Test {
protected:
    void SetUp() override {
        container = new OrderContainer();
    }

    void TearDown() override {
        delete container;
        container = nullptr;
    }

    OrderContainer* container;
};

/*TEST_F(OrderContainerTest, TestAddOrderToContainer) {
    Order tempOrder;
    tempOrder.setOrderID(1);

    container->add(tempOrder);
    EXPECT_NO_THROW(container->get(1));

    ASSERT_THROW(container->add(tempOrder), DuplicatedDataException);
}
*/

TEST_F(OrderContainerTest, TestRemoveOrderFromContainer) {
    Order tempOrder;
    tempOrder.setOrderID(1);

    container->add(tempOrder);
    EXPECT_NO_THROW(container->remove(1));

    EXPECT_THROW(container->get(1), NonExistingDataException);
}

TEST_F(OrderContainerTest, TestFindOrderInContainer) {
    Order tempOrder1(1, 100, Date(), "SOURCE A", "DESTINATION A", 0.0, 0.0, 0.0, COMPLETED);
    Order tempOrder2(2, 200, Date(), "SOURCE B", "DESTINATION B", 0.0, 0.0, 0.0, IN_PROGRESS);

    container->add(tempOrder1);
    container->add(tempOrder2);

    EXPECT_NO_THROW(container->get(2));
    EXPECT_EQ(container->get(2)->getSourceAddress(), "SOURCE B");

    EXPECT_THROW(container->get(3), NonExistingDataException);
}

TEST_F(OrderContainerTest, TestListOrders) {
    Order order1(1, 2200, Date(), "SOURCE A", "DESTINATION A", 10.0, 100.0, 500.0, COMPLETED);
    Order order2(2, 4400, Date(), "SOURCE B", "DESTINATION B", 20.0, 200.0, 1000.0, IN_PROGRESS);

    container->add(order1);
    container->add(order2);

    std::list<Order> allOrders = container->listOrders();
    EXPECT_EQ(allOrders.size(), 2);

    std::list<Order> completedOrders = container->listCompleted();
    EXPECT_EQ(completedOrders.size(), 1);
    EXPECT_EQ(completedOrders.begin()->getOrderID(), 1);

    std::list<Order> uncompletedOrders = container->listUncompleted();
    EXPECT_EQ(uncompletedOrders.size(), 1);
    EXPECT_EQ(uncompletedOrders.begin()->getOrderID(), 2);
}

TEST_F(OrderContainerTest, TestListOrdersByClient) {
    Order order1(1, 100, Date(), "Source A", "Dest A", 10.0, 100.0, 500.0, COMPLETED);
    Order order2(2, 101, Date(), "Source B", "Dest B", 20.0, 200.0, 1000.0, IN_PROGRESS);
    Order order3(3, 100, Date(), "Source C", "Dest C", 30.0, 300.0, 1500.0, IN_PROGRESS);

    container->add(order1);
    container->add(order2);
    container->add(order3);

    std::list<Order> client100Orders = container->listOrdersByClient(100);
    EXPECT_EQ(client100Orders.size(), 2);

    std::list<Order> client101Orders = container->listOrdersByClient(101);
    EXPECT_EQ(client101Orders.size(), 1);
}