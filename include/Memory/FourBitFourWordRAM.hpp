//
// Created by John on 5/28/2024.
//
#include <AbstractNode.hpp>
#include <Memory/D_FlipFlop.hpp>
#include <vector>
#include "LogicGates/TriStateBufferGate/TriStateBufferGate.hpp"

#ifndef LOGICGATESANDEVENTS_FOURBITFOURWORDRAM_HPP
#define LOGICGATESANDEVENTS_FOURBITFOURWORDRAM_HPP


class FourBitFourWordRAM : public AbstractNode {

private:

    AbstractNode* addr0;
    AbstractNode* addr1;

    AbstractNode* data0;
    AbstractNode* data1;
    AbstractNode* data2;
    AbstractNode* data3;

    LogicState::eLogicState output0;
    LogicState::eLogicState output1;
    LogicState::eLogicState output2;
    LogicState::eLogicState output3;


    AbstractNode* writeEnable;

    AbstractNode* chipSelect;

    TriStateBufferGate* data0TriStateBuffer;
    TriStateBufferGate* data1TriStateBuffer;
    TriStateBufferGate* data2TriStateBuffer;
    TriStateBufferGate* data3TriStateBuffer;

    D_FlipFlop* memA0;

    D_FlipFlop* memA1;

    D_FlipFlop* memA2;

    D_FlipFlop* memA3;

    D_FlipFlop* memB0;

    D_FlipFlop* memB1;

    D_FlipFlop* memB2;

    D_FlipFlop* memB3;

    D_FlipFlop* memC0;

    D_FlipFlop* memC1;

    D_FlipFlop* memC2;

    D_FlipFlop* memC3;

    D_FlipFlop* memD0;

    D_FlipFlop* memD1;

    D_FlipFlop* memD2;

    D_FlipFlop* memD3;


public:

    FourBitFourWordRAM();

    // For only LSB
    LogicState::eLogicState GetState() const override;

    // Only four bits wide.
    std::vector<LogicState::eLogicState> GetOutputStates() const;


    // inputs[0] is the lsb and inputs [3] is msb (only four bits)
    void SetDataInputs(std::vector<AbstractNode*> inputsData);

    void SetAddressInputs(std::vector<AbstractNode*> inputsAddress);

    void SetInputWriteEnable(AbstractNode* node);

    void SetInputChipSelect(AbstractNode* node);

    void Update(LogicState::eLogicState state) override;

};


#endif //LOGICGATESANDEVENTS_FOURBITFOURWORDRAM_HPP
