//
// Created by Vitor Teixeira on 08/06/2025.
//
#include "Trip.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicateDataException.h"

class tripTest : public ::testing::Test {
  protected:
    SetUp() override {
      trip = new Trip(1);
    }
    void TearDown() override {
      delete trip;
      trip = nullptr;
    }
    Trip *trip;
}

TEST_F(TripTest, ConstructorAndInicialization){
  EXPECT_EQ(trip->getTripID(), 1);
  EXPECT_EQ(trip->getState(), TripState::INCOMING);
  EXPECT_EQ(trip->getOrderID(), nullptr);
  EXPECT_EQ(trip->getDriver(), nullptr);
  EXPECT_EQ(trip->getVehicle(), nullptr);
  EXPECT_EQ(trip->getKM(), 0);
  EXPECT_EQ(trip->getFuel(), 0);
  EXPECT_EQ(trip->getFuelCost(), 0);
  EXPECT_EQ(trip->getTolls(), 0);
  EXPECT_EQ(trip->getFines(), 0);
}

TEST_F(TripTest, TestSetTrip){
  Order* order = new Order();
  Driver* driver = new Driver();
  Vehicle* vehicle = new Vehicle();

  trip->setOrder(testOrder );
  trip->setDriver(testDriver);
  trip->setVehicle(testVehicle);
  trip->setKM(30.3);
  trip->setFuel(20.5);
  trip->setFuelCost(100.0);
  trip->setTolls(50.4);
  trip->setFines(1000.0);


  EXPECT_EQ(trip->getOrder(), testOrder);
  EXPECT_EQ(trip->getDriver(), testDriver);
  EXPECT_EQ(trip->getVehicle(), testVehicle);
  EXPECT_DOUBLE_EQ(trip->getKM(), 30.3);
  EXPECT_DOUBLE_EQ(trip->getFuel(), 20.5);
  EXPECT_DOUBLE_EQ(trip->getFuelCost(), 100.0);
  EXPECT_DOUBLE_EQ(trip->getTolls(), 50.4);
  EXPECT_DOUBLE_EQ(trip->getFines(), 1000.0);

  delete testOrder;
  delete testDriver;
  delete testVehicle;
}
