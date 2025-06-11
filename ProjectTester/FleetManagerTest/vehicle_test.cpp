//
// Created by lucas on 11/06/2025.
//

#include "Vehicle.h"
#include "Truck.h"
#include "Van.h"
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

class TruckTest : public testing::Test {
protected:
    void SetUp() override {
        truck = new Truck;
    }
    void TearDown() override {
        delete truck;
        truck = nullptr;
    }
    Truck *truck;
};

class VanTest : public testing::Test {
protected:
    void SetUp() override {
        van = new Van;
    }
    void TearDown() override {
        delete van;
        van = nullptr;
    }
    Van *van;
};

// Vehicle
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
    EXPECT_NE(vehicle->getInsurance(), nullptr);

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
    EXPECT_NE(vehicle->getInspection(), nullptr);

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

// Truck
TEST_F(TruckTest, EmptyConstructorInicialization) {
    EXPECT_EQ(truck->getCategory(), CATEGORY::TRUCK);
    EXPECT_EQ(truck->getBrand(), "");
    EXPECT_EQ(truck->getModel(), "");
    EXPECT_EQ(truck->getYear(), 0);
    EXPECT_EQ(truck->getLicensePlate(), "");
    EXPECT_EQ(truck->getMileage(), 0);
    EXPECT_EQ(truck->getFuel(), 0);
    EXPECT_TRUE(truck->getAvailability());
    EXPECT_EQ(truck->getWeightCapacity(), 0);
    EXPECT_EQ(truck->getInsurance(), nullptr);
    EXPECT_EQ(truck->getInspection(), nullptr);
    EXPECT_EQ(truck->getVSL(), nullptr);
}

TEST_F(TruckTest, CreateTruck) {
    truck->setCategory(TRUCK);
    truck->setBrand("Dacia");
    truck->setModel("Duster");
    truck->setYear(2025);
    truck->setLicensePlate("AA-00-BB");
    truck->setMileage(15.8);
    truck->setFuel(76.35);
    truck->setWeightCapacity(27.87);

    EXPECT_EQ(truck->getCategory(), TRUCK);
    EXPECT_EQ(truck->getBrand(), "Dacia");
    EXPECT_EQ(truck->getModel(), "Duster");
    EXPECT_EQ(truck->getYear(), 2025);
    EXPECT_EQ(truck->getLicensePlate(), "AA-00-BB");
    EXPECT_EQ(truck->getMileage(), 15.8);
    EXPECT_EQ(truck->getFuel(), 76.35);
    EXPECT_TRUE(truck->getAvailability());
    EXPECT_EQ(truck->getWeightCapacity(), 27.87);
    EXPECT_EQ(truck->getInsurance(), nullptr);
    EXPECT_EQ(truck->getInspection(), nullptr);
    EXPECT_EQ(truck->getVSL(), nullptr);
}

// Van
TEST_F(VanTest, EmptyConstructorInicialization) {
    EXPECT_EQ(van->getCategory(), CATEGORY::VAN);
    EXPECT_EQ(van->getBrand(), "");
    EXPECT_EQ(van->getModel(), "");
    EXPECT_EQ(van->getYear(), 0);
    EXPECT_EQ(van->getLicensePlate(), "");
    EXPECT_EQ(van->getMileage(), 0);
    EXPECT_EQ(van->getFuel(), 0);
    EXPECT_TRUE(van->getAvailability());
    EXPECT_EQ(van->getSpaceCapacity(), 0);
    EXPECT_EQ(van->getInsurance(), nullptr);
    EXPECT_EQ(van->getInspection(), nullptr);
    EXPECT_EQ(van->getVSL(), nullptr);
}

TEST_F(VanTest, CreateVan) {
    van->setCategory(VAN);
    van->setBrand("Fiat");
    van->setModel("Punto");
    van->setYear(2006);
    van->setLicensePlate("65-7U-TY");
    van->setMileage(876543);
    van->setFuel(45.7);
    van->setSpaceCapacity(0.764);

    EXPECT_EQ(van->getCategory(), VAN);
    EXPECT_EQ(van->getBrand(), "Fiat");
    EXPECT_EQ(van->getModel(), "Punto");
    EXPECT_EQ(van->getYear(), 2006);
    EXPECT_EQ(van->getLicensePlate(), "65-7U-TY");
    EXPECT_EQ(van->getMileage(), 876543);
    EXPECT_EQ(van->getFuel(), 45.7);
    EXPECT_TRUE(van->getAvailability());
    EXPECT_EQ(van->getSpaceCapacity(), 0.764);
    EXPECT_EQ(van->getInsurance(), nullptr);
    EXPECT_EQ(van->getInspection(), nullptr);
    EXPECT_EQ(van->getVSL(), nullptr);
}