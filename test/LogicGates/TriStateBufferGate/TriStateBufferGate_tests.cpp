//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/TriStateBufferGate/TriStateBufferGate.hpp>

TEST(TriStateBufferGate_Tests, enableOn_dataOn)
{
    // 1. Setup
    auto switchData = new Switch();
    auto switchEnable = new Switch();


    auto triState = new TriStateBufferGate();

    triState->SetDataInput(switchData);
    triState->SetEnableInput(switchEnable);

    switchData->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::ON);

    EXPECT_EQ(triState->GetState(), LogicState::DISABLED);
}