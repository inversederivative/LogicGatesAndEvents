//
// Created by John on 3/12/2024.
//
#include <LogicGates/AndGate/AndGate.hpp>


// Totally need to redo:

LogicState::eLogicState AndGate::GetState() const {
//    // Compute the state of the AND gate based on its inputs
//    if (inputX && inputY) {
//        if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::ON)
//        {
//            return LogicState::ON;
//        }
//        else if (
//        (inputX->GetState() == LogicState::ON || inputY->GetState() == LogicState::OFF) ||
//        (inputX->GetState() == LogicState::OFF || inputY->GetState() == LogicState::ON) ||
//        (inputX->GetState() == LogicState::OFF || inputY->GetState() == LogicState::OFF) )
//        {
//            return LogicState::OFF;
//        }
//
//    } else {
//        // Handle case where inputs are not set
//        return LogicState::DISABLED; // Or some default value depending on your requirements
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
                output = LogicState::DISABLED;
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
                output = LogicState::OFF;
                return output;
            }
                // Case 8 T,F
            else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::OFF)
            {
                output = LogicState::OFF;
                return output;
            }
                // Case 9 T,T
            else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::ON)
            {
                output = LogicState::ON;
                return output;
            }
        }
    }
    else {
        std::cout<< "Both Inputs of AndGate weren't populated yet..." << std::endl;
        output = LogicState::DISABLED;
        return output;
    }
}
