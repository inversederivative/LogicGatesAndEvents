//
// Created by John on 5/28/2024.
//

#include "Memory/D_FlipFlop.hpp"

D_FlipFlop::D_FlipFlop() {
    notGate = new NotGate();
    andGateOne = new AndGate();
    andGateTwo = new AndGate();
    norGateOne = new NorGate();
    norGateTwo = new NorGate;

    connectedNodes_ = {};
}

void D_FlipFlop::SetInputData(AbstractNode *input) {
    inputData = input;
    input->Attach(this);

    // Set inputs
    //xorGateA->SetInputX(inputX);
    //andGateA->SetInputX(inputX);
    notGate->SetInput(dataInput);
    andGateOne->SetInputX(notGate->answer());
    andGateTwo->SetInputY(dataInput);
    norGateOne->SetInputX(andGateOne->answer());

    norGateOne->SetInputY(LogicState::OFF);
//    norGateTwo->SetInputX(LogicState::OFF);
//    norGateOne->SetInputY(norGateTwo->answer());
//    norGateTwo->SetInputX(norGateOne->answer());

    connectedNodes_.push_back(input);
    D_FlipFlop::Update(GetState());
}

void D_FlipFlop::SetInputEnable(AbstractNode *input) {
    inputEnable = input;
    input->Attach(this);

    // Set Inputs
    //xorGateA->SetInputY(inputY);
    //andGateA->SetInputY(inputY);
    andGateOne->SetInputY(enableInput);
    andGateTwo->SetInputX(enableInput);
    norGateTwo->SetInputY(andGateTwo->answer());

    norGateOne->SetInputY(LogicState::OFF);
//    norGateTwo->SetInputX(LogicState::OFF);
//    norGateOne->SetInputY(norGateTwo->answer());
//    norGateTwo->SetInputX(norGateOne->answer());

    connectedNodes_.push_back(input);
    D_FlipFlop::Update(GetState());
}

LogicState::eLogicState D_FlipFlop::GetState() const {

    // Note, this comes from the original TriStateLogicGates project. Needs to be modified a bit.

//    notGate->SetInput(dataInput);
//
//    andGateOne->SetInputX(notGate->answer());
//    andGateOne->SetInputY(enableInput);
//
//    andGateTwo->SetInputX(enableInput);
//    andGateTwo->SetInputY(dataInput);
//
//    norGateOne->SetInputX(andGateOne->answer());
//    norGateTwo->SetInputY(andGateTwo->answer());
//
//    // Default state of inputs is LS::DISABLED. We need
//    // to trick the NOR Gates, so they don't output DISABLED...
//    norGateOne->SetInputY(LogicState::OFF);
//    norGateTwo->SetInputX(LogicState::OFF);
//    norGateOne->SetInputY(norGateTwo->answer());
//    norGateTwo->SetInputX(norGateOne->answer());
//
//    outputQ = norGateOne->answer();
//    outputQBar = norGateTwo->answer();

    return LogicState::DISABLED;
}

LogicState::eLogicState D_FlipFlop::GetQBarState() const {
    return LogicState::DISABLED;
}
