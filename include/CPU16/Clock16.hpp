//
// Created by John on 6/1/2024.
//
#include "AbstractNode.hpp"

#ifndef LOGICGATESANDEVENTS_CLOCK16_HPP
#define LOGICGATESANDEVENTS_CLOCK16_HPP


class Clock16 : public AbstractNode {
public:
    Clock16(int frequency) : frequency(frequency), state(false) {}

    void tick() {
        state = !state;
        AbstractNode::Notify();
    }

    LogicState::eLogicState GetState() const override {
        if (state)
        {
            return LogicState::ON;
        }
        else
        {
            return LogicState::OFF;
        }
    }

    void Update(LogicState::eLogicState state) override {
        Notify();
    }

private:
    int frequency;
    bool state;
};


#endif //LOGICGATESANDEVENTS_CLOCK16_HPP
