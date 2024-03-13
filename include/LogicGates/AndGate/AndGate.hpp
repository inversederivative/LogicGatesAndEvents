//
// Created by John on 3/12/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_ANDGATE_HPP
#define LOGICGATESANDEVENTS_ANDGATE_HPP

class AndGate : public AbstractNode
{
private:
    AbstractNode* inputX;
    AbstractNode* inputY;
    LogicState::eLogicState outputState_ = LogicState::DISABLED;
    std::list<IObserver*> connectedNodes_;

public:

    //AndGate();

    void SetInputX(AbstractNode* input);
    void SetInputY(AbstractNode* input);

    void Update(LogicState::eLogicState state) override;

    LogicState::eLogicState GetState() const override;

};

#endif //LOGICGATESANDEVENTS_ANDGATE_HPP
