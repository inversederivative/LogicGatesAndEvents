//
// Created by John on 6/1/2024.
//
#include "AbstractNode.hpp"

#ifndef LOGICGATESANDEVENTS_CLOCK_HPP
#define LOGICGATESANDEVENTS_CLOCK_HPP


class Clock8 : public AbstractNode {
public:
    Clock8(int frequency) : frequency(frequency), state(false) {}

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


#endif //LOGICGATESANDEVENTS_CLOCK_HPP
