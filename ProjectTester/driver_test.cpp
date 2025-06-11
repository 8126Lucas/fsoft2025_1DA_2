//
// Created by ruben on 10/06/2025.
//
#include "Driver.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicateDataException.h"
#include "Date.h"
#include "Vacation.h"

class driverTest : public ::testing::Test {
protected:
    void SetUp() override {
        int id = 1;
        char license = 'C';
        int age = 30;
        driver = new Driver(id, license, age);
    }

    void TearDown() override {
        delete driver;
        driver = nullptr;
    }

    Driver* driver;
}

TEST_F(DriverTest, ConstructorAndInicialization) {
    EXPECT_EQ(driver->getID(), id);
    EXPECT_EQ(driver->getLicense(), license);
    EXPECT_EQ(driver->getAge(), age);
    EXPECT_TRUE(driver->getAvailability());
    EXPECT_TRUE(driver->getVacations().empty());
    EXPECT_EQ(driver->getTimeToRetire(), 65 - age);
}

TEST_F(DriverTest, TestSetDriver) {
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