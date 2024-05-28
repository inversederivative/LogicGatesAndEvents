//
// Created by John on 3/13/2024.
//
#include <AbstractNode.hpp>

#include <LogicGates/XorGate/XorGate.hpp>
#include <LogicGates/AndGate/AndGate.hpp>
#include <LogicGates/OrGate/OrGate.hpp>
#include "LogicGates/BufferGate/BufferGate.hpp"

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

    BufferGate* carryOutNode;

    LogicState::eLogicState outputSumState_ = LogicState::DISABLED;
    LogicState::eLogicState outputCarryState_ = LogicState::DISABLED;
    LogicState::eLogicState inputCarryState_ = LogicState::OFF;
    std::list<IObserver*> connectedNodes_;

public:

    FullAdder();

    void SetInputX(AbstractNode* input);

    void SetInputY(AbstractNode* input);

    void SetCarryIn(AbstractNode* carry);

    AbstractNode* GetCarryOutNode() const;

    void Update(LogicState::eLogicState state) override;

    LogicState::eLogicState GetState() const override;

    LogicState::eLogicState GetCarryOut() const;

};

#endif //LOGICGATESANDEVENTS_FULLADDER_HPP
