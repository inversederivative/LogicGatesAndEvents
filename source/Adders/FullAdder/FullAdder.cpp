//
// Created by John on 3/13/2024.
//
#include <Adders/FullAdder/FullAdder.hpp>
#include <Switch/Switch.hpp>

FullAdder::FullAdder()
{
    xorGateA = new XorGate();
    xorGateB = new XorGate();
    andGateA = new AndGate();
    andGateB = new AndGate();
    orGate = new OrGate();

    // Carry in Default behavior is false.
    // If we provide our own carryIn, it will be overwritten.
    carryIn = new Switch(LogicState::OFF);
    SetCarryIn(carryIn);
}

void FullAdder::SetInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);

    xorGateA->SetInputX(inputX);
    andGateA->SetInputX(inputX);

    connectedNodes_.push_back(input);
    FullAdder::Update(GetState());
}

void FullAdder::SetInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);

    xorGateA->SetInputY(inputY);
    andGateA->SetInputY(inputY);

    connectedNodes_.push_back(input);
    FullAdder::Update(GetState());
}

void FullAdder::SetCarryIn(AbstractNode *carry) {
    carryIn = carry;
    carry->Attach(this);

    xorGateB->SetInputY(carryIn);
    andGateB->SetInputY(carryIn);

    connectedNodes_.push_back(carry);
    FullAdder::Update(GetState());
}


void FullAdder::Update(LogicState::eLogicState state) {
    xorGateA->Update(xorGateA->GetState());
    andGateA->Update(andGateA->GetState());
    xorGateB->SetInputX(xorGateA);
    andGateB->SetInputX(xorGateA);
    orGate->SetInputX(andGateB);
    orGate->SetInputY(andGateA);
    outputSumState_ = xorGateB->GetState();
    outputCarryState_ = orGate->GetState();
}

LogicState::eLogicState FullAdder::GetState() const {
    // Compute the state of the Full Adder based on its inputs
    if (inputX && inputY) {
        return xorGateB->GetState();
    } else {
        // Handle case where inputs are not set
        return LogicState::DISABLED; // Or some default value depending on your requirements
    }
}

LogicState::eLogicState FullAdder::GetCarryOut() const {
    return orGate->GetState();
}