//
// Created by John on 3/12/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_DISPLAY_HPP
#define LOGICGATESANDEVENTS_DISPLAY_HPP

class Display : public AbstractNode
{
private:
    // Don't need this, because the Display has NO observers!!!
    std::list<IObserver*> connectedNodes_;
    AbstractNode* input_;
    LogicState::eLogicState state_ = LogicState::DISABLED;

public:

    void SetInput(AbstractNode* input);

    LogicState::eLogicState GetState() const override;

    void Update(LogicState::eLogicState state) override;

};

#endif //LOGICGATESANDEVENTS_DISPLAY_HPP
