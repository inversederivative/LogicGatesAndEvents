//
// Created by John on 5/11/2024.
//
#include "AbstractNode.hpp"

#ifndef LOGICGATESANDEVENTS_BUFFERGATE_HPP
#define LOGICGATESANDEVENTS_BUFFERGATE_HPP

class BufferGate : public AbstractNode
{
private:

    AbstractNode* input;

    LogicState::eLogicState outputState_ = LogicState::DISABLED;
    std::list<IObserver*> connectedNodes_;

public:
    void SetInput(AbstractNode* in);

    void Update(LogicState::eLogicState state) override;

    LogicState::eLogicState GetState() const override;
};

#endif //LOGICGATESANDEVENTS_BUFFERGATE_HPP
