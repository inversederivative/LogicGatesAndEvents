//
// Created by John on 3/13/2024.
//
#include <AbstractNode.hpp>
#include <LogicGates/XorGate/XorGate.hpp>
#include <LogicGates/AndGate/AndGate.hpp>

#ifndef LOGICGATESANDEVENTS_HALFADDER_HPP
#define LOGICGATESANDEVENTS_HALFADDER_HPP


class HalfAdder : public AbstractNode
{
private:
    AbstractNode* inputX;
    AbstractNode* inputY;

    XorGate* xorGate;
    AndGate* andGate;

    bool outputSumState_ = false;
    bool outputCarryState_ = false;
    std::list<IObserver*> connectedNodes_;

public:

    HalfAdder();

    void SetInputX(AbstractNode* input);
    void SetInputY(AbstractNode* input);

    void Update(bool state) override;

    bool GetState() const override;

    bool GetCarry() const;

};

#endif //LOGICGATESANDEVENTS_HALFADDER_HPP
