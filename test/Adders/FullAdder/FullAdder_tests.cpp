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

    switchX1->ChangeState(false);
    switchY1->ChangeState(false);

    EXPECT_EQ(fullAdder->GetState(), false);
    EXPECT_EQ(fullAdder->GetCarryOut(), false);
}

TEST(FullAdder_Tests, TestTrueAndFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(false);

    EXPECT_EQ(fullAdder->GetState(), true);
    EXPECT_EQ(fullAdder->GetCarryOut(), false);
}

TEST(FullAdder_Tests, TestFalseAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(false);
    switchY1->ChangeState(true);

    EXPECT_EQ(fullAdder->GetState(), true);
    EXPECT_EQ(fullAdder->GetCarryOut(), false);
}

TEST(FullAdder_Tests, TestTrueAndTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto fullAdder = new FullAdder();

    fullAdder->SetInputX(switchX1);
    fullAdder->SetInputY(switchY1);

    switchX1->ChangeState(true);
    switchY1->ChangeState(true);

    EXPECT_EQ(fullAdder->GetState(), false);
    EXPECT_EQ(fullAdder->GetCarryOut(), true);
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

    switchX1->ChangeState(false);
    switchY1->ChangeState(false);
    switchC->ChangeState(true);

    EXPECT_EQ(fullAdder->GetState(), true);
    EXPECT_EQ(fullAdder->GetCarryOut(), false);
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

    switchX1->ChangeState(true);
    switchY1->ChangeState(false);
    switchC->ChangeState(true);

    EXPECT_EQ(fullAdder->GetState(), false);
    EXPECT_EQ(fullAdder->GetCarryOut(), true);
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

    switchX1->ChangeState(false);
    switchY1->ChangeState(true);
    switchC->ChangeState(true);

    EXPECT_EQ(fullAdder->GetState(), false);
    EXPECT_EQ(fullAdder->GetCarryOut(), true);
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

    switchX1->ChangeState(true);
    switchY1->ChangeState(true);
    switchC->ChangeState(true);

    EXPECT_EQ(fullAdder->GetState(), true);
    EXPECT_EQ(fullAdder->GetCarryOut(), true);
}