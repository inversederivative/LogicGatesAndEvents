//
// Created by John on 3/13/2024.
//
#include <AbstractNode.hpp>

#include <LogicGates/XorGate/XorGate.hpp>
#include <LogicGates/AndGate/AndGate.hpp>
#include <LogicGates/OrGate/OrGate.hpp>

#ifndef LOGICGATESANDEVENTS_FULLADDER_HPP
#define LOGICGATESANDEVENTS_FULLADDER_HPP

class FullAdder : public AbstractNode
{
private:
    AbstractNode* inputX;
    AbstractNode* inputY;
    AbstractNode* carryIn;

    XorGate* xorGateA;
    AndGate* andGateA;
    XorGate* xorGateB;
    AndGate* andGateB;
    OrGate* orGate;

    bool outputSumState_ = false;
    bool outputCarryState_ = false;
    bool inputCarryState_ = false;
    std::list<IObserver*> connectedNodes_;

public:

    FullAdder();

    void SetInputX(AbstractNode* input);

    void SetInputY(AbstractNode* input);

    void SetCarryIn(AbstractNode* carry);

    void Update(bool state) override;

    bool GetState() const override;

    bool GetCarryOut() const;

};

#endif //LOGICGATESANDEVENTS_FULLADDER_HPP
