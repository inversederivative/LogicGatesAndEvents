//
// Created by John on 3/13/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_TRISTATEBUFFERGATE_HPP
#define LOGICGATESANDEVENTS_TRISTATEBUFFERGATE_HPP
class TriStateBufferGate : public AbstractNode
{
private:
    AbstractNode* dataInput;
    AbstractNode* enableInput;
    LogicState::eLogicState outputState_ = LogicState::DISABLED;
    std::list<IObserver*> connectedNodes_;

public:

    void SetDataInput(AbstractNode* input);
    void SetEnableInput(AbstractNode* input);

    void Update(LogicState::eLogicState state) override;

    LogicState::eLogicState GetState() const override;
};
#endif //LOGICGATESANDEVENTS_TRISTATEBUFFERGATE_HPP
