//
// Created by John on 6/1/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Memory/FourBitFourWordRAM.hpp>

class FourBitFourWordRam_Tests : public ::testing::Test {
protected:

    Switch* switchAddressX0;
    Switch* switchAddressX1;

    Switch* switchDataX0;
    Switch* switchDataX1;
    Switch* switchDataX2;
    Switch* switchDataX3;

    Switch* switchWriteEnable;
    Switch* switchChipSelect;

    FourBitFourWordRAM* fourBitFourWordRam;

    void SetUp() override {
        switchAddressX0 = new Switch();
        switchAddressX1 = new Switch();

        switchDataX0 = new Switch();
        switchDataX1 = new Switch();
        switchDataX2 = new Switch();
        switchDataX3 = new Switch();

        switchWriteEnable = new Switch();
        switchChipSelect = new Switch();


        fourBitFourWordRam = new FourBitFourWordRAM();

        std::vector<AbstractNode*> addresses = {switchAddressX0, switchAddressX1};

        std::vector<AbstractNode*> dataBits = {switchDataX0, switchDataX1, switchDataX2, switchDataX3};

        fourBitFourWordRam->SetAddressInputs(addresses);
        fourBitFourWordRam->SetDataInputs(dataBits);

        fourBitFourWordRam->SetInputWriteEnable(switchWriteEnable);
        fourBitFourWordRam->SetInputChipSelect(switchChipSelect);

        switchAddressX0->ChangeState(LogicState::OFF);
        switchAddressX1->ChangeState(LogicState::OFF);

        switchDataX0->ChangeState(LogicState::OFF);
        switchDataX1->ChangeState(LogicState::OFF);
        switchDataX2->ChangeState(LogicState::OFF);
        switchDataX3->ChangeState(LogicState::OFF);

        switchWriteEnable->ChangeState(LogicState::OFF);
        switchChipSelect->ChangeState(LogicState::OFF);
    }


    void TearDown() override {
        delete switchAddressX0;
        delete switchAddressX1;

        delete switchDataX0;
        delete switchDataX1;
        delete switchDataX2;
        delete switchDataX3;

        delete switchWriteEnable;
        delete switchChipSelect;
    }
};

TEST_F(FourBitFourWordRam_Tests, InitialState) {
    std::vector<LogicState::eLogicState> expected = {LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}

TEST_F(FourBitFourWordRam_Tests, WriteToAddress00) {
    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::OFF);



    switchDataX0->ChangeState(LogicState::ON);
    switchDataX1->ChangeState(LogicState::OFF);
    switchDataX2->ChangeState(LogicState::ON);
    switchDataX3->ChangeState(LogicState::OFF);



    switchWriteEnable->ChangeState(LogicState::OFF);
    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF); // Write operation

    switchChipSelect->ChangeState(LogicState::OFF); // Inverted; OFF means output states will be written, ON means outputs will display all DISABLED.

    std::vector<LogicState::eLogicState> expected = {LogicState::ON, LogicState::OFF, LogicState::ON, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}

TEST_F(FourBitFourWordRam_Tests, WriteToAddress01) {
    switchAddressX0->ChangeState(LogicState::ON);
    switchAddressX1->ChangeState(LogicState::OFF);

    switchDataX0->ChangeState(LogicState::OFF);
    switchDataX1->ChangeState(LogicState::ON);
    switchDataX2->ChangeState(LogicState::OFF);
    switchDataX3->ChangeState(LogicState::ON);

    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF); // Write operation

    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::OFF);

    std::vector<LogicState::eLogicState> expected = {LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());

    switchAddressX0->ChangeState(LogicState::ON);
    switchAddressX1->ChangeState(LogicState::OFF);

    expected = {LogicState::OFF, LogicState::ON, LogicState::OFF, LogicState::ON};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}

TEST_F(FourBitFourWordRam_Tests, WriteToAddress10) {
    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::ON);

    switchDataX0->ChangeState(LogicState::ON);
    switchDataX1->ChangeState(LogicState::ON);
    switchDataX2->ChangeState(LogicState::OFF);
    switchDataX3->ChangeState(LogicState::OFF);

    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF); // Write operation

    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::OFF);

    std::vector<LogicState::eLogicState> expected = {LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());

    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::ON);

    expected = {LogicState::ON, LogicState::ON, LogicState::OFF, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}

TEST_F(FourBitFourWordRam_Tests, WriteToAddress11) {
    switchAddressX0->ChangeState(LogicState::ON);
    switchAddressX1->ChangeState(LogicState::ON);

    switchDataX0->ChangeState(LogicState::OFF);
    switchDataX1->ChangeState(LogicState::OFF);
    switchDataX2->ChangeState(LogicState::ON);
    switchDataX3->ChangeState(LogicState::ON);

    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF); // Write operation

    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::OFF);

    std::vector<LogicState::eLogicState> expected = {LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());

    switchAddressX0->ChangeState(LogicState::ON);
    switchAddressX1->ChangeState(LogicState::ON);

    expected = {LogicState::OFF, LogicState::OFF, LogicState::ON, LogicState::ON};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}

TEST_F(FourBitFourWordRam_Tests, ReadFromAddress00WithChipSelectOn) {
    switchChipSelect->ChangeState(LogicState::ON);

    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::OFF);

    std::vector<LogicState::eLogicState> expected = {LogicState::DISABLED, LogicState::DISABLED, LogicState::DISABLED, LogicState::DISABLED};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}

TEST_F(FourBitFourWordRam_Tests, ReadFromAddress00WithChipSelectOff) {
    switchChipSelect->ChangeState(LogicState::OFF);

    switchAddressX0->ChangeState(LogicState::OFF);
    switchAddressX1->ChangeState(LogicState::OFF);

    std::vector<LogicState::eLogicState> expected = {LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());

    switchDataX0->ChangeState(LogicState::ON);
    switchDataX1->ChangeState(LogicState::OFF);
    switchDataX2->ChangeState(LogicState::ON);
    switchDataX3->ChangeState(LogicState::OFF);

    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF); // Write operation

    expected = {LogicState::ON, LogicState::OFF, LogicState::ON, LogicState::OFF};
    EXPECT_EQ(expected, fourBitFourWordRam->GetOutputStates());
}