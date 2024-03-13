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

void OrGate::Update(LogicState::eLogicState state) {
    // Notify observers of the new output state
    outputState_ = state;
    Notify();
}

LogicState::eLogicState OrGate::GetState() const {
    // Compute the state of the OR gate based on its inputs
    // Note, we're checking that both inputs are NOT null!
//    if (inputX && inputY) {
//        // Here is where we check if the or condition is true or not.
//        return inputX->GetState() || inputY->GetState();
//    } else {
//        // Handle case where inputs are not set
//        return false; // Or some default value depending on your requirements
//    }

    // If Both inputs are Disabled
    LogicState::eLogicState output;
    if (inputX && inputY)
    {
        if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::DISABLED)
        {
            output = LogicState::DISABLED;
            return output;
        }

        // If one or the other inputs are disabled

        if (inputX->GetState() == LogicState::DISABLED || inputY->GetState() == LogicState::DISABLED)
        {
            if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::DISABLED)
            {
                output = LogicState::ON;
                return output;
            }
            else if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::ON)
            {
                output = LogicState::ON;
                return output;
            }
            else if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::DISABLED)
            {
                output = LogicState::DISABLED;
                return output;
            }
            else if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::OFF)
            {
                output = LogicState::DISABLED;
                return output;
            }
        }
        else {
            // Neither input contained DISABLED...

            if (inputX->GetState() == LogicState::ON || inputY->GetState() == LogicState::ON) {
                output = LogicState::ON;
                return output;
            } else if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::OFF) {
                output = LogicState::OFF;
                return output;
            }
        }
    } else {
        std::cout<<"Both Inputs of OrGate weren't populated yet..." << std::endl;
        return LogicState::DISABLED;
    }
}
