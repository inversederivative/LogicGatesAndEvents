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

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(andGate->GetState(), LogicState::OFF);
}

TEST(AndGate_Tests, TestTrueAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(andGate->GetState(), LogicState::OFF);
}

TEST(AndGate_Tests, TestFalseAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(andGate->GetState(), LogicState::OFF);
}

TEST(AndGate_Tests, TestTrueAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(andGate->GetState(), LogicState::ON);
}

TEST(AndGate_Tests, TestDisabledAndDisabled)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::DISABLED);
    switchY1->ChangeState(LogicState::DISABLED);

    EXPECT_EQ(andGate->GetState(), LogicState::DISABLED);
}

TEST(AndGate_Tests, TestDisabledAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::DISABLED);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(andGate->GetState(), LogicState::DISABLED);
}

TEST(AndGate_Tests, TestTrueAndDisabled)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::DISABLED);

    EXPECT_EQ(andGate->GetState(), LogicState::DISABLED);
}

TEST(AndGate_Tests, TestFalseAndDisabled)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::DISABLED);

    EXPECT_EQ(andGate->GetState(), LogicState::OFF);
}

TEST(AndGate_Tests, TestDisabledAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::DISABLED);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(andGate->GetState(), LogicState::OFF);
}

TEST(AndGate_Tests, TestRemovingNodes)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto andGate = new AndGate();

    andGate->SetInputX(switchX1);
    andGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::DISABLED);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(andGate->GetState(), LogicState::OFF);

    andGate->RemoveInputX();
    int count = switchX1->GetObserversList().size();

    EXPECT_EQ(count, 0);
}