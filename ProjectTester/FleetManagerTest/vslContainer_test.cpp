//
// Created by lucas on 12/06/2025.
//

#include <Truck.h>

#include "VSLContainer.h"
#include "gtest/gtest.h"

class VSLContainerTest : public testing::Test {
protected:
    void SetUp() override {
        containerVSL = new VSLContainer;
    }
    void TearDown() override {
        containerVSL = nullptr;
    }
    VSLContainer *containerVSL;
};

TEST_F(VSLContainerTest, AddValidVSL) {
    string vslName = "Nome";
    string vslAddress = "Address";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    testing::internal::CaptureStdout();
    containerVSL->add(vsl);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
}

TEST_F(VSLContainerTest, AddDuplicatedVSL) {
    string vslName = "Nome";
    string vslAddress = "Address";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    containerVSL->add(vsl);
    testing::internal::CaptureStdout();
    containerVSL->add(vsl);
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Storage Location\" duplicated !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VSLContainerTest, RemoveValidVSL) {
    string vslName = "Nome";
    string vslAddress = "Address";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    testing::internal::CaptureStdout();
    containerVSL->add(vsl);
    string output = testing::internal::GetCapturedStdout();
    string success_message;
    EXPECT_EQ(success_message, output);
}

TEST_F(VSLContainerTest, RemoveVSLWithTruck) {
    string vslName = "Nome";
    string vslAddress = "Address";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    Truck *truck = new Truck(TRUCK, "ZZZ", "ZZZ", 2025, "ZZ-ZZ-ZZ", 120, 100, 129, true);
    vsl->addVehicle(truck);
    containerVSL->add(vsl);
    testing::internal::CaptureStdout();
    containerVSL->remove(vsl->getID());
    string output = testing::internal::GetCapturedStdout();
    string error_message = "!! Error: \"Storage Location still has Vehicles. Therefore, ID\" is invalid !!\n";
    EXPECT_EQ(error_message, output);
}

TEST_F(VSLContainerTest, ListVSLs) {
    string vsl1Name = "Nome1"; string vsl1Address = "Address1";
    VehicleStorageLocation *vsl1 = new VehicleStorageLocation(1, vsl1Name, vsl1Address, 999, 0);
    string vsl2Name = "Nome2"; string vsl2Address = "Address2";
    VehicleStorageLocation *vsl2 = new VehicleStorageLocation(2, vsl2Name, vsl2Address, 999, 0);
    string vsl3Name = "Nome3"; string vsl3Address = "Address3";
    VehicleStorageLocation *vsl3 = new VehicleStorageLocation(3, vsl3Name, vsl3Address, 999, 0);
    containerVSL->add(vsl1);
    containerVSL->add(vsl2);
    containerVSL->add(vsl3);
    list<VehicleStorageLocation*> vsls = containerVSL->listVSL();
    EXPECT_EQ(vsls.size(), 3);
}