//
// Created by John on 5/11/2024.
//
#include <LogicGates/BufferGate/BufferGate.hpp>

void BufferGate::SetInput(AbstractNode *in) {
    input = in;
    in->Attach(this);
    BufferGate::Update(GetState());
}

void BufferGate::Update(LogicState::eLogicState state) {
    outputState_ = state;
    Notify();
}

LogicState::eLogicState BufferGate::GetState() const {
    return outputState_;
}
