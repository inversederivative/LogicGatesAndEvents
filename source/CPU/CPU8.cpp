//
// Created by John on 6/1/2024.
//

#include "CPU8/CPU8.hpp"

// CPU class implementation
CPU8::CPU8() {
    clock = std::make_shared<Clock8>(1);
    programCounter = std::make_shared<Register8>();
    alu = std::make_shared<ALU8>();

    // Initialize registers
    for (int i = 0; i < 8; ++i) {
        registers.push_back(std::make_shared<Register8>());
    }

    // Map opcodes to their handlers
    opcodeMap = {
            {0x00, &CPU8::nop},
            {0x01, &CPU8::movRegisterToRegister},
            {0x02, &CPU8::movImmediateToRegister},
            {0x03, &CPU8::load},
            {0x04, &CPU8::store},
            {0x10, &CPU8::add},
            {0x11, &CPU8::sub},
            {0x12, &CPU8::inc},
            {0x13, &CPU8::dec},
            {0x20, &CPU8::andOp},
            {0x21, &CPU8::orOp},
            {0x22, &CPU8::xorOp},
            {0x23, &CPU8::notOp},
            {0x40, &CPU8::jmp},
            {0x41, &CPU8::jz},
            {0x42, &CPU8::jnz},
            {0x43, &CPU8::call},
            {0x44, &CPU8::ret},
            {0x60, &CPU8::inOp},
            {0x61, &CPU8::outOp},
            {0xFF, &CPU8::hlt}
    };
}

void CPU8::loadInstruction(uint8_t instruction, uint8_t operand1, uint8_t operand2) {
    this->instruction = instruction;
    this->operand1 = operand1;
    this->operand2 = operand2;
    decodeExecute();
}

void CPU8::tickClock() {
    clock->tick();
}

void CPU8::decodeExecute() {
    auto it = opcodeMap.find(instruction);
    if (it != opcodeMap.end()) {
        (this->*(it->second))();
    } else {
        std::cerr << "Unknown instruction: " << std::hex << +instruction << std::endl;
    }
}

void CPU8::nop() {
    // No operation
}

void CPU8::movRegisterToRegister() {
    uint8_t src = (operand1 & 0xF0) >> 4;
    uint8_t dest = operand1 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        registers[dest]->loadValue(registers[src]->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
    }
}

void CPU8::movImmediateToRegister() {
    uint8_t dest = operand1 & 0x0F;
    if (dest < registers.size()) {
        registers[dest]->loadValue(operand2);
    } else {
        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
    }
}

void CPU8::load() {
    // Load data from memory (not implemented) to register
}

void CPU8::store() {
    // Store data from register to memory (not implemented)
}

void CPU8::add() {
    uint8_t dest = (operand1 & 0xF0) >> 4;
    uint8_t src = operand1 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
        alu->setOperation(ALU8::ADD);
        registers[dest]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
    }
}

void CPU8::sub() {
    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
    alu->setOperation(ALU8::SUB);
    registers[0]->loadValue(alu->GetFullState());
}

void CPU8::inc() {
    registers[1]->loadValue(registers[1]->GetFullState() + 1);
}

void CPU8::dec() {
    registers[1]->loadValue(registers[1]->GetFullState() - 1);
}

void CPU8::andOp() {
    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
    alu->setOperation(ALU8::AND);
    registers[0]->loadValue(alu->GetFullState());
}

void CPU8::orOp() {
    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
    alu->setOperation(ALU8::OR);
    registers[0]->loadValue(alu->GetFullState());
}

void CPU8::xorOp() {
    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
    alu->setOperation(ALU8::XOR);
    registers[0]->loadValue(alu->GetFullState());
}

void CPU8::notOp() {
    alu->setInputs(registers[1]->GetFullState(), 0);
    alu->setOperation(ALU8::NOT);
    registers[0]->loadValue(alu->GetFullState());
}

void CPU8::jmp() {
    // Example: Jump to address (not implemented)
    // In a real implementation, decode address from the instruction
    programCounter->loadValue(operand1); // Use operand1 as the address
}

void CPU8::jz() {
    // Example: Jump to address if zero flag is set (not implemented)
    // In a real implementation, decode address from the instruction
    if (zeroFlag) {
        programCounter->loadValue(operand1); // Use operand1 as the address
    }
}

void CPU8::jnz() {
    // Example: Jump to address if zero flag is not set (not implemented)
    // In a real implementation, decode address from the instruction
    if (!zeroFlag) {
        programCounter->loadValue(operand1); // Use operand1 as the address
    }
}

void CPU8::call() {
    // Example: Call subroutine at address (not implemented)
    // In a real implementation, decode address from the instruction
    // Save current PC, then jump to address
    returnAddress = programCounter->GetFullState();
    programCounter->loadValue(operand1); // Use operand1 as the subroutine address
}

void CPU8::ret() {
    // Return from subroutine (not implemented)
    // Load saved return address into PC
    programCounter->loadValue(returnAddress);
}

void CPU8::inOp() {
    // Input operation (not implemented)
}

void CPU8::outOp() {
    // Output operation (not implemented)
}

void CPU8::hlt() {
    // Halt the CPU
    halted = true;
}

std::vector<std::shared_ptr<Register8>> CPU8::GetRegisters() const {
    return registers;
}
