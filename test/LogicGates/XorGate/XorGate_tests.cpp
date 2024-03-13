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

    switchX1->ChangeState(false);
    switchY1->ChangeState(false);

    EXPECT_EQ(xorGate->GetState(), false);
}

TEST(XorGate_Tests, TestTrueXorFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(false);

    EXPECT_EQ(xorGate->GetState(), true);
}

TEST(XorGate_Tests, TestFalseXorTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(false);
    switchY1->ChangeState(true);

    EXPECT_EQ(xorGate->GetState(), true);
}

TEST(XorGate_Tests, TestTrueXorTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto xorGate = new XorGate();

    xorGate->SetInputX(switchX1);
    xorGate->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(true);

    EXPECT_EQ(xorGate->GetState(), false);
}