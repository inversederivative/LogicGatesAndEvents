//
// Created by John on 6/1/2024.
//
#include <AbstractNode.hpp>
#include <CPU8/Clock8.hpp>
#include <CPU8/Register8.hpp>
#include <CPU8/ALU8.hpp>
#include <cstdint>
#include <memory>
#include <vector>
#include <map>

#ifndef LOGICGATESANDEVENTS_CPU_HPP
#define LOGICGATESANDEVENTS_CPU_HPP




class CPU8 {
public:
    CPU8();
    void loadInstruction(uint8_t instruction, uint8_t operand1 = -1, uint8_t operand2 = -1);
    void tickClock();

    std::vector<std::shared_ptr<Register8>> GetRegisters() const;

    bool GetZeroFlag() const
    {
        return zeroFlag;
    }

    void SetZeroFlag(bool zFlag)
    {
        zeroFlag = zFlag;
    }

    std::shared_ptr<Register8> GetProgramCounter() const
    {
        return programCounter;
    }

    bool halted = false;

private:
    void decodeExecute();
    void nop();
    void movRegisterToRegister();
    void movImmediateToRegister();
    void load();
    void store();
    void add();
    void sub();
    void inc();
    void dec();
    void andOp();
    void orOp();
    void xorOp();
    void notOp();
    void jmp();
    void jz();
    void jnz();
    void call();
    void ret();
    void inOp();
    void outOp();
    void hlt();

    uint8_t instruction;
    uint8_t operand1;
    uint8_t operand2;
    bool zeroFlag = false; // Example flag, should be set based on operations
    uint8_t returnAddress;

    std::shared_ptr<Clock8> clock;
    std::shared_ptr<Register8> programCounter;
    std::shared_ptr<ALU8> alu;
    std::vector<std::shared_ptr<Register8>> registers;

    std::map<uint8_t, void (CPU8::*)()> opcodeMap;
};

#endif //LOGICGATESANDEVENTS_CPU_HPP
