//
// Created by lucas on 12/06/2025.
//

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