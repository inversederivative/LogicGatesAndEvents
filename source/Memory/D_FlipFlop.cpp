//
// Created by John on 5/28/2024.
//

#include "Memory/D_FlipFlop.hpp"

//D_FlipFlop::D_FlipFlop() {
//    notGate = new NotGate();
//    andGateOne = new AndGate();
//    andGateTwo = new AndGate();
//    norGateOne = new NorGate();
//    norGateTwo = new NorGate;
//
//    connectedNodes_ = {};
//}
//
//void D_FlipFlop::SetInputData(AbstractNode *input) {
//    inputData = input;
//    input->Attach(this);
//
//    // Set inputs
//    notGate->SetInput(input);
//    andGateTwo->SetInputY(input);
//
//
//    connectedNodes_.push_back(input);
//    D_FlipFlop::Update(GetState());
//}
//
//void D_FlipFlop::SetInputEnable(AbstractNode *input) {
//    inputEnable = input;
//    input->Attach(this);
//
//    andGateOne->SetInputY(input);
//    andGateTwo->SetInputX(input);
//
//    connectedNodes_.push_back(input);
//    D_FlipFlop::Update(GetState());
//}
//
//LogicState::eLogicState D_FlipFlop::GetState() const {
//
//    // Note, this comes from the original TriStateLogicGates project. Needs to be modified a bit.
//
//    if (inputData && inputEnable)
//    {
//        return norGateOne->GetState();
//    }
//    return LogicState::DISABLED; // If both inputs are not yet set, then return disabled.
//}
//
//LogicState::eLogicState D_FlipFlop::GetQBarState() const {
//    return LogicState::DISABLED;
//}
//
//void D_FlipFlop::Update(LogicState::eLogicState state) {
//
//    notGate->Update(notGate->GetState());
//    andGateOne->SetInputX(notGate);
//    andGateOne->Update(andGateOne->GetState());
//    andGateTwo->Update(andGateTwo->GetState());
//    norGateOne->SetInputX(andGateOne);
//    norGateTwo->SetInputY(andGateTwo);
//    norGateOne->SetInputY(norGateTwo);
//    norGateTwo->SetInputX(norGateOne);
//    norGateOne->Update(norGateOne->GetState());
//    norGateTwo->Update(norGateTwo->GetState());
//
//    Notify();
//}


D_FlipFlop::D_FlipFlop() {
    inputData = nullptr;
    inputEnable = nullptr;
    dataInputState_ = LogicState::DISABLED;
    enableInputState_ = LogicState::DISABLED;
    outputQState_ = LogicState::OFF;
    outputQBarState_ = LogicState::ON;
    prevEnableState = LogicState::OFF;
}

void D_FlipFlop::SetInputData(AbstractNode* input) {
    inputData = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    D_FlipFlop::Update(LogicState::DISABLED); // Force an initial update to set state correctly
}

void D_FlipFlop::SetInputEnable(AbstractNode* input) {
    inputEnable = input;
    input->Attach(this);
    connectedNodes_.push_back(input);
    D_FlipFlop::Update(LogicState::DISABLED); // Force an initial update to set state correctly
}

LogicState::eLogicState D_FlipFlop::GetState() const {
    return outputQState_;
}

LogicState::eLogicState D_FlipFlop::GetQBarState() const {
    return outputQBarState_;
}

//void D_FlipFlop::Update(LogicState::eLogicState state) {
//    // Update internal states based on input nodes
//    if (inputData) {
//        dataInputState_ = inputData->GetState();
//    }
//    if (inputEnable) {
//        enableInputState_ = inputEnable->GetState();
//    }
//
//    // Check for rising edge of the enable signal
//    static LogicState::eLogicState prevEnableState = LogicState::OFF;
//
//    // Handle enable signal transitions
//    if (enableInputState_ == LogicState::ON && prevEnableState != LogicState::ON) {
//        // Capture the data input on rising edge of enable signal
//        if (dataInputState_ == LogicState::ON) {
//            outputQState_ = LogicState::ON;
//            outputQBarState_ = LogicState::OFF;
//        } else if (dataInputState_ == LogicState::OFF) {
//            outputQState_ = LogicState::OFF;
//            outputQBarState_ = LogicState::ON;
//        }
//    }
//
//    if (enableInputState_ == LogicState::DISABLED) {
//        // If enable input is disabled, the output is disabled
//        outputQState_ = LogicState::DISABLED;
//        outputQBarState_ = LogicState::DISABLED;
//    } else if (enableInputState_ == LogicState::OFF) {
//        // If enable input is OFF, maintain the last state unless it is DISABLED
//        if (outputQState_ == LogicState::DISABLED || outputQBarState_ == LogicState::DISABLED) {
//            outputQState_ = LogicState::OFF;
//            outputQBarState_ = LogicState::ON;
//        }
//    }
//
//    prevEnableState = enableInputState_;
//
//    Notify();
//}


void D_FlipFlop::Update(LogicState::eLogicState state) {
    if (inputData) {
        dataInputState_ = inputData->GetState();
    }
    if (inputEnable) {
        enableInputState_ = inputEnable->GetState();
    }

    if (enableInputState_ == LogicState::ON && prevEnableState == LogicState::OFF) {
        if (dataInputState_ == LogicState::ON) {
            outputQState_ = LogicState::ON;
            outputQBarState_ = LogicState::OFF;
        } else if (dataInputState_ == LogicState::OFF) {
            outputQState_ = LogicState::OFF;
            outputQBarState_ = LogicState::ON;
        }
    }

//    if (enableInputState_ == LogicState::DISABLED) {
//        outputQState_ = LogicState::DISABLED;
//        outputQBarState_ = LogicState::DISABLED;
//    } else
    if (enableInputState_ == LogicState::OFF || enableInputState_ == LogicState::DISABLED) {
        if (outputQState_ == LogicState::DISABLED || outputQBarState_ == LogicState::DISABLED) {
            outputQState_ = LogicState::OFF;
            outputQBarState_ = LogicState::ON;
        }
        prevEnableState = LogicState::OFF;
    }
    else
    {
        prevEnableState = enableInputState_;
    }


    Notify();
}