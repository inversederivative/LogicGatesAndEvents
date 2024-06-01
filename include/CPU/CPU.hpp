//
// Created by John on 6/1/2024.
//
#include <AbstractNode.hpp>
#include <CPU/Clock.hpp>
#include <CPU/Register.hpp>
#include <CPU/ALU.hpp>
#include <cstdint>
#include <memory>
#include <vector>
#include <map>

#ifndef LOGICGATESANDEVENTS_CPU_HPP
#define LOGICGATESANDEVENTS_CPU_HPP




class CPU {
public:
    CPU();
    void loadInstruction(uint8_t instruction);
    void tickClock();

    std::vector<std::shared_ptr<Register>> GetRegisters() const;

    bool GetZeroFlag() const
    {
        return zeroFlag;
    }

    void SetZeroFlag(bool zFlag)
    {
        zeroFlag = zFlag;
    }

    std::shared_ptr<Register> GetProgramCounter() const
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
    bool zeroFlag = false; // Example flag, should be set based on operations
    uint8_t returnAddress;

    std::shared_ptr<Clock> clock;
    std::shared_ptr<Register> programCounter;
    std::shared_ptr<ALU> alu;
    std::vector<std::shared_ptr<Register>> registers;

    std::map<uint8_t, void (CPU::*)()> opcodeMap;
};

#endif //LOGICGATESANDEVENTS_CPU_HPP
