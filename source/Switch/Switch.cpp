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

LogicState::eLogicState Switch::GetState() const {
    return state_;
}

