//
// Created by John on 3/13/2024.
//
#include <LogicGates/TriStateBufferGate/TriStateBufferGate.hpp>

void TriStateBufferGate::SetDataInput(AbstractNode *input) {
    dataInput = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    TriStateBufferGate::Update(GetState());
}

void TriStateBufferGate::SetEnableInput(AbstractNode *input) {
    enableInput = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    TriStateBufferGate::Update(GetState());
}

void TriStateBufferGate::Update(LogicState::eLogicState state) {
    // Notify observers of the new output state
    outputState_ = state;
    Notify();
}

LogicState::eLogicState TriStateBufferGate::GetState() const {
    LogicState::eLogicState output;
    if (dataInput && enableInput)
    {
        if (enableInput->GetState() == LogicState::ON)
        {
            // If the enable Input is ON, we want to set the output of the
            //  buffer to DISABLED!
            output = LogicState::DISABLED;
            return output;
        }
        else if (enableInput->GetState() == LogicState::OFF && dataInput->GetState() == LogicState::ON)
        {
            output = LogicState::ON;
            return output;
        }
        else
        {
            output = LogicState::OFF;
            return output;
        }
    }
    else
    {
        std::cout<<"Both Inputs of Tri State Buffer Gate weren't populated yet..." << std::endl;
        return LogicState::DISABLED;
    }
}
