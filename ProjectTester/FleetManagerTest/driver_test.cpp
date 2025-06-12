//
// Created by ruben on 10/06/2025.
//
#include "Driver.h"
#include "DriverContainer.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"
#include "Date.h"
#include "Vacation.h"

class DriverTest : public ::testing::Test {
protected:
    void SetUp() override {
        driver = new Driver();
    }
    void TearDown() override {
        delete driver;
        driver = nullptr;
    }
    Driver* driver;
};

TEST_F(DriverTest, ConstructorAndInicialization) {
    EXPECT_EQ(driver->getID(), 0);
    EXPECT_EQ(driver->getLicense(), '\0');
    EXPECT_EQ(driver->getAge(), 0);
    EXPECT_TRUE(driver->getAvailability());
    EXPECT_TRUE(driver->getVacations().empty());
    EXPECT_EQ(driver->getTimeToRetire(), 65);
}

TEST_F(DriverTest, TestSetDriver) {
    int newId = 100;
    char newLicense = 'B';
    int newAge = 30;
    int newTimeToRetire = 65 - newAge;
    bool newAvailability = false;

    driver->setID(newId);
    driver->setLicense(newLicense);
    driver->setAge(newAge);
    driver->setTimeToRetire(newTimeToRetire);
    driver->setAvailability(newAvailability);

    EXPECT_EQ(driver->getID(), newId);
    EXPECT_EQ(driver->getLicense(), newLicense);
    EXPECT_EQ(driver->getAge(), newAge);
    EXPECT_EQ(driver->getTimeToRetire(), newTimeToRetire);
    EXPECT_FALSE(driver->getAvailability());
}

class VacationTest : public ::testing::Test {
protected:
    void SetUp() override {
        vacation = new Vacation;
    }
    void TearDown() override {
        delete vacation;
        vacation = nullptr;
    }
    Vacation *vacation;
};

TEST_F(VacationTest, ConstructorAndInicialization) {
    EXPECT_EQ(vacation->getID(), 0);
    EXPECT_EQ(vacation->getDriver(), nullptr);
    Date emptyDate;
    EXPECT_EQ(vacation->getStartDate(), emptyDate);
    EXPECT_EQ(vacation->getEndDate(), emptyDate);
    EXPECT_FALSE(vacation->getStatus());
}

TEST_F(VacationTest, TestSetVacation) {
    int newId = 100;
    Driver* testDriver = new Driver();
    Date newStartDate;
    Date newEndDate;
    Date today = Date::getToday();
    bool newStatus = false;

    vacation->setID(newId);
    vacation->setDriver(testDriver);
    vacation->setStartDate(newStartDate);
    vacation->setEndDate(newEndDate);
    vacation->setStatus(newStatus);

    EXPECT_EQ(vacation->getID(), newId);
    EXPECT_EQ(vacation->getDriver(), testDriver);
    EXPECT_EQ(vacation->getStartDate(), newStartDate);
    EXPECT_EQ(vacation->getEndDate(), newEndDate);
    EXPECT_FALSE(vacation->getStatus());

    delete testDriver;
}