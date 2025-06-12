//
// Created by lucas on 12/06/2025.
//

#include "VSLContainer.h"
#include "gtest/gtest.h"

class VSLContainerTest : public testing::Test {
protected:
    void SetUp() override {
        containerVSL = new VSLContainer;
    }
    void TearDown() override {
        delete containerVSL;
        containerVSL = nullptr;
    }
    VSLContainer *containerVSL;
};
