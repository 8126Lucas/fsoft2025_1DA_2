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

TEST_F(VehicleContainerTest, RemoveTruckInVSL) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    string vslName = "Nome";
    string vslAddress = "Morada";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    truck->setVSL(vsl);
    containerVehicle->add(truck);
    testing::internal::CaptureStdout();
    containerVehicle->remove(truck->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Truck is still in a Storage Location. Therefore, License Plate\" is invalid !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, RemoveVanInVSL) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    string vslName = "Nome";
    string vslAddress = "Morada";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    van->setVSL(vsl);
    containerVehicle->add(van);
    testing::internal::CaptureStdout();
    containerVehicle->remove(van->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Van is still in a Storage Location. Therefore, License Plate\" is invalid !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, RemoveTruckWithInsurance) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    Date startDate(1, 1, 2025);
    Date endDate(1, 1, 2100);
    Insurance *insurance = new Insurance(999, truck, startDate, endDate, 25.99);
    truck->setInsurance(insurance);
    containerVehicle->add(truck);
    testing::internal::CaptureStdout();
    containerVehicle->remove(truck->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Truck still has Insurance. Therefore, License Plate\" is invalid !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, RemoveVanWithInsurance) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    Date startDate(1, 1, 2025);
    Date endDate(1, 1, 2100);
    Insurance *insurance = new Insurance(999, van, startDate, endDate, 25.99);
    van->setInsurance(insurance);
    containerVehicle->add(van);
    testing::internal::CaptureStdout();
    containerVehicle->remove(van->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Van still has Insurance. Therefore, License Plate\" is invalid !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, RemoveTruckWithInspection) {
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    Date date(1, 1, 2100);
    Inspection *inspection = new Inspection(999, truck, date, 25.99);
    truck->setInspection(inspection);
    containerVehicle->add(truck);
    testing::internal::CaptureStdout();
    containerVehicle->remove(truck->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Truck still has Inspection. Therefore, License Plate\" is invalid !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VehicleContainerTest, RemoveVanWithInspection) {
    Van *van = new Van(VAN, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 199, true);
    Date date(1, 1, 2100);
    Inspection *inspection = new Inspection(999, van, date, 25.99);
    van->setInspection(inspection);
    containerVehicle->add(van);
    testing::internal::CaptureStdout();
    containerVehicle->remove(van->getLicensePlate());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Van still has Inspection. Therefore, License Plate\" is invalid !!\n";
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

TEST_F(VehicleContainerTest, ListTrucks) {
    Truck *truck1 = new Truck(TRUCK, "AAA", "AAA", 2025, "AA-AA-AA", 120, 100, 199, true);
    Truck *truck2 = new Truck(TRUCK, "BBB", "BBB", 2025, "BB-BB-BB", 120, 100, 199, false);
    Truck *truck3 = new Truck(TRUCK, "CCC", "CCC", 2025, "CC-CC-CC", 120, 100, 199, true);
    containerVehicle->add(truck1);
    containerVehicle->add(truck2);
    containerVehicle->add(truck3);
    list<Truck*> trucks = containerVehicle->listTrucks();
    EXPECT_EQ(trucks.size(), 3);
}

TEST_F(VehicleContainerTest, ListVans) {
    Van *van1 = new Van(VAN, "AAA", "AAA", 2025, "AA-AA-AA", 120, 100, 199, true);
    Van *van2 = new Van(VAN, "BBB", "BBB", 2025, "BB-BB-BB", 120, 100, 199, false);
    Van *van3 = new Van(VAN, "CCC", "CCC", 2025, "CC-CC-CC", 120, 100, 199, true);
    containerVehicle->add(van1);
    containerVehicle->add(van2);
    containerVehicle->add(van3);
    list<Van*> vans = containerVehicle->listVans();
    EXPECT_EQ(vans.size(), 3);
}

TEST_F(VehicleContainerTest, ListAvailableTrucks) {
    Truck *truck1 = new Truck(TRUCK, "AAA", "AAA", 2025, "AA-AA-AA", 120, 100, 199, true);
    Truck *truck2 = new Truck(TRUCK, "BBB", "BBB", 2025, "BB-BB-BB", 120, 100, 199, false);
    Truck *truck3 = new Truck(TRUCK, "CCC", "CCC", 2025, "CC-CC-CC", 120, 100, 199, true);
    containerVehicle->add(truck1);
    containerVehicle->add(truck2);
    containerVehicle->add(truck3);
    list<Truck*> trucks = containerVehicle->listTrucks(true);
    EXPECT_EQ(trucks.size(), 2);
}

TEST_F(VehicleContainerTest, ListAvailableVans) {
    Van *van1 = new Van(VAN, "AAA", "AAA", 2025, "AA-AA-AA", 120, 100, 199, true);
    Van *van2 = new Van(VAN, "BBB", "BBB", 2025, "BB-BB-BB", 120, 100, 199, false);
    Van *van3 = new Van(VAN, "CCC", "CCC", 2025, "CC-CC-CC", 120, 100, 199, false);
    containerVehicle->add(van1);
    containerVehicle->add(van2);
    containerVehicle->add(van3);
    list<Van*> vans = containerVehicle->listVans(true);
    EXPECT_EQ(vans.size(), 1);
}

TEST_F(VehicleContainerTest, ListUnavailableTrucks) {
    Truck *truck1 = new Truck(TRUCK, "AAA", "AAA", 2025, "AA-AA-AA", 120, 100, 199, true);
    Truck *truck2 = new Truck(TRUCK, "BBB", "BBB", 2025, "BB-BB-BB", 120, 100, 199, false);
    Truck *truck3 = new Truck(TRUCK, "CCC", "CCC", 2025, "CC-CC-CC", 120, 100, 199, true);
    containerVehicle->add(truck1);
    containerVehicle->add(truck2);
    containerVehicle->add(truck3);
    list<Truck*> trucks = containerVehicle->listTrucks(false);
    EXPECT_EQ(trucks.size(), 1);
}

TEST_F(VehicleContainerTest, ListUnavailableVans) {
    Van *van1 = new Van(VAN, "AAA", "AAA", 2025, "AA-AA-AA", 120, 100, 199, true);
    Van *van2 = new Van(VAN, "BBB", "BBB", 2025, "BB-BB-BB", 120, 100, 199, false);
    Van *van3 = new Van(VAN, "CCC", "CCC", 2025, "CC-CC-CC", 120, 100, 199, false);
    containerVehicle->add(van1);
    containerVehicle->add(van2);
    containerVehicle->add(van3);
    list<Van*> vans = containerVehicle->listVans(false);
    EXPECT_EQ(vans.size(), 2);
}