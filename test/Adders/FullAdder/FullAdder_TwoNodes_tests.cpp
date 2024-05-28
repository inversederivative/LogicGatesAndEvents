//
// Created by John on 5/11/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Adders/FullAdder/FullAdder.hpp>

TEST(FullAdder_TwoNodes_Tests, Test_00_01)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchC = new Switch();

    auto fullAdder1 = new FullAdder();
    auto fullAdder2 = new FullAdder();


    fullAdder1->SetInputX(switchX1);
    fullAdder1->SetInputY(switchY1);
    fullAdder1->SetCarryIn(switchC);

    fullAdder2->SetInputX(switchX2);
    fullAdder2->SetInputY(switchY2);
    fullAdder2->SetCarryIn(fullAdder1->GetCarryOutNode());

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);
    switchX2->ChangeState(LogicState::OFF);
    switchY2->ChangeState(LogicState::OFF);
    switchC->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder1->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder2->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_TwoNodes_Tests, Test_01_01)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchC = new Switch();

    auto fullAdder1 = new FullAdder();
    auto fullAdder2 = new FullAdder();


    fullAdder1->SetInputX(switchX1);
    fullAdder1->SetInputY(switchY1);
    fullAdder1->SetCarryIn(switchC);

    fullAdder2->SetInputX(switchX2);
    fullAdder2->SetInputY(switchY2);
    fullAdder2->SetCarryIn(fullAdder1->GetCarryOutNode());

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchX2->ChangeState(LogicState::OFF);
    switchY2->ChangeState(LogicState::OFF);
    switchC->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder1->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder2->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_TwoNodes_Tests, Test_11_00)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchC = new Switch();

    auto fullAdder1 = new FullAdder();
    auto fullAdder2 = new FullAdder();


    fullAdder1->SetInputX(switchX1);
    fullAdder1->SetInputY(switchY1);
    fullAdder1->SetCarryIn(switchC);

    fullAdder2->SetInputX(switchX2);
    fullAdder2->SetInputY(switchY2);
    fullAdder2->SetCarryIn(fullAdder1->GetCarryOutNode());

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::OFF);
    switchX2->ChangeState(LogicState::ON);
    switchY2->ChangeState(LogicState::OFF);
    switchC->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder1->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetCarryOut(), LogicState::OFF);
}

TEST(FullAdder_TwoNodes_Tests, Test_11_01)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchC = new Switch();

    auto fullAdder1 = new FullAdder();
    auto fullAdder2 = new FullAdder();


    fullAdder1->SetInputX(switchX1);
    fullAdder1->SetInputY(switchY1);
    fullAdder1->SetCarryIn(switchC);

    fullAdder2->SetInputX(switchX2);
    fullAdder2->SetInputY(switchY2);
    fullAdder2->SetCarryIn(fullAdder1->GetCarryOutNode());

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchX2->ChangeState(LogicState::ON);
    switchY2->ChangeState(LogicState::OFF);
    switchC->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder1->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder2->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder2->GetCarryOut(), LogicState::ON);
}

TEST(FullAdder_TwoNodes_Tests, Test_11_11)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchC = new Switch();

    auto fullAdder1 = new FullAdder();
    auto fullAdder2 = new FullAdder();


    fullAdder1->SetInputX(switchX1);
    fullAdder1->SetInputY(switchY1);
    fullAdder1->SetCarryIn(switchC);

    fullAdder2->SetInputX(switchX2);
    fullAdder2->SetInputY(switchY2);
    fullAdder2->SetCarryIn(fullAdder1->GetCarryOutNode());

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchX2->ChangeState(LogicState::ON);
    switchY2->ChangeState(LogicState::ON);
    switchC->ChangeState(LogicState::OFF);

    EXPECT_EQ(fullAdder1->GetState(), LogicState::OFF);
    EXPECT_EQ(fullAdder2->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetCarryOut(), LogicState::ON);
}

TEST(FullAdder_TwoNodes_Tests, Test_11_11_Plus_Carry)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchC = new Switch();

    auto fullAdder1 = new FullAdder();
    auto fullAdder2 = new FullAdder();


    fullAdder1->SetInputX(switchX1);
    fullAdder1->SetInputY(switchY1);
    fullAdder1->SetCarryIn(switchC);

    fullAdder2->SetInputX(switchX2);
    fullAdder2->SetInputY(switchY2);
    fullAdder2->SetCarryIn(fullAdder1->GetCarryOutNode());

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchX2->ChangeState(LogicState::ON);
    switchY2->ChangeState(LogicState::ON);
    switchC->ChangeState(LogicState::ON);

    EXPECT_EQ(fullAdder1->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetState(), LogicState::ON);
    EXPECT_EQ(fullAdder2->GetCarryOut(), LogicState::ON);
}