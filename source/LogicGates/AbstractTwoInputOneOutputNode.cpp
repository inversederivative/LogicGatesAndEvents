//
// Created by John on 5/6/2024.
//
#include <LogicGates/AbstractTwoInputOneOutputGate.hpp>

AbstractTwoInputOneOutputNode::AbstractTwoInputOneOutputNode() {
    inputX = nullptr;
    inputY = nullptr;
    outputState_ = LogicState::DISABLED;
    connectedNodes_ = {};
}

void AbstractTwoInputOneOutputNode::SetInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);
    connectedNodes_.push_back(inputX);
    AbstractTwoInputOneOutputNode::Update(GetState());
}

void AbstractTwoInputOneOutputNode::SetInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);
    connectedNodes_.push_back(inputY);
    AbstractTwoInputOneOutputNode::Update(GetState());
}

void AbstractTwoInputOneOutputNode::RemoveInputX() {
    inputX->Detach(this);
    connectedNodes_.remove(inputX);
    inputX = nullptr;
}

void AbstractTwoInputOneOutputNode::RemoveInputY() {
    inputY->Detach(this);
    connectedNodes_.remove(inputY);
    inputY = nullptr;
}

void AbstractTwoInputOneOutputNode::Update(LogicState::eLogicState state) {
    outputState_ = state;
    Notify();
}
