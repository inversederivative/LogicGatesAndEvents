//
// Created by John on 5/11/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Adders/FourBitAdder/FourBitAdder.hpp>

TEST(FourBitAdder_Tests, TestXFalseAndYFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto switchX3 = new Switch();
    auto switchY3 = new Switch();
    auto switchX4 = new Switch();
    auto switchY4 = new Switch();
    auto carrySwitch = new Switch();

    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchX2->ChangeState(LogicState::ON);
    switchY2->ChangeState(LogicState::ON);
    switchX3->ChangeState(LogicState::OFF);
    switchY3->ChangeState(LogicState::OFF);
    switchX4->ChangeState(LogicState::OFF);
    switchY4->ChangeState(LogicState::OFF);

    auto fourBitAdder = new FourBitAdder();

    fourBitAdder->SetInputX1(switchX1);
    fourBitAdder->SetInputY1(switchY1);
    fourBitAdder->SetInputX2(switchX2);
    fourBitAdder->SetInputY2(switchY2);
    fourBitAdder->SetInputX3(switchX3);
    fourBitAdder->SetInputY3(switchY3);
    fourBitAdder->SetInputX4(switchX4);
    fourBitAdder->SetInputY4(switchY4);
    fourBitAdder->SetCarryIn(carrySwitch);

    // Placing the switches here causes hundreds of
    // propagations, which in the end is costly.

//    switchX1->ChangeState(LogicState::OFF);
//    switchY1->ChangeState(LogicState::OFF);
//    switchX2->ChangeState(LogicState::OFF);
//    switchY2->ChangeState(LogicState::OFF);
//    switchX3->ChangeState(LogicState::OFF);
//    switchY3->ChangeState(LogicState::OFF);
//    switchX4->ChangeState(LogicState::OFF);
//    switchY4->ChangeState(LogicState::OFF);
    carrySwitch->ChangeState(LogicState::OFF);

    // The result of calling update function so many times results in 984 print statements.
    // Running this test takes about 15 minutes to run.

    EXPECT_EQ(fourBitAdder->GetStateSum1(), LogicState::OFF);
    EXPECT_EQ(fourBitAdder->GetStateSum2(), LogicState::ON);
    EXPECT_EQ(fourBitAdder->GetStateSum3(), LogicState::ON);
    EXPECT_EQ(fourBitAdder->GetStateSum4(), LogicState::OFF);

    EXPECT_EQ(fourBitAdder->GetCarryOut(), LogicState::OFF);
}