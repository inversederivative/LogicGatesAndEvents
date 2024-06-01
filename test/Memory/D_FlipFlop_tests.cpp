//
// Created by John on 5/29/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Memory/D_FlipFlop.hpp>

class D_FlipFlop_Tests : public ::testing::Test {
protected:
    Switch* switchData;
    Switch* switchEnable;
    D_FlipFlop* flipFlop;

    void SetUp() override {
        switchData = new Switch();
        switchEnable = new Switch();
        flipFlop = new D_FlipFlop();

        flipFlop->SetInputData(switchData);
        flipFlop->SetInputEnable(switchEnable);
        switchData->ChangeState(LogicState::OFF);
        switchEnable->ChangeState(LogicState::OFF);
    }

    void TearDown() override {
        delete switchData;
        delete switchEnable;
        delete flipFlop;
    }
};

TEST_F(D_FlipFlop_Tests, InitialState) {
    EXPECT_EQ(flipFlop->GetState(), LogicState::OFF);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::ON);
}

TEST_F(D_FlipFlop_Tests, DisabledDataAndEnable) {
    switchData->ChangeState(LogicState::DISABLED);
    switchEnable->ChangeState(LogicState::DISABLED);

    EXPECT_EQ(flipFlop->GetState(), LogicState::DISABLED);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::DISABLED);
}

TEST_F(D_FlipFlop_Tests, EnableSignalRisingEdge) {
    switchData->ChangeState(LogicState::OFF);
    switchEnable->ChangeState(LogicState::OFF);

    EXPECT_EQ(flipFlop->GetState(), LogicState::OFF);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::ON);

    switchData->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::OFF);

    EXPECT_EQ(flipFlop->GetState(), LogicState::ON);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::OFF);
}

TEST_F(D_FlipFlop_Tests, EnableSignalDisabled) {
    switchData->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::DISABLED);

    EXPECT_EQ(flipFlop->GetState(), LogicState::DISABLED);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::DISABLED);
}

TEST_F(D_FlipFlop_Tests, DataChangeWithoutEnable) {
    switchData->ChangeState(LogicState::OFF);
    switchEnable->ChangeState(LogicState::OFF);

    EXPECT_EQ(flipFlop->GetState(), LogicState::OFF);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::ON);

    switchData->ChangeState(LogicState::ON);

    EXPECT_EQ(flipFlop->GetState(), LogicState::OFF);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::ON);
}

TEST_F(D_FlipFlop_Tests, EnableSignalONOFF) {
    switchData->ChangeState(LogicState::OFF);
    switchEnable->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::OFF);

    EXPECT_EQ(flipFlop->GetState(), LogicState::OFF);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::ON);

    switchData->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::OFF);

    EXPECT_EQ(flipFlop->GetState(), LogicState::ON);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::OFF);
}

TEST_F(D_FlipFlop_Tests, EnableSignalOFF) {
    switchData->ChangeState(LogicState::ON);
    switchEnable->ChangeState(LogicState::OFF);

    EXPECT_EQ(flipFlop->GetState(), LogicState::OFF);
    EXPECT_EQ(flipFlop->GetQBarState(), LogicState::ON);
}

TEST_F(D_FlipFlop_Tests, Emulate_RAM)
{
    switchData->ChangeState(LogicState::OFF);
    switchEnable->ChangeState(LogicState::ON);

    EXPECT_EQ(LogicState::OFF, flipFlop->GetState());
}