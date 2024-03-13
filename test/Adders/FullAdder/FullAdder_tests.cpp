//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Adders/FullAdder/FullAdder.hpp>

TEST(FullAdder_Tests, TestFalseAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_Tests, TestTrueAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_Tests, TestFalseAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_Tests, TestTrueAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::ON);
}

TEST(FullAdder_Tests, TestFalseAndFalseCarry)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchC = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);
    fullAdder->SetCarryIn(switchC);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);
    switchC->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_Tests, TestTrueAndFalseCarry)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchC = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);
    fullAdder->SetCarryIn(switchC);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);
    switchC->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::ON);
}

TEST(FullAdder_Tests, TestFalseAndTrueCarry)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchC = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);
    fullAdder->SetCarryIn(switchC);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);
    switchC->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::ON);
}

TEST(FullAdder_Tests, TestTrueAndTrueCarry)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchC = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);
    fullAdder->SetCarryIn(switchC);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchC->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder->GetCarryOut(), LogicState::ON);
}