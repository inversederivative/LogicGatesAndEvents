//
// Created by John on 3/12/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_SWITCH_HPP
#define LOGICGATESANDEVENTS_SWITCH_HPP

class Switch : public AbstractNode
{
private:
    bool state_ = false;

public:

    Switch() = default;
    explicit Switch(bool state);

    void ChangeState(bool state);
    void ToggleState();
    bool GetState() const override;

    void Update(bool state) override {
        // Do nothing!
        // The switch doesn't have any objects, this is just for show.
    }

};

#endif //LOGICGATESANDEVENTS_SWITCH_HPP
