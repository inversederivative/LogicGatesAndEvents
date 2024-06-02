//
// Created by John on 6/1/2024.
//
#include <AbstractNode.hpp>
#include <cstdint>

#ifndef LOGICGATESANDEVENTS_ALU_HPP
#define LOGICGATESANDEVENTS_ALU_HPP


class ALU8 : public AbstractNode {
public:
    enum Operation { ADD, SUB, AND, OR, XOR, NOT };

    void setInputs(uint8_t a, uint8_t b) {
        this->a = a;
        this->b = b;
        Update(LogicState::DISABLED); // Note we don't need any value here.
    }

    void setOperation(Operation op) {
        this->op = op;
    Update(LogicState::DISABLED); // Note we don't need any value here.
    }

    void Update(LogicState::eLogicState) override {
        switch (op) {
            case ADD:
                result = a + b;
                break;
            case SUB:
                result = a - b;
                break;
            case AND:
                result = a & b;
                break;
            case OR:
                result = a | b;
                break;
            case XOR:
                result = a ^ b;
                break;
            case NOT:
                result = ~a;
                break;
        }
        Notify();
    }

    LogicState::eLogicState GetState() const override {
        return result ? LogicState::ON : LogicState::OFF;
    }

    uint8_t GetFullState() const
    {
        return result;
    }

private:
    uint8_t a, b;
    uint8_t result;
    Operation op;
};

#endif //LOGICGATESANDEVENTS_ALU_HPP
