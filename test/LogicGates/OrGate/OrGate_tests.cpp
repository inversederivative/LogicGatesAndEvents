//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/OrGate/OrGate.hpp>

TEST(OrGate_Tests, TestFalseOrFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(false);
    switchY1->ChangeState(false);

    EXPECT_EQ(orGate->GetState(), false);
}

TEST(OrGate_Tests, TestTrueOrFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(false);

    EXPECT_EQ(orGate->GetState(), true);
}

TEST(OrGate_Tests, TestFalseOrTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(false);
    switchY1->ChangeState(true);

    EXPECT_EQ(orGate->GetState(), true);
}

TEST(OrGate_Tests, TestTrueOrTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(true);

    EXPECT_EQ(orGate->GetState(), true);
}