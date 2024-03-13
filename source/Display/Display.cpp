//
// Created by John on 3/13/2024.
//
#include <Display/Display.hpp>

void Display::SetInput(AbstractNode *input) {
    input_ = input;
    input_->Attach(this);
    Display::Update(input->GetState());
}

bool Display::GetState() const {
    return state_;
}

void Display::Update(bool state) {
    state_ = state;
    Notify();
}
