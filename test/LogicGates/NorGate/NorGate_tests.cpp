//
// Created by John on 5/28/2024.
//

#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/NorGate/NorGate.hpp>

TEST(NorGate_Tests, TestFalseNorFalse)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto norGate = new NorGate();

    norGate->SetInputX(switchX1);
    norGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::OFF);

    EXPECT_EQ(norGate->GetState(), LogicState::ON);
}

TEST(NorGate_Tests, TestFalseNorTrue)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();

    auto norGate = new NorGate();

    norGate->SetInputX(switchX1);
    norGate->SetInputY(switchY1);

    switchX1->ChangeState(LogicState::OFF);
    switchY1->ChangeState(LogicState::ON);

    EXPECT_EQ(norGate->GetState(), LogicState::OFF);
}