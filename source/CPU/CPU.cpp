//
// Created by John on 6/1/2024.
//

#include "CPU/CPU.hpp"

// CPU class implementation
CPU::CPU() {
    clock = std::make_shared<Clock>(1);
    programCounter = std::make_shared<Register>();
    alu = std::make_shared<ALU>();

    // Initialize registers
    for (int i = 0; i < 8; ++i) {
        registers.push_back(std::make_shared<Register>());
    }

    // Map opcodes to their handlers
    opcodeMap = {
            {0x00, &CPU::nop},
            {0x01, &CPU::movRegisterToRegister},
            {0x02, &CPU::movImmediateToRegister},
            {0x03, &CPU::load},
            {0x04, &CPU::store},
            {0x10, &CPU::add},
            {0x11, &CPU::sub},
            {0x12, &CPU::inc},
            {0x13, &CPU::dec},
            {0x20, &CPU::andOp},
            {0x21, &CPU::orOp},
            {0x22, &CPU::xorOp},
            {0x23, &CPU::notOp},
            {0x40, &CPU::jmp},
            {0x41, &CPU::jz},
            {0x42, &CPU::jnz},
            {0x43, &CPU::call},
            {0x44, &CPU::ret},
            {0x60, &CPU::inOp},
            {0x61, &CPU::outOp},
            {0xFF, &CPU::hlt}
    };
}

void CPU::loadInstruction(uint8_t instruction) {
    this->instruction = instruction;
    decodeExecute();
}

void CPU::tickClock() {
    clock->tick();
}

void CPU::decodeExecute() {
    auto it = opcodeMap.find(instruction);
    if (it != opcodeMap.end()) {
        (this->*(it->second))();
    } else {
        std::cerr << "Unknown instruction: " << std::hex << +instruction << std::endl;
    }
}

void CPU::nop() {
    // No operation
}

void CPU::movRegisterToRegister() {
    // Example: Move value from register 1 to register 2
    // In a real implementation, decode operands from the instruction
    uint8_t value = registers[1]->GetState();
    registers[2]->loadValue(value);
}

void CPU::movImmediateToRegister() {
    // Example: Move immediate value to register 1
    // In a real implementation, decode operands from the instruction
    registers[1]->loadValue(42); // Immediate value
}

void CPU::load() {
    // Load data from memory (not implemented) to register
}

void CPU::store() {
    // Store data from register to memory (not implemented)
}

void CPU::add() {
    alu->setInputs(registers[1]->GetState(), registers[2]->GetState());
    alu->setOperation(ALU::ADD);
    registers[0]->loadValue(alu->GetState());
}

void CPU::sub() {
    alu->setInputs(registers[1]->GetState(), registers[2]->GetState());
    alu->setOperation(ALU::SUB);
    registers[0]->loadValue(alu->GetState());
}

void CPU::inc() {
    registers[1]->loadValue(registers[1]->GetState() + 1);
}

void CPU::dec() {
    registers[1]->loadValue(registers[1]->GetState() - 1);
}

void CPU::andOp() {
    alu->setInputs(registers[1]->GetState(), registers[2]->GetState());
    alu->setOperation(ALU::AND);
    registers[0]->loadValue(alu->GetState());
}

void CPU::orOp() {
    alu->setInputs(registers[1]->GetState(), registers[2]->GetState());
    alu->setOperation(ALU::OR);
    registers[0]->loadValue(alu->GetState());
}

void CPU::xorOp() {
    alu->setInputs(registers[1]->GetState(), registers[2]->GetState());
    alu->setOperation(ALU::XOR);
    registers[0]->loadValue(alu->GetState());
}

void CPU::notOp() {
    alu->setInputs(registers[1]->GetState(), 0);
    alu->setOperation(ALU::NOT);
    registers[0]->loadValue(alu->GetState());
}

void CPU::jmp() {
    // Example: Jump to address (not implemented)
    // In a real implementation, decode address from the instruction
    programCounter->loadValue(10); // Example address
}

void CPU::jz() {
    // Example: Jump to address if zero flag is set (not implemented)
    // In a real implementation, decode address from the instruction
    if (zeroFlag) {
        programCounter->loadValue(10); // Example address
    }
}

void CPU::jnz() {
    // Example: Jump to address if zero flag is not set (not implemented)
    // In a real implementation, decode address from the instruction
    if (!zeroFlag) {
        programCounter->loadValue(10); // Example address
    }
}

void CPU::call() {
    // Example: Call subroutine at address (not implemented)
    // In a real implementation, decode address from the instruction
    // Save current PC, then jump to address
    returnAddress = programCounter->GetState();
    programCounter->loadValue(10); // Example subroutine address
}

void CPU::ret() {
    // Return from subroutine (not implemented)
    // Load saved return address into PC
    programCounter->loadValue(returnAddress);
}

void CPU::inOp() {
    // Input operation (not implemented)
}

void CPU::outOp() {
    // Output operation (not implemented)
}

void CPU::hlt() {
    // Halt the CPU
    halted = true;
}

std::vector<std::shared_ptr<Register>> CPU::GetRegisters() const {
    return registers;
}
