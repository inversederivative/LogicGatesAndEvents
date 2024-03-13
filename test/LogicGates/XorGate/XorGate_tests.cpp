//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/XorGate/XorGate.hpp>

TEST(XorGate_Tests, TestFalseXorFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(xorGate->GetState(), LogicState::OFF);
}

TEST(XorGate_Tests, TestTrueXorFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(xorGate->GetState(), LogicState::ON);
}

TEST(XorGate_Tests, TestFalseXorTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(xorGate->GetState(), LogicState::ON);
}

TEST(XorGate_Tests, TestTrueXorTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(xorGate->GetState(), LogicState::OFF);
}