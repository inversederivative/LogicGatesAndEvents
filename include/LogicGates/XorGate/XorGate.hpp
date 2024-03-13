//
// Created by John on 3/13/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_XORGATE_HPP
#define LOGICGATESANDEVENTS_XORGATE_HPP

class XorGate : public AbstractNode
{
private:
    AbstractNode* inputX;
    AbstractNode* inputY;
    bool outputState_ = false;
    std::list<IObserver*> connectedNodes_;

public:

    void SetInputX(AbstractNode* input);
    void SetInputY(AbstractNode* input);

    void Update(bool state) override;

    bool GetState() const override;

};

#endif //LOGICGATESANDEVENTS_XORGATE_HPP
