//
// Created by Vitor Teixeira on 08/06/2025.
//
#include "Trip.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"

class TripTest : public ::testing::Test {
  protected:
    void SetUp() override {
      trip = new Trip;
    }
    void TearDown() override {
      delete trip;
      trip = nullptr;
    }
    Trip *trip;
};

TEST_F(TripTest, ConstructorAndInicialization){
  //Assert
  EXPECT_EQ(trip->getID(), 0);
  EXPECT_EQ(trip->getState(), STATE::SUPRESSED);
  EXPECT_EQ(trip->getOrder(), nullptr);
  EXPECT_EQ(trip->getDriver(), nullptr);
  EXPECT_EQ(trip->getVehicle(), nullptr);
  EXPECT_EQ(trip->getKM(), 0);
  EXPECT_EQ(trip->getFuel(), 0);
  EXPECT_EQ(trip->getFuelCost(), 0);
  EXPECT_EQ(trip->getTolls(), 0);
  EXPECT_EQ(trip->getFines(), 0);
}

TEST_F(TripTest, TestSetTrip){
  //Arrange
  Order* testOrder = new Order();
  Driver* testDriver = new Driver();
  Vehicle* testVehicle = new Vehicle();

  //Act
  trip->setOrder(testOrder);
  trip->setDriver(testDriver);
  trip->setVehicle(testVehicle);
  trip->setKM(30.3);
  trip->setFuel(20.5);
  trip->setFuelCost(100.0);
  trip->setTolls(50.4);
  trip->setFines(1000.0);

  //Assert
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

TEST_F(TripTest, TripSuppressedState){
  Trip* testTrip = new Trip();
  //ASSERT
  EXPECT_EQ(testTrip->getState(), STATE::SUPRESSED);
}

TEST_F(TripTest, TripIncomingState){
  //ARRANGE
  Driver* testDriver = new Driver();
  Order* testOrder = new Order();
  Vehicle* testVehicle = new Vehicle();
  trip->setDriver(testDriver);
  trip->setOrder(testOrder);
  trip->setVehicle(testVehicle);
  trip->setState(STATE::INCOMING);
  //ASSERT
  EXPECT_EQ(trip->getState(), STATE::INCOMING);

  delete testDriver;
  delete testOrder;
  delete testVehicle;
}

TEST_F(TripTest, TripDeliveredState){
  //ARRANGE
  Driver* testDriver = new Driver();
  Order* testOrder = new Order();
  Vehicle* testVehicle = new Vehicle();

  trip->setDriver(testDriver);
  trip->setOrder(testOrder);
  trip->setVehicle(testVehicle);
  trip->setState(STATE::INCOMING);
  trip->setKM(100);
  trip->setFuel(10);
  trip->setFuelCost(100);
  trip->setTolls(50.4);
  trip->setFines(1000.0);
  trip->setState(STATE::DELIVERED);

  //ASSERT
  EXPECT_EQ(trip->getState(), STATE::DELIVERED);

  delete testDriver;
  delete testOrder;
  delete testVehicle;
}

TEST_F(TripTest, TripFailedState){
  trip->setState(FAILED);
  EXPECT_EQ(trip->getState(), STATE::FAILED);
}