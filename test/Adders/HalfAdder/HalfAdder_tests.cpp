//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Adders/HalfAdder/HalfAdder.hpp>

TEST(HalfAdder_Tests, TestFalseAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto halfAdder = new HalfAdder();

    halfAdder->SetInputX(switchX1);
    halfAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(halfAdder->GetState(), LogicState::OFF);
    EXPECT_EQ(halfAdder->GetCarry(), LogicState::OFF);
}

TEST(HalfAdder_Tests, TestTrueAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto halfAdder = new HalfAdder();

    halfAdder->SetInputX(switchX1);
    halfAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(halfAdder->GetState(), LogicState::ON);
    EXPECT_EQ(halfAdder->GetCarry(), LogicState::OFF);
}

TEST(HalfAdder_Tests, TestFalseAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto halfAdder = new HalfAdder();

    halfAdder->SetInputX(switchX1);
    halfAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(halfAdder->GetState(), LogicState::ON);
    EXPECT_EQ(halfAdder->GetCarry(), LogicState::OFF);
}

TEST(HalfAdder_Tests, TestTrueAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto halfAdder = new HalfAdder();

    halfAdder->SetInputX(switchX1);
    halfAdder->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(halfAdder->GetState(), LogicState::OFF);
    EXPECT_EQ(halfAdder->GetCarry(), LogicState::ON);
}