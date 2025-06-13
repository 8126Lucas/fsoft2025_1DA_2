//
// Created by lucas on 12/06/2025.
//
#include <string>
#include <DuplicatedDataException.h>
#include <NonExistingDataException.h>
#include "VehicleContainer.h"
#include "gtest/gtest.h"

class VehicleContainerTest : public testing::Test {
protected:
    void SetUp() override {
        containerVehicle = new VehicleContainer;
    }
    void TearDown() override {
        delete containerVehicle;
        containerVehicle = nullptr;
    }
    VehicleContainer *containerVehicle;
};

TEST_F(VehicleContainerTest, AddValidTruck) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    testing::internal::CaptureStdout();
    containerVehicle->add(truck);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
}

TEST_F(VehicleContainerTest, AddValidVan) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    testing::internal::CaptureStdout();
    containerVehicle->add(van);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
}

TEST_F(VehicleContainerTest, AddDuplicatedTruck) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    containerVehicle->add(truck);
    testing::internal::CaptureStdout();
    containerVehicle->add(truck);
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Vehicle (Truck): ZZ-ZZ-ZZ\" duplicated !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, AddDuplicatedVan) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    containerVehicle->add(van);
    testing::internal::CaptureStdout();
    containerVehicle->add(van);
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Vehicle (Van): ZZ-ZZ-ZZ\" duplicated !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, RemoveValidTruck) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    containerVehicle->add(truck);
    testing::internal::CaptureStdout();
    containerVehicle->remove(truck->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
}

TEST_F(VehicleContainerTest, RemoveValidVan) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    containerVehicle->add(van);
    testing::internal::CaptureStdout();
    containerVehicle->remove(van->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
}

TEST_F(VehicleContainerTest, RemoveNonExistingVehicle) {
    testing::internal::CaptureStdout();
    containerVehicle->remove("ZZ-ZZ-ZZ");
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Vehicle ZZ-ZZ-ZZ\" does not exist !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, AddInsuranceToTruck) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    string licensePlate = truck->getLicensePlate();
    containerVehicle->add(truck);
    Date startDate(1, 1, 2025);
    Date endDate(1, 1, 2026);
    Insurance *insurance = new Insurance(1, truck, startDate, endDate, 100);
    containerVehicle->update(licensePlate, insurance);
    EXPECT_EQ(truck->getInsurance(), insurance);
}

TEST_F(VehicleContainerTest, AddInsuranceToVan) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    string licensePlate = van->getLicensePlate();
    containerVehicle->add(van);
    Date startDate(1, 1, 2025);
    Date endDate(1, 1, 2026);
    Insurance *insurance = new Insurance(1, van, startDate, endDate, 100);
    containerVehicle->update(licensePlate, insurance);
    EXPECT_EQ(van->getInsurance(), insurance);
}

TEST_F(VehicleContainerTest, RemoveInsuranceToTruck) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    string licensePlate = truck->getLicensePlate();
    containerVehicle->add(truck);
    Date startDate(1, 1, 2025);
    Date endDate(1, 1, 2026);
    Insurance *insurance = new Insurance(1, truck, startDate, endDate, 100);
    containerVehicle->update(licensePlate, insurance);
    EXPECT_EQ(truck->getInsurance(), insurance);
}

TEST_F(VehicleContainerTest, RemoveInsuranceToVan) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    string licensePlate = van->getLicensePlate();
    containerVehicle->add(van);
    Date startDate(1, 1, 2025);
    Date endDate(1, 1, 2026);
    Insurance *insurance = new Insurance(1, van, startDate, endDate, 100);
    containerVehicle->update(licensePlate, insurance);
    EXPECT_EQ(van->getInsurance(), insurance);
}