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

TEST_F(DriverContainerTest, TestAddDriver) {
    char licenseB = 'B';
    char licenseC = 'C';
    char licenseX = 'X';
    Driver driver1(1, licenseB, 30);
    EXPECT_NO_THROW(driverContainer->add(driver1));
    //EXPECT_THROW(driverContainer->add(driver1), DuplicatedDataException);
    EXPECT_EQ(driverContainer->listDrivers().size(), 1);

    Driver duplicateDriver(1, licenseC, 25);
    //EXPECT_THROW(driverContainer->add(duplicateDriver), DuplicatedDataException);
    EXPECT_EQ(driverContainer->listDrivers().size(), 1);

    Driver invalidDriver(-1, licenseX, 17);
    //EXPECT_THROW(driverContainer->add(invalidDriver), InvalidDataException);
    EXPECT_EQ(driverContainer->listDrivers().size(), 1);

    Driver driver2(2, licenseC, 35);
    EXPECT_NO_THROW(driverContainer->add(driver2));
    EXPECT_EQ(driverContainer->listDrivers().size(), 2);
}

TEST_F(DriverContainerTest, TestRemoveDriver) {
    char license = 'B';
    Driver driver1(1, license, 30);
    driverContainer->add(driver1);

    EXPECT_NO_THROW(driverContainer->remove(1));
    EXPECT_EQ(driverContainer->listDrivers().size(), 0);

    //EXPECT_THROW(driverContainer->remove(1), NonExistingDataException);
    //EXPECT_THROW(driverContainer->remove(2), NonExistingDataException);

    //EXPECT_THROW(driverContainer->remove(-1), InvalidDataException);
    //EXPECT_THROW(driverContainer->remove(0), InvalidDataException);
}

/*listDrivers

TEST_F(DriverTest, TestListDrivers) {

}*/

/*listAvailableDrivers

TEST_F(DriverTest, TestListAvailableDrivers) {

}*/

/*listUnavailableDrivers

TEST_F(DriverTest, TestListUnavailableDrivers) {

}*/

TEST_F(DriverContainerTest, TestAddVacation) {
    char license = 'B';
    Driver driver1(1, license, 30);
    driverContainer->add(driver1);

    Date startDate1(1, 7, 2025);
    Date endDate1(15, 7, 2025);
    Vacation* vacation1 = new Vacation(1, &driver1, startDate1, endDate1);

    EXPECT_NO_THROW(driverContainer->addVacation(vacation1));
    EXPECT_EQ(driverContainer->get(1)->getVacations().size(), 1);

    Date startDate2(1, 8, 2025);
    Date endDate2(15, 8, 2025);
    Vacation* vacationDuplicate = new Vacation(1, &driver1, startDate2, endDate2);
    //EXPECT_THROW(driverContainer->addVacation(vacationDuplicate), DuplicatedDataException);
    EXPECT_EQ(driverContainer->get(1)->getVacations().size(), 1);

    Vacation* invalidIdVacation = new Vacation(-1, &driver1, startDate1, endDate1);
    //EXPECT_THROW(driverContainer->addVacation(invalidIdVacation), InvalidDataException);

    Vacation* vacation2 = new Vacation(2, &driver1, startDate2, endDate2);
    EXPECT_NO_THROW(driverContainer->addVacation(vacation2));
    EXPECT_EQ(driverContainer->get(1)->getVacations().size(), 2);

    delete vacationDuplicate;
    delete invalidIdVacation;
}