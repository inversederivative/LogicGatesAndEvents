//
// Created by John on 5/28/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/NotGate/NotGate.hpp>

TEST(NotGate_Tests, TestDisabled)
{
    // 1. Setup
    auto switchX1 = new Switch();

    auto notGate = new NotGate();

    notGate->SetInput(switchX1);

    switchX1->ChangeState(LogicState::DISABLED);

    EXPECT_EQ(notGate->GetState(), LogicState::DISABLED);
}

TEST(NotGate_Tests, TestOff)
{
    // 1. Setup
    auto switchX1 = new Switch();

    auto notGate = new NotGate();

    notGate->SetInput(switchX1);

    switchX1->ChangeState(LogicState::OFF);

    EXPECT_EQ(notGate->GetState(), LogicState::ON);
}

TEST(NotGate_Tests, TestOn)
{
    // 1. Setup
    auto switchX1 = new Switch();

    auto notGate = new NotGate();

    notGate->SetInput(switchX1);

    switchX1->ChangeState(LogicState::ON);

    EXPECT_EQ(notGate->GetState(), LogicState::OFF);
}