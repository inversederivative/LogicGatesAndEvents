//
// Created by John on 3/12/2024.
//
#include "AbstractNode.hpp"

#ifndef LOGICGATESANDEVENTS_ANDGATE_HPP
#define LOGICGATESANDEVENTS_ANDGATE_HPP

class AndGate : public AbstractNode
{
private:
    AbstractNode* inputX;
    AbstractNode* inputY;
    bool outputState_ = false;
    std::list<IObserver*> connectedNodes_;

public:

    //AndGate();

    void SetInputX(AbstractNode* input);
    void SetInputY(AbstractNode* input);

    void Update(bool state) override;

    bool GetState() const override;

};

#endif //LOGICGATESANDEVENTS_ANDGATE_HPP
