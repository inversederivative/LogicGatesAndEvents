//
// Created by John on 5/28/2024.
//

#include "LogicGates/NorGate/NorGate.hpp"

LogicState::eLogicState NorGate::GetState() const
{
    LogicState::eLogicState output = LogicState::DISABLED;

    if (inputX->GetState() == LogicState::DISABLED || inputY->GetState() == LogicState::DISABLED)
    {
        // Case 1 D,D
        if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::DISABLED)
        {
            output = LogicState::DISABLED;
        }
            // Case 2 D,F
        else if (inputX->GetState() == LogicState::DISABLED && inputY->GetState() == LogicState::OFF)
        {
            output = LogicState::DISABLED;
        }
            // Case 3 F,D
        else if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::DISABLED)
        {
            output = LogicState::DISABLED;
        }
            // Case 4 D,T
        else if (inputX->GetState() == LogicState::DISABLED && inputY->GetState()== LogicState::ON)
        {
            output = LogicState::DISABLED;
        }
            // Case 5 T,D
        else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::DISABLED)
        {
            output = LogicState::DISABLED;
        }
    }
        // Neither input was Disabled:
    else
    {
        // Case 6 F,F
        if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::OFF)
        {
            output = LogicState::ON;
        }
            // Case 7 F,T
        else if (inputX->GetState() == LogicState::OFF && inputY->GetState() == LogicState::ON)
        {
            output = LogicState::OFF;
        }
            // Case 8 T,F
        else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::OFF)
        {
            output = LogicState::OFF;
        }
            // Case 9 T,T
        else if (inputX->GetState() == LogicState::ON && inputY->GetState() == LogicState::ON)
        {
            output = LogicState::OFF;
        }
    }

    return output;
}
