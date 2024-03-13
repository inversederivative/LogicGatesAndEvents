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

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(orGate->GetState(), LogicState::OFF);
}

TEST(OrGate_Tests, TestTrueOrFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(orGate->GetState(), LogicState::ON);
}

TEST(OrGate_Tests, TestFalseOrTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(orGate->GetState(), LogicState::ON);
}

TEST(OrGate_Tests, TestTrueOrTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto orGate = new OrGate();

    orGate->SetInputX(switchX1);
    orGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(orGate->GetState(), LogicState::ON);
}