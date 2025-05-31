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
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            int orderID = Utils::getInt("Order ID");
            int clientID = Utils::getInt("Client ID");
            Date date = Utils::getDate("Date");
            string sourceAddress = Utils::getString("Source Address");
            string destinationAddress = Utils::getString("Destination Address");
            double cargoSpace = Utils::getDouble("Cargo Space");
            double cargoWeight = Utils::getDouble("Cargo Weight");
            double shippingValue = Utils::getDouble("Shipping Value");

            order.setStatus(IN_PROGRESS);
            order.setOrderID(orderID);
            order.setClientID(clientID);
            order.setDate(date);
            order.setSourceAddress(sourceAddress);
            order.setDestinationAddress(destinationAddress);
            order.setCargoSpace(cargoSpace);
            order.setCargoWeight(cargoWeight);
            order.setShippingValue(shippingValue);
        } catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    } while (flag_error);
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
            cout << "*** Order " << order->getOrderID() << " ***\n";
            cout << "Client ID: " << order->getClientID() << endl;
            cout << "Date: " << order->getDate() << endl;
            cout << "Source Address: " << order->getSourceAddress() << endl;
            cout << "Destination Address: " << order->getDestinationAddress() << endl;
            cout << "Cargo Space (m" + to_string(char(0x00B3)) + "): " << order->getCargoSpace() << endl;
            cout << "CargoWeight (Kg): " << order->getCargoWeight() << endl;
            cout << "ShippingValue (€): " << order->getShippingValue() << endl;
            if (order->getStatus() == IN_PROGRESS ) {cout << "Status: Not delivered\n";}
            else {cout << "Status: Delivered\n";}
        } catch (NonExistingDataException &error) {
            cout << error.what() << endl;
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

void OrderView::completeOrder(Order *order) {
    bool flag_error = false;
    do {
        try {
            flag_error = false;
            order->setStatus(COMPLETED);
        }catch (InvalidDataException &error) {
            cout << error.what() << endl;
            flag_error = true;
        }
    }while (flag_error);

}
