//
// Created by John on 3/12/2024.
//
#include <LogicGates/AbstractTwoInputOneOutputGate.hpp>

#ifndef LOGICGATESANDEVENTS_ANDGATE_HPP
#define LOGICGATESANDEVENTS_ANDGATE_HPP

class AndGate : public AbstractTwoInputOneOutputNode
{
public:

    [[nodiscard]] LogicState::eLogicState GetState() const override;

};

#endif //LOGICGATESANDEVENTS_ANDGATE_HPP
