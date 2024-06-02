//
// Created by John on 6/1/2024.
//
#include "AbstractNode.hpp"
#include <cstdint>

#ifndef LOGICGATESANDEVENTS_REGISTER_HPP
#define LOGICGATESANDEVENTS_REGISTER_HPP


class Register8 : public AbstractNode {
public:
    void loadValue(uint8_t value) {
        state = value;
        AbstractNode::Notify();
    }

    LogicState::eLogicState GetState() const override {

        return state ? LogicState::ON : LogicState::OFF;
    }

    uint8_t GetFullState() const {
        return state;
    }

    void Update(LogicState::eLogicState state) override {
        Notify();
    }

private:
    uint8_t state = 0;
};


#endif //LOGICGATESANDEVENTS_REGISTER_HPP
