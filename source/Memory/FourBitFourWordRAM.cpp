//
// Created by John on 5/28/2024.
//

#include "Memory/FourBitFourWordRAM.hpp"

FourBitFourWordRAM::FourBitFourWordRAM() {
    // Initialize all member variables
    addr0 = nullptr;
    addr1 = nullptr;
    data0 = nullptr;
    data1 = nullptr;
    data2 = nullptr;
    data3 = nullptr;
    output0 = LogicState::DISABLED;
    output1 = LogicState::DISABLED;
    output2 = LogicState::DISABLED;
    output3 = LogicState::DISABLED;
    writeEnable = nullptr;
    chipSelect = nullptr;

    // Initialize D_FlipFlops for memory
    memA0 = new D_FlipFlop();
    memA1 = new D_FlipFlop();
    memA2 = new D_FlipFlop();
    memA3 = new D_FlipFlop();
    memB0 = new D_FlipFlop();
    memB1 = new D_FlipFlop();
    memB2 = new D_FlipFlop();
    memB3 = new D_FlipFlop();
    memC0 = new D_FlipFlop();
    memC1 = new D_FlipFlop();
    memC2 = new D_FlipFlop();
    memC3 = new D_FlipFlop();
    memD0 = new D_FlipFlop();
    memD1 = new D_FlipFlop();
    memD2 = new D_FlipFlop();
    memD3 = new D_FlipFlop();

}

LogicState::eLogicState FourBitFourWordRAM::GetState() const {
    // Only return the state of the least significant bit (output0)
    return output0;
}

std::vector<LogicState::eLogicState> FourBitFourWordRAM::GetOutputStates() const {
    return {output0, output1, output2, output3};
}

void FourBitFourWordRAM::SetDataInputs(std::vector<AbstractNode*> inputsData) {
    if (inputsData.size() != 4) {
        throw std::invalid_argument("Four data inputs are required.");
    }

    // Set data inputs and attach observers
    data0 = inputsData[0];
    data1 = inputsData[1];
    data2 = inputsData[2];
    data3 = inputsData[3];

    data0->Attach(this);
    data1->Attach(this);
    data2->Attach(this);
    data3->Attach(this);
}

void FourBitFourWordRAM::SetAddressInputs(std::vector<AbstractNode*> inputsAddress) {
    if (inputsAddress.size() != 2) {
        throw std::invalid_argument("Two address inputs are required.");
    }

    // Set address inputs and attach observers
    addr0 = inputsAddress[0];
    addr1 = inputsAddress[1];

    addr0->Attach(this);
    addr1->Attach(this);
}

void FourBitFourWordRAM::SetInputWriteEnable(AbstractNode* node) {
    writeEnable = node;
    writeEnable->Attach(this);
}

void FourBitFourWordRAM::SetInputChipSelect(AbstractNode* node) {
    chipSelect = node;
    chipSelect->Attach(this);
}

void FourBitFourWordRAM::Update(LogicState::eLogicState state) {
    if (writeEnable && writeEnable->GetState() == LogicState::ON) {
        // Determine which memory block to write to based on address lines
        // Address 0
        if (addr0->GetState() == LogicState::OFF && addr1->GetState() == LogicState::OFF)  {
            memA0->SetInputData(data0);
            memA1->SetInputData(data1);
            memA2->SetInputData(data2);
            memA3->SetInputData(data3);
            memA0->SetInputEnable(writeEnable);
            memA1->SetInputEnable(writeEnable);
            memA2->SetInputEnable(writeEnable);
            memA3->SetInputEnable(writeEnable);
            // Address 1
        } else if (addr0->GetState() == LogicState::ON && addr1->GetState() == LogicState::OFF) {
            memB0->SetInputData(data0);
            memB1->SetInputData(data1);
            memB2->SetInputData(data2);
            memB3->SetInputData(data3);
            memB0->SetInputEnable(writeEnable);
            memB1->SetInputEnable(writeEnable);
            memB2->SetInputEnable(writeEnable);
            memB3->SetInputEnable(writeEnable);
            // Address Two
        } else if (addr0->GetState() == LogicState::OFF && addr1->GetState() == LogicState::ON) {
            memC0->SetInputData(data0);
            memC1->SetInputData(data1);
            memC2->SetInputData(data2);
            memC3->SetInputData(data3);
            memC0->SetInputEnable(writeEnable);
            memC1->SetInputEnable(writeEnable);
            memC2->SetInputEnable(writeEnable);
            memC3->SetInputEnable(writeEnable);
            // Address 3
        } else if (addr0->GetState() == LogicState::ON && addr1->GetState() == LogicState::ON) {
            memD0->SetInputData(data0);
            memD1->SetInputData(data1);
            memD2->SetInputData(data2);
            memD3->SetInputData(data3);
            memD0->SetInputEnable(writeEnable);
            memD1->SetInputEnable(writeEnable);
            memD2->SetInputEnable(writeEnable);
            memD3->SetInputEnable(writeEnable);
        }
    }

    if (chipSelect && chipSelect->GetState() == LogicState::OFF) {
        // Determine which memory block to read from based on address lines
        if (addr0->GetState() == LogicState::OFF && addr1->GetState() == LogicState::OFF) {
            output0 = memA0->GetState();
            output1 = memA1->GetState();
            output2 = memA2->GetState();
            output3 = memA3->GetState();
        } else if (addr0->GetState() == LogicState::ON && addr1->GetState() == LogicState::OFF) {
            output0 = memB0->GetState();
            output1 = memB1->GetState();
            output2 = memB2->GetState();
            output3 = memB3->GetState();
        } else if (addr0->GetState() == LogicState::OFF && addr1->GetState() == LogicState::ON) {
            output0 = memC0->GetState();
            output1 = memC1->GetState();
            output2 = memC2->GetState();
            output3 = memC3->GetState();
        } else if (addr0->GetState() == LogicState::ON && addr1->GetState() == LogicState::ON) {
            output0 = memD0->GetState();
            output1 = memD1->GetState();
            output2 = memD2->GetState();
            output3 = memD3->GetState();
        }
    } else {
        // If chip select is ON, disable outputs
        output0 = LogicState::DISABLED;
        output1 = LogicState::DISABLED;
        output2 = LogicState::DISABLED;
        output3 = LogicState::DISABLED;
    }


    Notify();
}
