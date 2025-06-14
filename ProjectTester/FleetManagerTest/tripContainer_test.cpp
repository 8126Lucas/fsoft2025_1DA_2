//
// Created by Vitor Teixeira on 12/06/2025.
//
#include "TripContainer.h"
#include "Trip.h"
#include "Vehicle.h"
#include "Order.h"
#include "OrderContainer.h"
#include "gtest/gtest.h"


class TripContainerTest : public ::testing::Test{
  protected:
    void SetUp() override {
      tripContainer = new TripContainer();
    }
    void TearDown() override {
      delete tripContainer;
      tripContainer = nullptr;
    }
    TripContainer *tripContainer;
};


TEST_F(TripContainerTest, addValidTrip){
  Order *order = new Order();
  Trip *trip = new Trip(order, 10, 0.4, 1, 1,40,10);
  trip->setID(1);
  trip->setState(SUPRESSED);
  tripContainer->add(*trip);
  testing::internal::CaptureStdout();
  string output = testing::internal::GetCapturedStdout();
  string success_mesage;
  EXPECT_EQ(output, success_mesage);
  delete order;
}

TEST_F(TripContainerTest, duplicatedTrip) {
  Order *order = new Order();
  Trip *trip = new Trip(order, 10, 0.4, 1, 1,40,10);
  trip->setID(1);
  trip->setState(SUPRESSED);
  tripContainer->add(*trip);
  testing::internal::CaptureStdout();
  string output = testing::internal::GetCapturedStdout();
  string success_mesage;
  ASSERT_EQ(output, success_mesage);

  Trip *trip2 = new Trip(order, 10, 3, 4, 2,1,2);
  trip2->setID(1);
  trip2->setState(SUPRESSED);
  tripContainer->add(*trip2);
  testing::internal::CaptureStdout();
  string output2 = testing::internal::GetCapturedStdout();
  string success_mesage2;
  EXPECT_EQ(tripContainer->listTrips().size(), 1);
  EXPECT_EQ(output, success_mesage);
}

TEST_F(TripContainerTest, updateTrip) {
  Order *order = new Order();
  Trip *trip = new Trip(order, 10, 0.4, 1, 1,40,10);
  trip->setID(1);
  trip->setState(SUPRESSED);
  tripContainer->add(*trip);
  testing::internal::CaptureStdout();
  trip->setState(FAILED);
  tripContainer->update(*trip);
  string output = testing::internal::GetCapturedStdout();
  string success_mesage;
  EXPECT_EQ(output, success_mesage);
}

TEST_F(TripContainerTest, listTrips) {
  Order *order = new Order();
  Trip *trip = new Trip(order, 10, 0.4, 1, 1,40,10);
  Trip *trip2 = new Trip(order, 0.2, 4, 3, 10.00,2039,0);
  Trip *trip3 = new Trip(order, 0, 0, 0, 0,0,0);
  trip->setID(1);
  trip2->setID(2);
  trip3->setID(3);
  trip->setState(SUPRESSED);
  trip2->setState(SUPRESSED);
  trip3->setState(SUPRESSED);
  tripContainer->add(*trip);
  tripContainer->add(*trip2);
  tripContainer->add(*trip3);
  testing::internal::CaptureStdout();
  string output = testing::internal::GetCapturedStdout();
  string success_mesage;
  EXPECT_EQ(tripContainer->listTrips().size(), 3);
}

TEST_F(TripContainerTest, listTripsByState) {
  Order *order = new Order();
  Trip *trip = new Trip(order, 10, 0.4, 1, 1,40,10);
  Trip *trip2 = new Trip(order, 0, 0, 0, 0,0,0);
  Trip *trip3 = new Trip(order, 100, 100, 0.1, 0.200,0.2034,0.00);
  trip->setID(1);
  trip2->setID(2);
  trip3->setID(3);
  trip->setState(SUPRESSED);
  trip2->setState(FAILED);
  trip3->setState(SUPRESSED);
  tripContainer->add(*trip);
  tripContainer->add(*trip2);
  tripContainer->add(*trip3);
  std::list<Trip> trips = tripContainer->listTripsByState(SUPRESSED);
  EXPECT_EQ(trips.size(), 2);
  EXPECT_EQ(trip->getState(), SUPRESSED);
}