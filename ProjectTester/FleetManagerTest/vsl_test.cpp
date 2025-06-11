//
// Created by lucas on 11/06/2025.
//

#include <Truck.h>

#include "VehicleStorageLocation.h"
#include "Vehicle.h"
#include "gtest/gtest.h"

class VSLTest : public testing::Test {
protected:
    void SetUp() override {
        vsl = new VehicleStorageLocation;
    }
    void TearDown() override {
        delete vsl;
        vsl = nullptr;
    }
    VehicleStorageLocation *vsl;
};

TEST_F(VSLTest, EmptyConstructorInitialization) {
    unordered_map<int, list<Vehicle *>> testMap = {};
    EXPECT_EQ(vsl->getVehicles(), testMap);
    EXPECT_EQ(vsl->getID(), 0);
    EXPECT_EQ(vsl->getCapacity(), 0);
    EXPECT_EQ(vsl->getVehicleCount(), 0);
}

TEST_F(VSLTest, IncrementVehicleCount) {
    vsl->incrementVehicleCount();
    EXPECT_EQ(vsl->getVehicleCount(), 1);
}

TEST_F(VSLTest, DecrementVehicleCount) {
    vsl->setCurrentVehicleCount(2);
    vsl->decrementVehicleCount();
    EXPECT_EQ(vsl->getVehicleCount(), 1);
}

// TEST_F(VSLTest, GetStoredVehicles) {}

TEST_F(VSLTest, AddVehicleToStorageLocation) {
    Truck *testTruck = new Truck(TRUCK, "BMW", "Serie 4", 2023, "6E-UT-U9", 109, 79, 4000, true);
    vsl->setID(1);
    vsl->setName("Nome");
    vsl->setAddress("Morada");
    vsl->setCapacity(1);
    vsl->addVehicle(testTruck);
    EXPECT_EQ(vsl->getStoredVehicles(vsl->getID()).size(), 1);
}