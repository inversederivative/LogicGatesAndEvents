//
// Created by John on 3/12/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_SWITCH_HPP
#define LOGICGATESANDEVENTS_SWITCH_HPP

class Switch : public AbstractNode
{
private:
    LogicState::eLogicState state_ = LogicState::DISABLED;

public:

    Switch() = default;
    explicit Switch(LogicState::eLogicState state);

    void ChangeState(LogicState::eLogicState state);
    void ToggleState();
    LogicState::eLogicState GetState() const override;

    void Update(LogicState::eLogicState state) override {
        // Do nothing!
        // The switch doesn't have any objects, this is just for show.
    }

};

#endif //LOGICGATESANDEVENTS_SWITCH_HPP
