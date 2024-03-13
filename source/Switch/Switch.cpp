//
// Created by John on 3/12/2024.
//
#include <Switch/Switch.hpp>

Switch::Switch(LogicState::eLogicState state) {
    ChangeState(state);
}

void Switch::ChangeState(LogicState::eLogicState state) {
    state_ = state;
    Notify();
}

void Switch::ToggleState() {
    // We need to then check if disabled
    if (state_ != LogicState::DISABLED)
    {
        if (state_ == LogicState::OFF)
        {
            state_ = LogicState::ON;
        }
        else
        {
            state_ = LogicState::OFF;
        }
    }
    Notify();
}

LogicState::eLogicState Switch::GetState() const {
    return state_;
}

