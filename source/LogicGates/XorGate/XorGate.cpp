//
// Created by John on 3/13/2024.
//
#include <LogicGates/XorGate/XorGate.hpp>

void XorGate::SetInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    XorGate::Update(GetState());
}

void XorGate::SetInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    XorGate::Update(GetState());
}

void XorGate::Update(bool state) {
    // Notify observers of the new output state
    outputState_ = state;
    Notify();
}

bool XorGate::GetState() const {
    // Compute the state of the XOR gate based on its inputs
    if (inputX && inputY) {
        return !inputX->GetState() != !inputY->GetState();
    } else {
        // Handle case where inputs are not set
        return false; // Or some default value depending on your requirements
    }
}
