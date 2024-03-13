//
// Created by John on 3/13/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_ORGATE_HPP
#define LOGICGATESANDEVENTS_ORGATE_HPP

class OrGate : public AbstractNode
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

#endif //LOGICGATESANDEVENTS_ORGATE_HPP
