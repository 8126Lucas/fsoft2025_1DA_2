//
// Created by Vitor Teixeira on 12/06/2025.
//
#include "TripContainer.h"
#include "gtest/gtest.h"

class TripContainerTest : public ::testing::Test{
  protected:
    void SetUp() override {
      tripContainer = new TripContainer();
    }
    void TearDown() override {
      delete tripContainer;
      tripContainer = nullptr;
    }
    TripContainer *tripContainer;
};


