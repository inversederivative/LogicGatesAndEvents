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

void XorGate::Update(LogicState::eLogicState state) {
    // Notify observers of the new output state
    outputState_ = state;
    Notify();
}

LogicState::eLogicState XorGate::GetState() const {
//    // Compute the state of the XOR gate based on its inputs
//    if (inputX && inputY) {
//        return !inputX->GetState() != !inputY->GetState();
//    } else {
//        // Handle case where inputs are not set
//        return false; // Or some default value depending on your requirements
//    }

    LogicState::eLogicState output;

    if (inputX && inputY)
    {
        if (inputX->GetState() == LogicState::DISABLED || inputY->GetState() == LogicState::DISABLED)
        {
            // Case 1 D,D
            if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::DISABLED)
            {
                output = LogicState::DISABLED;
                return output;
            }
                // Case 2 D,F
            else if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::OFF)
            {
                output = LogicState::ON;
                return output;
            }
                // Case 3 F,D
            else if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::DISABLED)
            {
                output = LogicState::DISABLED;
                return output;
            }
                // Case 4 D,T
            else if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::ON)
            {
                output = LogicState::DISABLED;
                return output;
            }
                // Case 5 T,D
            else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::DISABLED)
            {
                output = LogicState::DISABLED;
                return output;
            }
        }
            // Neither input was Disabled:
        else
        {
            // Case 6 F,F
            if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::OFF)
            {
                output = LogicState::OFF;
                return output;
            }
                // Case 7 F,T
            else if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::ON)
            {
                output = LogicState::ON;
                return output;
            }
                // Case 8 T,F
            else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::OFF)
            {
                output = LogicState::ON;
                return output;
            }
                // Case 9 T,T
            else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::ON)
            {
                output = LogicState::OFF;
                return output;
            }
        }
    }
    else {
        std::cout<< "Both Inputs of XorGate weren't populated yet..." << std::endl;
        return LogicState::DISABLED;
    }
}
