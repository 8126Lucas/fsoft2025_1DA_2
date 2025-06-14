//
// Created by ruben on 12/06/2025.
//
#include "Driver.h"
#include "DriverContainer.h"
#include "gtest/gtest.h"
#include "NonExistingDataException.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "Date.h"
#include "Vacation.h"

using namespace std;

class DriverContainerTest : public ::testing::Test {
protected:
    void SetUp() override {
        driverContainer = new DriverContainer();
    }
    void TearDown() override {
        delete driverContainer;
        driverContainer = nullptr;
    }
    DriverContainer* driverContainer;
};

TEST_F(DriverContainerTest, AddValidDriver) {
    char license = 'B';
    Driver *driver = new Driver(1, license, 30);
    testing::internal::CaptureStdout();
    driverContainer->add(*driver);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(driverContainer->listDrivers().size(), 1);
    delete driver;
}

TEST_F(DriverContainerTest, AddDuplicatedDriver) {
    char license = 'B';
    Driver *driver = new Driver(1, license, 30);
    driverContainer->add(*driver);
    testing::internal::CaptureStdout();
    driverContainer->add(*driver);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Driver (id): 1\" duplicated !!\n");
    EXPECT_EQ(driverContainer->listDrivers().size(), 1);
    delete driver;
}

TEST_F(DriverContainerTest, RemoveValidDriver) {
    char license = 'B';
    Driver *driver = new Driver(1, license, 30);
    driverContainer->add(*driver);
    testing::internal::CaptureStdout();
    driverContainer->remove(1);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
    EXPECT_EQ(driverContainer->listDrivers().size(), 0);
    delete driver;
}

TEST_F(DriverContainerTest, RemoveNonExistingDriver) {
    testing::internal::CaptureStdout();
    driverContainer->remove(1);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Driver (id): 1\" does not exist !!\n");
    EXPECT_EQ(driverContainer->listDrivers().size(), 0);
}

TEST_F(DriverContainerTest, TestListDrivers) {
    char licenseB = 'B';
    char licenseC = 'C';
    Driver *driver1 = new Driver(1, licenseB, 25);
    Driver *driver2 = new Driver(2, licenseC, 35);
    Driver *driver3 = new Driver(3, licenseB, 45);
    driverContainer->add(*driver1);
    driverContainer->add(*driver2);
    driverContainer->add(*driver3);
    list<Driver> drivers = driverContainer->listDrivers();
    EXPECT_EQ(drivers.size(), 3);
    delete driver1;
    delete driver2;
    delete driver3;
}

TEST_F(DriverContainerTest, TestListAvailableDrivers) {
    char license = 'B';
    Driver *driver1 = new Driver(1, license, 30);
    Driver *driver2 = new Driver(2, license, 35);
    Driver *driver3 = new Driver(3, license, 40);
    driver2->setAvailability(false);
    driverContainer->add(*driver1);
    driverContainer->add(*driver2);
    driverContainer->add(*driver3);
    list<Driver> availableDrivers = driverContainer->listAvailableDrivers(true);
    EXPECT_EQ(availableDrivers.size(), 2);
    delete driver1;
    delete driver2;
    delete driver3;
}

TEST_F(DriverContainerTest, TestListUnavailableDrivers) {
    char license = 'B';
    Driver *driver1 = new Driver(1, license, 30);
    Driver *driver2 = new Driver(2, license, 35);
    Driver *driver3 = new Driver(3, license, 40);
    driver1->setAvailability(false);
    driver2->setAvailability(false);
    driverContainer->add(*driver1);
    driverContainer->add(*driver2);
    driverContainer->add(*driver3);
    list<Driver> unavailableDrivers = driverContainer->listAvailableDrivers(false);
    EXPECT_EQ(unavailableDrivers.size(), 2);
    delete driver1;
    delete driver2;
    delete driver3;
}

TEST_F(DriverContainerTest, AddVacationToDriver) {
    char license = 'B';
    Driver *driver = new Driver(1, license, 30);
    driverContainer->add(*driver);
    Date startDate(1, 7, 2025);
    Date endDate(15, 7, 2025);
    Vacation *vacation = new Vacation(1, driver, startDate, endDate);
    testing::internal::CaptureStdout();
    driverContainer->addVacation(vacation);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(output, success_message);
    Driver* containerDriver = driverContainer->get(1);
    const list<Vacation*>& vacations = containerDriver->getVacations();
    EXPECT_EQ(vacations.size(), 1);
    EXPECT_EQ(*vacations.begin(), vacation);

    delete driver;
    delete vacation;
}

TEST_F(DriverContainerTest, AddDuplicatedVacationToDriver) {
    char license = 'B';
    Driver *driver = new Driver(1, license, 30);
    driverContainer->add(*driver);

    Date startDate1(1, 7, 2025);
    Date endDate1(15, 7, 2025);
    Vacation *vacation1 = new Vacation(1, driver, startDate1, endDate1);
    driverContainer->addVacation(vacation1);

    Date startDate2(1, 8, 2025);
    Date endDate2(15, 8, 2025);
    Vacation *vacation2 = new Vacation(1, driver, startDate2, endDate2);

    testing::internal::CaptureStdout();
    driverContainer->addVacation(vacation2);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "!! Error: \"Vacation (id): 1\" duplicated !!\n");
    EXPECT_EQ(driverContainer->get(1)->getVacations().size(), 1);

    delete driver;
    delete vacation2;
}