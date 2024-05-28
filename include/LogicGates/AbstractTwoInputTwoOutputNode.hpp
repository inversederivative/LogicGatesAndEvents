//
// Created by John on 5/28/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_ABSTRACTTWOINPUTTWOOUTPUTNODE_HPP
#define LOGICGATESANDEVENTS_ABSTRACTTWOINPUTTWOOUTPUTNODE_HPP


class AbstractTwoInputTwoOutputNode : public AbstractNode {

protected:
    AbstractNode* inputX;
    AbstractNode* inputY;

    LogicState::eLogicState outputState_;
    std::list<IObserver*> connectedNodes_;

public:

    AbstractTwoInputTwoOutputNode();

    virtual void SetInputX(AbstractNode* input);
    virtual void SetInputY(AbstractNode* input);
    virtual void RemoveInputX();
    virtual void RemoveInputY();

    virtual void Update(LogicState::eLogicState state) override;
};


#endif //LOGICGATESANDEVENTS_ABSTRACTTWOINPUTTWOOUTPUTNODE_HPP
