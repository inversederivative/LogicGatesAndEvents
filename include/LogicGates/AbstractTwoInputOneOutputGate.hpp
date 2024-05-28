#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_ABSTRACTTWOINPUTONEOUTPUTNODE_HPP
#define LOGICGATESANDEVENTS_ABSTRACTTWOINPUTONEOUTPUTNODE_HPP

class AbstractTwoInputOneOutputNode : public AbstractNode
{
protected:
    AbstractNode* inputX;
    AbstractNode* inputY;

    LogicState::eLogicState outputState_;
    std::list<IObserver*> connectedNodes_;

public:

    AbstractTwoInputOneOutputNode();

    virtual void SetInputX(AbstractNode* input);
    virtual void SetInputY(AbstractNode* input);
    virtual void RemoveInputX();
    virtual void RemoveInputY();

    virtual void Update(LogicState::eLogicState state) override;

};



#endif // LOGICGATESANDEVENTS_ABSTRACTTWOINPUTONEOUTPUTNODE_HPP