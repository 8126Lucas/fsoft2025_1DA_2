//
// Created by dinis on 5/23/25.
//
#include <iostream>
#include "OrderView.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"
#include "Utils.h"
#include "Order.h"
#include "OrderContainer.h"

using namespace std;

Order OrderView::addOrder() {
  Order order = Order();
  return order;
}

Order *OrderView::getOrder(OrderContainer *container) {
  int orderId = Utils::getInt("Order ID");
  Order *order = container->get(orderId);
  return order;
}

void OrderView::printOrder(Order *order) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            cout << "*** Order " << order->getOrderId() << " ***\n";
            cout << "Client Id: " << order->getClientId() << endl;
            cout << "Date: " << order->getDate() << endl;
            cout << "Source Address: " << order->getSourceAddress() << endl;
            cout << "Destination Address: " << order->getDestinationAddress() << endl;
            cout << "Cargo Space (m³): " << order->getCargoSpace() << endl;
            cout << "CargoWeight (Kg): " << order->getCargoWeight() << endl;
            cout << "ShippingValue (€): " << order->getShippingValue() << endl;
            if (order->getStatus() == IN_PROGRESS ) {
                cout << "Status: Not delivered\n";
            }
            else {cout << "Availability: Delivered\n";}
            cout << "Delivered in Address: " << order->getSourceAddress() << endl;
            cout << "In date: " << order->getDate() << endl;//ver esta cena do date para saber como usar a nova date
            cout << "The Order Id was: " << order->getOrderId() << endl;
        } catch (NonExistingDataException &error) {
            flag_error = true;
        }
    } while (flag_error);
}

void OrderView::printOrders(list<Order> &orders) {
  list<Order>::iterator it = orders.begin();
  for (; it != orders.end(); ++it) {
    printOrder(&*it);
  }

}