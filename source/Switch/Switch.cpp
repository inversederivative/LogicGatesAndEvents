//
// Created by John on 3/12/2024.
//
#include <Switch/Switch.hpp>

void Switch::ChangeState(bool state) {
    state_ = state;
    Notify();
}

void Switch::ToggleState() {
    state_ = !state_;
    Notify();
}

bool Switch::GetState() const {
    return state_;
}

