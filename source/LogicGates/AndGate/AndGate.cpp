//
// Created by John on 3/12/2024.
//
#include <LogicGates/AndGate/AndGate.hpp>

void AndGate::SetInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    AndGate::Update(GetState());
}

void AndGate::SetInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    AndGate::Update(GetState());
}

void AndGate::Update(bool state) {
    // Notify observers of the new output state
    outputState_ = state;
    Notify();
}

bool AndGate::GetState() const {
    // Compute the state of the AND gate based on its inputs
    if (inputX && inputY) {
        return inputX->GetState() && inputY->GetState();
    } else {
        // Handle case where inputs are not set
        return false; // Or some default value depending on your requirements
    }
}
