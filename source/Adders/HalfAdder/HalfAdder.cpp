//
// Created by John on 3/13/2024.
//
#include <Adders/HalfAdder/HalfAdder.hpp>

HalfAdder::HalfAdder() {

    xorGate = new XorGate();
    andGate = new AndGate();

}

void HalfAdder::SetInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);

    xorGate->SetInputX(inputX);
    andGate->SetInputX(inputX);

    connectedNodes_.push_back(input);
    HalfAdder::Update(GetState());
}

void HalfAdder::SetInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);

    xorGate->SetInputY(inputY);
    andGate->SetInputY(inputY);

    connectedNodes_.push_back(input);
    HalfAdder::Update(GetState());
}

void HalfAdder::Update(bool state) {
    // Notify observers of the new output state

    // Perhaps we'll need to reimplement the HA logic here
    outputSumState_ = state;
    outputCarryState_ = andGate->GetState();
    Notify();
}

bool HalfAdder::GetState() const {
    // Compute the state of the Half Adder based on its inputs
    if (inputX && inputY) {
        return xorGate->GetState();
    } else {
        // Handle case where inputs are not set
        return false; // Or some default value depending on your requirements
    }
}

bool HalfAdder::GetCarry() const {
    return outputCarryState_;
}
