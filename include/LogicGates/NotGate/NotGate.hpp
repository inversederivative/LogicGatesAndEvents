//
// Created by John on 5/28/2024.
//
#include "AbstractNode.hpp"

#ifndef LOGICGATESANDEVENTS_NOTGATE_HPP
#define LOGICGATESANDEVENTS_NOTGATE_HPP



class NotGate : public AbstractNode {
private:
    AbstractNode* input;

    LogicState::eLogicState outputState_ = LogicState::DISABLED;
    std::list<IObserver*> connectedNodes_;

public:
    void SetInput(AbstractNode* in);

    void Update(LogicState::eLogicState state) override;

    LogicState::eLogicState GetState() const override;

};


#endif //LOGICGATESANDEVENTS_NOTGATE_HPP
