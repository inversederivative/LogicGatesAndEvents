//
// Created by John on 6/1/2024.
//
#include <AbstractNode.hpp>
#include <CPU16/Clock16.hpp>
#include <CPU16/Register16.hpp>
#include <CPU16/ALU16.hpp>
#include <CPU16/Memory16.hpp>
#include <cstdint>
#include <memory>
#include <vector>
#include <map>

#ifndef LOGICGATESANDEVENTS_CPU16_HPP
#define LOGICGATESANDEVENTS_CPU16_HPP

class CPU16 {
public:
    CPU16(size_t memorySize);
    void loadInstruction(uint16_t instruction, uint16_t operand1 = 0, uint16_t operand2 = 0);
    void tickClock();
    void run();
    void loadProgram(const std::vector<uint16_t>& program, uint16_t startAddress);

    std::vector<std::shared_ptr<Register16>> GetRegisters() const;
    bool GetZeroFlag() const;
    void SetZeroFlag(bool zFlag);
    std::shared_ptr<Register16> GetProgramCounter() const;
    bool halted = false;

    std::shared_ptr<Memory16> GetMemory() const; // Make memory accessible for testing



private:
    void fetch();
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

    uint16_t instruction;
    uint16_t operand1;
    uint16_t operand2;
    bool zeroFlag = false; // Example flag, should be set based on operations
    uint16_t returnAddress;

    std::shared_ptr<Clock16> clock;
    std::shared_ptr<Register16> programCounter;
    std::shared_ptr<ALU16> alu;
    std::vector<std::shared_ptr<Register16>> registers;

    std::map<uint16_t, void (CPU16::*)()> opcodeMap;

    std::shared_ptr<Memory16> memory;
};

#endif //LOGICGATESANDEVENTS_CPU16_HPP
