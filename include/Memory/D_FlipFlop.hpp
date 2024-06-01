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


    LogicState::eLogicState dataInputState_;
    LogicState::eLogicState enableInputState_;
    LogicState::eLogicState outputQState_;
    LogicState::eLogicState outputQBarState_;

    LogicState::eLogicState prevEnableState;

public:

    D_FlipFlop();

    void SetInputData(AbstractNode* input);

    void SetInputEnable(AbstractNode* input);

    LogicState::eLogicState GetState() const override;

    LogicState::eLogicState GetQBarState() const;

    void Update(LogicState::eLogicState state) override;

};


#endif //LOGICGATESANDEVENTS_D_FLIPFLOP_HPP
