//
// Created by John on 5/11/2024.
//
#include <AbstractNode.hpp>
#include <Adders/FullAdder/FullAdder.hpp>


#ifndef LOGICGATESANDEVENTS_FOURBITADDER_HPP
#define LOGICGATESANDEVENTS_FOURBITADDER_HPP

class FourBitAdder : public AbstractNode
{
    AbstractNode* inputX1;
    AbstractNode* inputX2;
    AbstractNode* inputX3;
    AbstractNode* inputX4;

    AbstractNode* inputY1;
    AbstractNode* inputY2;
    AbstractNode* inputY3;
    AbstractNode* inputY4;

    AbstractNode* carryIn;

    FullAdder* adder1;
    FullAdder* adder2;
    FullAdder* adder3;
    FullAdder* adder4;

    LogicState::eLogicState outputSumState1_ = LogicState::DISABLED;
    LogicState::eLogicState outputSumState2_ = LogicState::DISABLED;
    LogicState::eLogicState outputSumState3_ = LogicState::DISABLED;
    LogicState::eLogicState outputSumState4_ = LogicState::DISABLED;

    LogicState::eLogicState outputCarryState_ = LogicState::DISABLED;
    LogicState::eLogicState inputCarryState_ = LogicState::DISABLED;

    std::list<IObserver*> connectNodes_;


public:

    FourBitAdder();

    void SetInputX1(AbstractNode* input);
    void SetInputX2(AbstractNode* input);
    void SetInputX3(AbstractNode* input);
    void SetInputX4(AbstractNode* input);

    void SetInputY1(AbstractNode* input);
    void SetInputY2(AbstractNode* input);
    void SetInputY3(AbstractNode* input);
    void SetInputY4(AbstractNode* input);

    void SetCarryIn(AbstractNode* input);

    void Update(LogicState::eLogicState state) override;

    LogicState::eLogicState GetState() const override;

    LogicState::eLogicState GetStateSum1() const;

    LogicState::eLogicState GetStateSum2() const;

    LogicState::eLogicState GetStateSum3() const;

    LogicState::eLogicState GetStateSum4() const;

    LogicState::eLogicState GetCarryOut() const;

};

#endif //LOGICGATESANDEVENTS_FOURBITADDER_HPP
