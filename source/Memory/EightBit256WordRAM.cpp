//
// Created by John on 6/1/2024.
//

#include "Memory/EightBit256WordRAM.hpp"

EightBit256WordRAM::EightBit256WordRAM() {
    // Initialize all member variables
    addressBit0 = nullptr;
    addressBit1 = nullptr;
    addressBit2 = nullptr;
    addressBit3 = nullptr;
    addressBit4 = nullptr;
    addressBit5 = nullptr;
    addressBit6 = nullptr;
    addressBit7 = nullptr;

    addressWord = 0;

    dataBit0 = nullptr;
    dataBit1 = nullptr;
    dataBit2 = nullptr;
    dataBit3 = nullptr;
    dataBit4 = nullptr;
    dataBit5 = nullptr;
    dataBit6 = nullptr;
    dataBit7 = nullptr;

    dataWord = 0;

    writeEnableInput = nullptr;
    chipSelectInput = nullptr;

    outputBit0 = LogicState::DISABLED;
    outputBit1 = LogicState::DISABLED;
    outputBit2 = LogicState::DISABLED;
    outputBit3 = LogicState::DISABLED;
    outputBit4 = LogicState::DISABLED;
    outputBit5 = LogicState::DISABLED;
    outputBit6 = LogicState::DISABLED;
    outputBit7 = LogicState::DISABLED;

    outputWord = 0;

    // Initialize memory
    std::fill(std::begin(memory), std::end(memory), 0);
}

LogicState::eLogicState EightBit256WordRAM::GetState() const {
    return outputBit0;
}

uint8_t EightBit256WordRAM::GetOutputStates() const {
    // Check if any output bit is DISABLED
    if (outputBit0 == LogicState::DISABLED || outputBit1 == LogicState::DISABLED ||
        outputBit2 == LogicState::DISABLED || outputBit3 == LogicState::DISABLED ||
        outputBit4 == LogicState::DISABLED || outputBit5 == LogicState::DISABLED ||
        outputBit6 == LogicState::DISABLED || outputBit7 == LogicState::DISABLED) {
        return 0;
    }

    // Create a word from the output bits
    uint8_t _outputWord = 0;
    _outputWord |= (outputBit0 == LogicState::ON ? 1 : 0);
    _outputWord |= (outputBit1 == LogicState::ON ? 2 : 0);
    _outputWord |= (outputBit2 == LogicState::ON ? 4 : 0);
    _outputWord |= (outputBit3 == LogicState::ON ? 8 : 0);
    _outputWord |= (outputBit4 == LogicState::ON ? 16 : 0);
    _outputWord |= (outputBit5 == LogicState::ON ? 32 : 0);
    _outputWord |= (outputBit6 == LogicState::ON ? 64 : 0);
    _outputWord |= (outputBit7 == LogicState::ON ? 128 : 0);

    return outputWord;
}

void EightBit256WordRAM::SetDataInputs(std::vector<AbstractNode *> inputsData) {
    if (inputsData.size() != 8) {
        throw std::invalid_argument("Eight data inputs are required.");
    }

    dataBit0 = inputsData[0];
    dataBit1 = inputsData[1];
    dataBit2 = inputsData[2];
    dataBit3 = inputsData[3];
    dataBit4 = inputsData[4];
    dataBit5 = inputsData[5];
    dataBit6 = inputsData[6];
    dataBit7 = inputsData[7];

    dataBit0->Attach(this);
    dataBit1->Attach(this);
    dataBit2->Attach(this);
    dataBit3->Attach(this);
    dataBit4->Attach(this);
    dataBit5->Attach(this);
    dataBit6->Attach(this);
    dataBit7->Attach(this);
}

void EightBit256WordRAM::SetAddressInputs(std::vector<AbstractNode *> inputsAddress) {
    if (inputsAddress.size() != 8) {
        throw std::invalid_argument("Eight address inputs are required.");
    }

    addressBit0 = inputsAddress[0];
    addressBit1 = inputsAddress[1];
    addressBit2 = inputsAddress[2];
    addressBit3 = inputsAddress[3];
    addressBit4 = inputsAddress[4];
    addressBit5 = inputsAddress[5];
    addressBit6 = inputsAddress[6];
    addressBit7 = inputsAddress[7];

    addressBit0->Attach(this);
    addressBit1->Attach(this);
    addressBit2->Attach(this);
    addressBit3->Attach(this);
    addressBit4->Attach(this);
    addressBit5->Attach(this);
    addressBit6->Attach(this);
    addressBit7->Attach(this);
}

void EightBit256WordRAM::SetInputWriteEnable(AbstractNode *node) {
    writeEnableInput = node;
    writeEnableInput->Attach(this);
}

void EightBit256WordRAM::SetInputChipSelect(AbstractNode *node) {
    chipSelectInput = node;
    chipSelectInput->Attach(this);
}


void EightBit256WordRAM::Update(LogicState::eLogicState state) {
    // Update the address word
    addressWord = (addressBit0->GetState() == LogicState::ON ? 1 : 0) |
                  (addressBit1->GetState() == LogicState::ON ? 2 : 0) |
                  (addressBit2->GetState() == LogicState::ON ? 4 : 0) |
                  (addressBit3->GetState() == LogicState::ON ? 8 : 0) |
                  (addressBit4->GetState() == LogicState::ON ? 16 : 0) |
                  (addressBit5->GetState() == LogicState::ON ? 32 : 0) |
                  (addressBit6->GetState() == LogicState::ON ? 64 : 0) |
                  (addressBit7->GetState() == LogicState::ON ? 128 : 0);

    // Update the data word
    dataWord = (dataBit0->GetState() == LogicState::ON ? 1 : 0) |
               (dataBit1->GetState() == LogicState::ON ? 2 : 0) |
               (dataBit2->GetState() == LogicState::ON ? 4 : 0) |
               (dataBit3->GetState() == LogicState::ON ? 8 : 0) |
               (dataBit4->GetState() == LogicState::ON ? 16 : 0) |
               (dataBit5->GetState() == LogicState::ON ? 32 : 0) |
               (dataBit6->GetState() == LogicState::ON ? 64 : 0) |
               (dataBit7->GetState() == LogicState::ON ? 128 : 0);

    // Handle write operation
    if (writeEnableInput && writeEnableInput->GetState() == LogicState::ON) {
        memory[addressWord] = dataWord;
    }

    // Handle read operation
    if (chipSelectInput && chipSelectInput->GetState() == LogicState::OFF) {
        outputWord = memory[addressWord];

        outputBit0 = (outputWord & 1) ? LogicState::ON : LogicState::OFF;
        outputBit1 = (outputWord & 2) ? LogicState::ON : LogicState::OFF;
        outputBit2 = (outputWord & 4) ? LogicState::ON : LogicState::OFF;
        outputBit3 = (outputWord & 8) ? LogicState::ON : LogicState::OFF;
        outputBit4 = (outputWord & 16) ? LogicState::ON : LogicState::OFF;
        outputBit5 = (outputWord & 32) ? LogicState::ON : LogicState::OFF;
        outputBit6 = (outputWord & 64) ? LogicState::ON : LogicState::OFF;
        outputBit7 = (outputWord & 128) ? LogicState::ON : LogicState::OFF;
    } else {
        // If chip select is ON, disable outputs
        outputBit0 = LogicState::DISABLED;
        outputBit1 = LogicState::DISABLED;
        outputBit2 = LogicState::DISABLED;
        outputBit3 = LogicState::DISABLED;
        outputBit4 = LogicState::DISABLED;
        outputBit5 = LogicState::DISABLED;
        outputBit6 = LogicState::DISABLED;
        outputBit7 = LogicState::DISABLED;
    }

    Notify();
}

uint8_t EightBit256WordRAM::GetOutputState(uint8_t address) {
    // Temporarily set the address lines to the specified address
    uint8_t prevAddressWord = addressWord;
    addressWord = address;

    // Handle read operation for the given address
    uint8_t outputValue = memory[addressWord];

    // Restore the previous address word
    addressWord = prevAddressWord;

    return outputValue;
}
