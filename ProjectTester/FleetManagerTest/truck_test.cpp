//
// Created by lucas on 12/06/2025.
//

#include "Truck.h"
#include "gtest/gtest.h"


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