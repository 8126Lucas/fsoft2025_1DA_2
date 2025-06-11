//
// Created by ruben on 10/06/2025.
//
#include "Driver.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"
#include "Date.h"
#include "Vacation.h"

class driverTest : public ::testing::Test {
protected:
    void SetUp() override {
        //int id = 1;
        //char license = 'C';
        //int age = 30;
        driver = new Driver();
    }

    void TearDown() override {
        delete driver;
        driver = nullptr;
    }
    Driver* driver;
};

TEST_F(driverTest, ConstructorAndInicialization) {
    EXPECT_EQ(driver->getID(), 0);
    EXPECT_EQ(driver->getLicense(), '\0');
    EXPECT_EQ(driver->getAge(), 0);
    EXPECT_TRUE(driver->getAvailability());
    EXPECT_TRUE(driver->getVacations().empty());
    EXPECT_EQ(driver->getTimeToRetire(), 65);
}

TEST_F(driverTest, TestSetDriver) {
    int newId = 100;
    char newLicense = 'B';
    int newAge = 40;
    int newTimeToRetire = 65 - newAge;
    bool newAvailability = false;

    driver->setID(newId);
    driver->setLicense(newLicense);
    driver->setAge(newAge);
    driver->setTimeToRetire(newTimeToRetire);
    driver->setAvailability(newAvailability);
    //vacations?

    EXPECT_EQ(driver->getID(), newId);
    EXPECT_EQ(driver->getLicense(), newLicense);
    EXPECT_EQ(driver->getAge(), newAge);
    EXPECT_EQ(driver->getTimeToRetire(), newTimeToRetire);
    EXPECT_FALSE(driver->getAvailability());
}