//
// Created by John on 5/28/2024.
//

#include "LogicGates/NotGate/NotGate.hpp"

void NotGate::SetInput(AbstractNode *in) {
    input = in;
    in->Attach(this);
    NotGate::Update(GetState());
}

void NotGate::Update(LogicState::eLogicState state) {
    outputState_ = state;
    Notify();
}

LogicState::eLogicState NotGate::GetState() const {

    LogicState::eLogicState output = LogicState::DISABLED;

    if (input->GetState() == LogicState::DISABLED)
    {
        output = LogicState::DISABLED;
    }
    else
    {
        if (input->GetState() == LogicState::OFF)
        {
            output = LogicState::ON;
        }
        else
        {
            output = LogicState::OFF;
        }
    }

    return output;
}