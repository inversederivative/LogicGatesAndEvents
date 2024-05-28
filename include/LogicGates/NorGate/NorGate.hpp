//
// Created by John on 5/28/2024.
//
#include <LogicGates/AbstractTwoInputOneOutputGate.hpp>

#ifndef LOGICGATESANDEVENTS_NORGATE_HPP
#define LOGICGATESANDEVENTS_NORGATE_HPP


class NorGate : public AbstractTwoInputOneOutputNode {

public:

    LogicState::eLogicState GetState() const override;
};


#endif //LOGICGATESANDEVENTS_NORGATE_HPP
