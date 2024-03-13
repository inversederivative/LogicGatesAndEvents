//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/AndGate/AndGate.hpp>

TEST(AndGate_Tests, TestFalseAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(false);
    switchY1->ChangeState(false);

    EXPECT_EQ(andGate->GetState(), false);
}

TEST(AndGate_Tests, TestTrueAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(false);

    EXPECT_EQ(andGate->GetState(), false);
}

TEST(AndGate_Tests, TestFalseAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(false);
    switchY1->ChangeState(true);

    EXPECT_EQ(andGate->GetState(), false);
}

TEST(AndGate_Tests, TestTrueAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(true);

    EXPECT_EQ(andGate->GetState(), true);
}