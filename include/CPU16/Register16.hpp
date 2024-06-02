//
// Created by John on 6/1/2024.
//
#include "AbstractNode.hpp"
#include <cstdint>

#ifndef LOGICGATESANDEVENTS_REGISTER16_HPP
#define LOGICGATESANDEVENTS_REGISTER16_HPP


class Register16 : public AbstractNode {
public:
    void loadValue(uint16_t value) {
        state = value;
        AbstractNode::Notify();
    }

    LogicState::eLogicState GetState() const override {

        return state ? LogicState::ON : LogicState::OFF;
    }

    uint16_t GetFullState() const {
        return state;
    }

    void Update(LogicState::eLogicState state) override {
        Notify();
    }

private:
    uint16_t state = 0;
};


#endif //LOGICGATESANDEVENTS_REGISTER16_HPP
