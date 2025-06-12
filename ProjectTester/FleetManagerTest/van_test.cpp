//
// Created by lucas on 12/06/2025.
//

#include "Van.h"
#include "gtest/gtest.h"

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