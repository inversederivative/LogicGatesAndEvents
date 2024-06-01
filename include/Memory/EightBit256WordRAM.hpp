//
// Created by John on 6/1/2024.
//
#include "AbstractNode.hpp"
#include "D_FlipFlop.hpp"
#include <cstdint>
#include <vector>

#ifndef LOGICGATESANDEVENTS_EIGHTBIT255WORDRAM_HPP
#define LOGICGATESANDEVENTS_EIGHTBIT255WORDRAM_HPP


class EightBit256WordRAM : public AbstractNode {

private:

    AbstractNode* addressBit0;
    AbstractNode* addressBit1;
    AbstractNode* addressBit2;
    AbstractNode* addressBit3;
    AbstractNode* addressBit4;
    AbstractNode* addressBit5;
    AbstractNode* addressBit6;
    AbstractNode* addressBit7;

    uint8_t addressWord;

    AbstractNode* dataBit0;
    AbstractNode* dataBit1;
    AbstractNode* dataBit2;
    AbstractNode* dataBit3;
    AbstractNode* dataBit4;
    AbstractNode* dataBit5;
    AbstractNode* dataBit6;
    AbstractNode* dataBit7;

    uint8_t dataWord;

    AbstractNode* writeEnableInput;
    AbstractNode* chipSelectInput;

    LogicState::eLogicState outputBit0;
    LogicState::eLogicState outputBit1;
    LogicState::eLogicState outputBit2;
    LogicState::eLogicState outputBit3;
    LogicState::eLogicState outputBit4;
    LogicState::eLogicState outputBit5;
    LogicState::eLogicState outputBit6;
    LogicState::eLogicState outputBit7;

    uint8_t outputWord;

    // Memory array to store 256 words of 8 bits each
    uint8_t memory[256];

public:

    EightBit256WordRAM();

    // For only LSB
    LogicState::eLogicState GetState() const override;

    // Only Eight bits wide.
    uint8_t GetOutputStates() const;

    void SetDataInputs(std::vector<AbstractNode*> inputsData);

    void SetAddressInputs(std::vector<AbstractNode*> inputsAddress);

    void SetInputWriteEnable(AbstractNode* node);

    void SetInputChipSelect(AbstractNode* node);

    uint8_t GetOutputState(uint8_t address);


    void Update(LogicState::eLogicState state) override;
};


#endif //LOGICGATESANDEVENTS_EIGHTBIT255WORDRAM_HPP
