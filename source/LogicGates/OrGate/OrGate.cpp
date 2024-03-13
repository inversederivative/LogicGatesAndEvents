//
// Created by John on 3/13/2024.
//
#include <LogicGates/OrGate/OrGate.hpp>

void OrGate::SetInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    OrGate::Update(GetState());
}

void OrGate::SetInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    OrGate::Update(GetState());
}

void OrGate::Update(bool state) {
    // Notify observers of the new output state
    outputState_ = state;
    Notify();
}

bool OrGate::GetState() const {
    // Compute the state of the OR gate based on its inputs
    // Note, we're checking that both inputs are NOT null!
    if (inputX && inputY) {
        // Here is where we check if the or condition is true or not.
        return inputX->GetState() || inputY->GetState();
    } else {
        // Handle case where inputs are not set
        return false; // Or some default value depending on your requirements
    }
}
