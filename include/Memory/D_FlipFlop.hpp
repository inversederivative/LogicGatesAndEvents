//
// Created by John on 5/28/2024.
//
#include "AbstractNode.hpp"
#include "LogicGates/AndGate/AndGate.hpp"
#include "LogicGates/NotGate/NotGate.hpp"
#include "LogicGates/NorGate/NorGate.hpp"

#ifndef LOGICGATESANDEVENTS_D_FLIPFLOP_HPP
#define LOGICGATESANDEVENTS_D_FLIPFLOP_HPP




class D_FlipFlop : public AbstractNode {
private:

    AbstractNode* inputData;
    AbstractNode* inputEnable;

    std::list<IObserver*> connectedNodes_;


    LogicState::eLogicState dataInputState_ = LogicState::DISABLED;
    LogicState::eLogicState enableInputState_ = LogicState::DISABLED;
    LogicState::eLogicState outputQState_ = LogicState::DISABLED;
    LogicState::eLogicState outputQBarState_ = LogicState::DISABLED;

    NotGate* notGate;
    AndGate* andGateOne;
    AndGate* andGateTwo;
    NorGate* norGateOne;
    NorGate* norGateTwo;

public:

    D_FlipFlop();

    void SetInputData(AbstractNode* input);

    void SetInputEnable(AbstractNode* input);

    LogicState::eLogicState GetState() const override;

    LogicState::eLogicState GetQBarState() const;



};


#endif //LOGICGATESANDEVENTS_D_FLIPFLOP_HPP
