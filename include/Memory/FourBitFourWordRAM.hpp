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

    //    D_FlipFlop* mem00;
//    D_FlipFlop* mem01;
//    D_FlipFlop* mem02;
//    D_FlipFlop* mem03;
//    D_FlipFlop* mem04;
//    D_FlipFlop* mem05;
//    D_FlipFlop* mem06;
//    D_FlipFlop* mem07; // Bit 8
//
//    D_FlipFlop* mem10;
//    D_FlipFlop* mem11;
//    D_FlipFlop* mem12;
//    D_FlipFlop* mem13;
//    D_FlipFlop* mem14;
//    D_FlipFlop* mem15;
//    D_FlipFlop* mem16;
//    D_FlipFlop* mem17; // Bit 16
//
//    D_FlipFlop* mem20;
//    D_FlipFlop* mem21;
//    D_FlipFlop* mem22;
//    D_FlipFlop* mem23;
//    D_FlipFlop* mem24;
//    D_FlipFlop* mem25;
//    D_FlipFlop* mem26;
//    D_FlipFlop* mem27; // Bit 24
//
//    D_FlipFlop* mem30;
//    D_FlipFlop* mem31;
//    D_FlipFlop* mem32;
//    D_FlipFlop* mem33;
//    D_FlipFlop* mem34;
//    D_FlipFlop* mem35;
//    D_FlipFlop* mem36;
//    D_FlipFlop* mem37; // Bit 32
//
//    D_FlipFlop* mem40;
//    D_FlipFlop* mem41;
//    D_FlipFlop* mem42;
//    D_FlipFlop* mem43;
//    D_FlipFlop* mem44;
//    D_FlipFlop* mem45;
//    D_FlipFlop* mem46;
//    D_FlipFlop* mem47; // Bit 40
//
//    D_FlipFlop* mem50;
//    D_FlipFlop* mem51;
//    D_FlipFlop* mem52;
//    D_FlipFlop* mem53;
//    D_FlipFlop* mem54;
//    D_FlipFlop* mem55;
//    D_FlipFlop* mem56;
//    D_FlipFlop* mem57; // Bit 48
//
//    D_FlipFlop* mem60;
//    D_FlipFlop* mem61;
//    D_FlipFlop* mem62;
//    D_FlipFlop* mem63;
//    D_FlipFlop* mem64;
//    D_FlipFlop* mem65;
//    D_FlipFlop* mem66;
//    D_FlipFlop* mem67; // Bit 56
//
//    D_FlipFlop* mem70;
//    D_FlipFlop* mem71;
//    D_FlipFlop* mem72;
//    D_FlipFlop* mem73;
//    D_FlipFlop* mem74;
//    D_FlipFlop* mem75;
//    D_FlipFlop* mem76;
//    D_FlipFlop* mem77;  // Bit 64

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
