//
// Created by John on 6/1/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <Memory/EightBit256WordRAM.hpp>

class EightBit256WordRAM_Tests : public ::testing::Test {
protected:

    Switch* switchAddress0;
    Switch* switchAddress1;
    Switch* switchAddress2;
    Switch* switchAddress3;
    Switch* switchAddress4;
    Switch* switchAddress5;
    Switch* switchAddress6;
    Switch* switchAddress7;


    Switch* switchData0;
    Switch* switchData1;
    Switch* switchData2;
    Switch* switchData3;
    Switch* switchData4;
    Switch* switchData5;
    Switch* switchData6;
    Switch* switchData7;


    Switch* switchWriteEnable;
    Switch* switchChipSelect;

    EightBit256WordRAM* eightBit256WordRam;

    void SetUp() override {

        switchAddress0 = new Switch();
        switchAddress1 = new Switch();
        switchAddress2 = new Switch();
        switchAddress3 = new Switch();
        switchAddress4 = new Switch();
        switchAddress5 = new Switch();
        switchAddress6 = new Switch();
        switchAddress7 = new Switch();

        switchData0 = new Switch();
        switchData1 = new Switch();
        switchData2 = new Switch();
        switchData3 = new Switch();
        switchData4 = new Switch();
        switchData5 = new Switch();
        switchData6 = new Switch();
        switchData7 = new Switch();

        switchWriteEnable = new Switch();
        switchChipSelect = new Switch();


        eightBit256WordRam = new EightBit256WordRAM();

        std::vector<AbstractNode*> addresses = {switchAddress0, switchAddress1, switchAddress2, switchAddress3, switchAddress4, switchAddress5, switchAddress6, switchAddress7};

        std::vector<AbstractNode*> dataBits = {switchData0, switchData1, switchData2, switchData3, switchData4, switchData5, switchData6, switchData7};

        eightBit256WordRam->SetAddressInputs(addresses);
        eightBit256WordRam->SetDataInputs(dataBits);

        eightBit256WordRam->SetInputWriteEnable(switchWriteEnable);
        eightBit256WordRam->SetInputChipSelect(switchChipSelect);

        switchAddress0->ChangeState(LogicState::OFF);
        switchAddress1->ChangeState(LogicState::OFF);
        switchAddress2->ChangeState(LogicState::OFF);
        switchAddress3->ChangeState(LogicState::OFF);
        switchAddress4->ChangeState(LogicState::OFF);
        switchAddress5->ChangeState(LogicState::OFF);
        switchAddress6->ChangeState(LogicState::OFF);
        switchAddress7->ChangeState(LogicState::OFF);


        switchData0->ChangeState(LogicState::OFF);
        switchData1->ChangeState(LogicState::OFF);
        switchData2->ChangeState(LogicState::OFF);
        switchData3->ChangeState(LogicState::OFF);
        switchData4->ChangeState(LogicState::OFF);
        switchData5->ChangeState(LogicState::OFF);
        switchData6->ChangeState(LogicState::OFF);
        switchData7->ChangeState(LogicState::OFF);

        switchWriteEnable->ChangeState(LogicState::OFF);
        switchChipSelect->ChangeState(LogicState::OFF);
    }

    void ResetAllSwitches() {
        switchAddress0->ChangeState(LogicState::OFF);
        switchAddress1->ChangeState(LogicState::OFF);
        switchAddress2->ChangeState(LogicState::OFF);
        switchAddress3->ChangeState(LogicState::OFF);
        switchAddress4->ChangeState(LogicState::OFF);
        switchAddress5->ChangeState(LogicState::OFF);
        switchAddress6->ChangeState(LogicState::OFF);
        switchAddress7->ChangeState(LogicState::OFF);

        switchData0->ChangeState(LogicState::OFF);
        switchData1->ChangeState(LogicState::OFF);
        switchData2->ChangeState(LogicState::OFF);
        switchData3->ChangeState(LogicState::OFF);
        switchData4->ChangeState(LogicState::OFF);
        switchData5->ChangeState(LogicState::OFF);
        switchData6->ChangeState(LogicState::OFF);
        switchData7->ChangeState(LogicState::OFF);

        switchWriteEnable->ChangeState(LogicState::OFF);
        switchChipSelect->ChangeState(LogicState::OFF);
    }

    void SetAllSwitches(uint8_t value) {
        switchAddress0->ChangeState(value & 0x01 ? LogicState::ON : LogicState::OFF);
        switchAddress1->ChangeState(value & 0x02 ? LogicState::ON : LogicState::OFF);
        switchAddress2->ChangeState(value & 0x04 ? LogicState::ON : LogicState::OFF);
        switchAddress3->ChangeState(value & 0x08 ? LogicState::ON : LogicState::OFF);
        switchAddress4->ChangeState(value & 0x10 ? LogicState::ON : LogicState::OFF);
        switchAddress5->ChangeState(value & 0x20 ? LogicState::ON : LogicState::OFF);
        switchAddress6->ChangeState(value & 0x40 ? LogicState::ON : LogicState::OFF);
        switchAddress7->ChangeState(value & 0x80 ? LogicState::ON : LogicState::OFF);

        switchData0->ChangeState(value & 0x01 ? LogicState::ON : LogicState::OFF);
        switchData1->ChangeState(value & 0x02 ? LogicState::ON : LogicState::OFF);
        switchData2->ChangeState(value & 0x04 ? LogicState::ON : LogicState::OFF);
        switchData3->ChangeState(value & 0x08 ? LogicState::ON : LogicState::OFF);
        switchData4->ChangeState(value & 0x10 ? LogicState::ON : LogicState::OFF);
        switchData5->ChangeState(value & 0x20 ? LogicState::ON : LogicState::OFF);
        switchData6->ChangeState(value & 0x40 ? LogicState::ON : LogicState::OFF);
        switchData7->ChangeState(value & 0x80 ? LogicState::ON : LogicState::OFF);
    }

    void TearDown() override {
        delete switchAddress0;
        delete switchAddress1;
        delete switchAddress2;
        delete switchAddress3;
        delete switchAddress4;
        delete switchAddress5;
        delete switchAddress6;
        delete switchAddress7;

        delete switchData0;
        delete switchData1;
        delete switchData2;
        delete switchData3;
        delete switchData4;
        delete switchData5;
        delete switchData6;
        delete switchData7;


        delete switchWriteEnable;
        delete switchChipSelect;
    }

    void SetAddress(uint8_t address) {
        switchAddress0->ChangeState(address & 0x01 ? LogicState::ON : LogicState::OFF);
        switchAddress1->ChangeState(address & 0x02 ? LogicState::ON : LogicState::OFF);
        switchAddress2->ChangeState(address & 0x04 ? LogicState::ON : LogicState::OFF);
        switchAddress3->ChangeState(address & 0x08 ? LogicState::ON : LogicState::OFF);
        switchAddress4->ChangeState(address & 0x10 ? LogicState::ON : LogicState::OFF);
        switchAddress5->ChangeState(address & 0x20 ? LogicState::ON : LogicState::OFF);
        switchAddress6->ChangeState(address & 0x40 ? LogicState::ON : LogicState::OFF);
        switchAddress7->ChangeState(address & 0x80 ? LogicState::ON : LogicState::OFF);
    }

    void SetData(uint8_t data) {
        switchData0->ChangeState(data & 0x01 ? LogicState::ON : LogicState::OFF);
        switchData1->ChangeState(data & 0x02 ? LogicState::ON : LogicState::OFF);
        switchData2->ChangeState(data & 0x04 ? LogicState::ON : LogicState::OFF);
        switchData3->ChangeState(data & 0x08 ? LogicState::ON : LogicState::OFF);
        switchData4->ChangeState(data & 0x10 ? LogicState::ON : LogicState::OFF);
        switchData5->ChangeState(data & 0x20 ? LogicState::ON : LogicState::OFF);
        switchData6->ChangeState(data & 0x40 ? LogicState::ON : LogicState::OFF);
        switchData7->ChangeState(data & 0x80 ? LogicState::ON : LogicState::OFF);
    }
};

TEST_F(EightBit256WordRAM_Tests, InitialState) {
//std::vector<LogicState::eLogicState> expected = {LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF, LogicState::OFF};
uint8_t expected = 0;
EXPECT_EQ(expected, eightBit256WordRam->GetOutputStates());
}

TEST_F(EightBit256WordRAM_Tests, WriteAndReadAllAddresses) {

    uint8_t address = 255;
    while (address > 0)
    {
        ResetAllSwitches();

        // Set all switches (address and data) to the same value

        if (address == 108)
        {
            uint8_t value = 42;
            SetData(value); // Sets up
            SetAddress(108);
        }
        else
        {
            SetAllSwitches(address);
        }



        // Enable write
        switchWriteEnable->ChangeState(LogicState::ON);
        switchWriteEnable->ChangeState(LogicState::OFF);  // Simulate a write operation

        // Verify the data was written correctly
        switchChipSelect->ChangeState(LogicState::OFF);  // Enable chip select to read data
        if (address != 108)
        {
            EXPECT_EQ(address, eightBit256WordRam->GetOutputStates());
        }
        else
        {
            EXPECT_EQ(42, eightBit256WordRam->GetOutputStates());
        }

        address--;
    }
    uint8_t twoHundred = 200;
    EXPECT_EQ(twoHundred, eightBit256WordRam->GetOutputState(200));
    EXPECT_EQ(twoHundred+1, eightBit256WordRam->GetOutputState(201));
    EXPECT_EQ(twoHundred+5, eightBit256WordRam->GetOutputState(205));
    EXPECT_EQ(twoHundred-158, eightBit256WordRam->GetOutputState(108)); //200-158 = 42.
}

TEST_F(EightBit256WordRAM_Tests, RandomAddressesAndValues_Test) {
    ResetAllSwitches();

    uint8_t address;
    uint8_t data;

    // Set Address and Data
    address = 1;
    data = 240; // 1111 0000
    SetAddress(address);
    SetData(data);
    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF);  // Simulate a write operation

    // Verify the data was written correctly
    switchChipSelect->ChangeState(LogicState::OFF);  // Enable chip select to read data
    EXPECT_EQ(240, eightBit256WordRam->GetOutputStates());

    // Set Address and Data
    address = 42;
    data = 240; // 1111 0000
    SetAddress(address);
    SetData(data);
    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF);  // Simulate a write operation

    EXPECT_EQ(240, eightBit256WordRam->GetOutputStates());

    // Set Address and Data
    address = 64;
    data = 240; // 1111 0000
    SetAddress(address);
    SetData(data);
    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF);  // Simulate a write operation

    EXPECT_EQ(240, eightBit256WordRam->GetOutputStates());

    // Set Address and Data

    address = 200;
    data = 240; // 1111 0000
    SetAddress(address);
    SetData(data);
    // Enable write
    switchWriteEnable->ChangeState(LogicState::ON);
    switchWriteEnable->ChangeState(LogicState::OFF);  // Simulate a write operation

    EXPECT_EQ(240, eightBit256WordRam->GetOutputStates());

    EXPECT_EQ(240, eightBit256WordRam->GetOutputState(1));
    EXPECT_EQ(0, eightBit256WordRam->GetOutputState(2));
    EXPECT_EQ(240, eightBit256WordRam->GetOutputState(42));
    EXPECT_EQ(0, eightBit256WordRam->GetOutputState(43));
    EXPECT_EQ(240, eightBit256WordRam->GetOutputState(64));
    EXPECT_EQ(0, eightBit256WordRam->GetOutputState(65));
    EXPECT_EQ(240, eightBit256WordRam->GetOutputState(200));
    EXPECT_EQ(0, eightBit256WordRam->GetOutputState(201));

}


