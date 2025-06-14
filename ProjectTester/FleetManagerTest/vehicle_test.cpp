//
// Created by lucas on 11/06/2025.
//

#include "Vehicle.h"
#include "Insurance.h"
#include "Inspection.h"
#include "Trip.h"
#include "gtest/gtest.h"

class VehicleTest : public testing::Test {
protected:
    void SetUp() override {
        vehicle = new Vehicle;
    }
    void TearDown() override {
        delete vehicle;
        vehicle = nullptr;
    }
    Vehicle *vehicle;
};

TEST_F(VehicleTest, FuelVehicle) {
    vehicle->setFuel(20);
    EXPECT_EQ(vehicle->getFuel(), 20);
    vehicle->addFuel(50);
    EXPECT_EQ(vehicle->getFuel(), 70);
}

TEST_F(VehicleTest, UpdateMileage) {
    Trip *testTrip = new Trip();
    testTrip->setKM(150.65);
    vehicle->setMileage(90);
    vehicle->updateMileage(*testTrip);
    EXPECT_EQ(vehicle->getMileage(), 90 + 150.65);
}

TEST_F(VehicleTest, IsAvailable) {
    vehicle->setAvailability(false);
    EXPECT_FALSE(vehicle->isAvailable());
}

TEST_F(VehicleTest, FuelIsEnough) {
    Trip *trip = new Trip();
    trip->setFuel(58);
    vehicle->setFuel(60);
    EXPECT_TRUE(vehicle->isFuelEnough(*trip));
}

TEST_F(VehicleTest, FuelIsNotEnough) {
    Trip *trip = new Trip();
    trip->setFuel(67);
    vehicle->setFuel(60);
    EXPECT_FALSE(vehicle->isFuelEnough(*trip));
}

// Insurance
TEST_F(VehicleTest, AddInsurance) {
    Insurance *testInsurance = new Insurance();
    testInsurance->setID(1);
    testInsurance->setVehicle(vehicle);
    Date startDate(1,1,2020);
    testInsurance->setStartDate(startDate);
    Date endDate(1, 1, 2100);
    testInsurance->setEndDate(endDate);
    testInsurance->setMonthlyCost(100.99);
    vehicle->setInsurance(testInsurance);
    EXPECT_EQ(testInsurance->getID(), 1);
    EXPECT_EQ(testInsurance->getStartDate(), startDate);
    EXPECT_EQ(testInsurance->getEndDate(), endDate);
    EXPECT_EQ(testInsurance->getMonthlyCost(), 100.99);
    EXPECT_EQ(vehicle->getInsurance(), testInsurance);
    delete testInsurance;
}

TEST_F(VehicleTest, InsuranceExpiredMinus) {
    Date startDate(1, 1, 2025);
    Date endDate(1, 6, 2025);
    Insurance *testInsurance = new Insurance(1, vehicle, startDate, endDate, 99.99);
    EXPECT_TRUE(testInsurance->isExpired());
    delete testInsurance;
}

TEST_F(VehicleTest, InsuranceExpiredToday) {
    Date startDate(1, 1, 2025);
    Date endDate = Date::getToday();
    Insurance *testInsurance = new Insurance(1, vehicle, startDate, endDate, 99.99);
    EXPECT_TRUE(testInsurance->isExpired());
    delete testInsurance;
}

TEST_F(VehicleTest, InsuranceRemainingDays) {
    Date startDate(1, 1, 2025);
    Date endDate = Date::getToday();
    Insurance *testInsurance = new Insurance(1, vehicle, startDate, endDate, 99.99);
    EXPECT_EQ(testInsurance->getRemainingDays(), 0);
    delete testInsurance;
}

// Inspection
TEST_F(VehicleTest, AddInspection) {
    Inspection *testInspection = new Inspection();
    testInspection->setID(1);
    testInspection->setVehicle(vehicle);
    Date date(1,1,2031);
    testInspection->setDate(date);
    testInspection->setCost(10.99);
    vehicle->setInspection(testInspection);
    EXPECT_EQ(testInspection->getID(), 1);
    EXPECT_EQ(testInspection->getDate(), date);
    EXPECT_EQ(testInspection->getCost(), 10.99);
    EXPECT_EQ(vehicle->getInspection(), testInspection);
    delete testInspection;
}

TEST_F(VehicleTest, InspectionDuedMinus) {
    Date date(1, 6, 2025);
    Inspection *testInspection = new Inspection(1, vehicle, date, 19.99);
    EXPECT_TRUE(testInspection->isDued());
    delete testInspection;
}

TEST_F(VehicleTest, InspectionExpiredToday) {
    Date date = Date::getToday();
    Inspection *testInspection = new Inspection(1, vehicle, date, 19.99);
    EXPECT_TRUE(testInspection->isDued());
    delete testInspection;
}

TEST_F(VehicleTest, InspectionRemainingDays) {
    Date date = Date::getToday();
    Inspection *testInspection = new Inspection(1, vehicle, date, 19.99);
    testInspection->updateToday();
    EXPECT_EQ(testInspection->getRemainingDays(), 0);
    delete testInspection;
}
