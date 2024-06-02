//
// Created by John on 6/1/2024.
//

#include "CPU16/CPU16.hpp"

//// CPU class implementation
//CPU16::CPU16() {
//    clock = std::make_shared<Clock16>(1);
//    programCounter = std::make_shared<Register16>();
//    alu = std::make_shared<ALU16>();
//
//    // Initialize registers
//    for (int i = 0; i < 8; ++i) {
//        registers.push_back(std::make_shared<Register16>());
//    }
//
//    // Map opcodes to their handlers
//    opcodeMap = {
//            {0x00, &CPU16::nop},
//            {0x01, &CPU16::movRegisterToRegister},
//            {0x02, &CPU16::movImmediateToRegister},
//            {0x03, &CPU16::load},
//            {0x04, &CPU16::store},
//            {0x10, &CPU16::add},
//            {0x11, &CPU16::sub},
//            {0x12, &CPU16::inc},
//            {0x13, &CPU16::dec},
//            {0x20, &CPU16::andOp},
//            {0x21, &CPU16::orOp},
//            {0x22, &CPU16::xorOp},
//            {0x23, &CPU16::notOp},
//            {0x40, &CPU16::jmp},
//            {0x41, &CPU16::jz},
//            {0x42, &CPU16::jnz},
//            {0x43, &CPU16::call},
//            {0x44, &CPU16::ret},
//            {0x60, &CPU16::inOp},
//            {0x61, &CPU16::outOp},
//            {0xFF, &CPU16::hlt}
//    };
//}
//
//void CPU16::loadInstruction(uint16_t instruction, uint16_t operand1, uint16_t operand2) {
//    this->instruction = instruction;
//    this->operand1 = operand1;
//    this->operand2 = operand2;
//    decodeExecute();
//}
//
//void CPU16::tickClock() {
//    clock->tick();
//}
//
//void CPU16::decodeExecute() {
//    auto it = opcodeMap.find(instruction);
//    if (it != opcodeMap.end()) {
//        (this->*(it->second))();
//    } else {
//        std::cerr << "Unknown instruction: " << std::hex << +instruction << std::endl;
//    }
//}
//
//void CPU16::nop() {
//    // No operation
//}
//
//void CPU16::movRegisterToRegister() {
//    uint16_t src = (operand1 & 0xF0) >> 4;
//    uint16_t dest = operand1 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        registers[dest]->loadValue(registers[src]->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::movImmediateToRegister() {
//    uint16_t dest = operand1 & 0x0F;
//    if (dest < registers.size()) {
//        registers[dest]->loadValue(operand2);
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::load() {
//    // Load data from memory (not implemented) to register
//}
//
//void CPU16::store() {
//    // Store data from register to memory (not implemented)
//}
//
//void CPU16::add() {
//    uint16_t dest = (operand1 & 0xF0) >> 4;
//    uint16_t src = operand1 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
//        alu->setOperation(ALU16::ADD);
//        registers[dest]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::sub() {
//    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
//    alu->setOperation(ALU16::SUB);
//    registers[0]->loadValue(alu->GetFullState());
//}
//
//void CPU16::inc() {
//    registers[1]->loadValue(registers[1]->GetFullState() + 1);
//}
//
//void CPU16::dec() {
//    registers[1]->loadValue(registers[1]->GetFullState() - 1);
//}
//
//void CPU16::andOp() {
//    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
//    alu->setOperation(ALU16::AND);
//    registers[0]->loadValue(alu->GetFullState());
//}
//
//void CPU16::orOp() {
//    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
//    alu->setOperation(ALU16::OR);
//    registers[0]->loadValue(alu->GetFullState());
//}
//
//void CPU16::xorOp() {
//    alu->setInputs(registers[1]->GetFullState(), registers[2]->GetFullState());
//    alu->setOperation(ALU16::XOR);
//    registers[0]->loadValue(alu->GetFullState());
//}
//
//void CPU16::notOp() {
//    alu->setInputs(registers[1]->GetFullState(), 0);
//    alu->setOperation(ALU16::NOT);
//    registers[0]->loadValue(alu->GetFullState());
//}
//
//void CPU16::jmp() {
//    // Example: Jump to address (not implemented)
//    // In a real implementation, decode address from the instruction
//    programCounter->loadValue(operand1); // Use operand1 as the address
//}
//
//void CPU16::jz() {
//    // Example: Jump to address if zero flag is set (not implemented)
//    // In a real implementation, decode address from the instruction
//    if (zeroFlag) {
//        programCounter->loadValue(operand1); // Use operand1 as the address
//    }
//}
//
//void CPU16::jnz() {
//    // Example: Jump to address if zero flag is not set (not implemented)
//    // In a real implementation, decode address from the instruction
//    if (!zeroFlag) {
//        programCounter->loadValue(operand1); // Use operand1 as the address
//    }
//}
//
//void CPU16::call() {
//    // Example: Call subroutine at address (not implemented)
//    // In a real implementation, decode address from the instruction
//    // Save current PC, then jump to address
//    returnAddress = programCounter->GetFullState();
//    programCounter->loadValue(operand1); // Use operand1 as the subroutine address
//}
//
//void CPU16::ret() {
//    // Return from subroutine (not implemented)
//    // Load saved return address into PC
//    programCounter->loadValue(returnAddress);
//}
//
//void CPU16::inOp() {
//    // Input operation (not implemented)
//}
//
//void CPU16::outOp() {
//    // Output operation (not implemented)
//}
//
//void CPU16::hlt() {
//    // Halt the CPU
//    halted = true;
//}
//
//std::vector<std::shared_ptr<Register16>> CPU16::GetRegisters() const {
//    return registers;
//}

//CPU16::CPU16(size_t memorySize) {
//    clock = std::make_shared<Clock16>(1);
//    programCounter = std::make_shared<Register16>();
//    alu = std::make_shared<ALU16>();
//    memory = std::make_shared<Memory16>(memorySize);
//
//    // Initialize registers
//    for (int i = 0; i < 8; ++i) {
//        registers.push_back(std::make_shared<Register16>());
//    }
//
//    // Map opcodes to their handlers
//    opcodeMap = {
//            {0x00, &CPU16::nop},
//            {0x01, &CPU16::movRegisterToRegister},
//            {0x02, &CPU16::movImmediateToRegister},
//            {0x03, &CPU16::load},
//            {0x04, &CPU16::store},
//            {0x10, &CPU16::add},
//            {0x11, &CPU16::sub},
//            {0x12, &CPU16::inc},
//            {0x13, &CPU16::dec},
//            {0x20, &CPU16::andOp},
//            {0x21, &CPU16::orOp},
//            {0x22, &CPU16::xorOp},
//            {0x23, &CPU16::notOp},
//            {0x40, &CPU16::jmp},
//            {0x41, &CPU16::jz},
//            {0x42, &CPU16::jnz},
//            {0x43, &CPU16::call},
//            {0x44, &CPU16::ret},
//            {0x60, &CPU16::inOp},
//            {0x61, &CPU16::outOp},
//            {0xFF, &CPU16::hlt}
//    };
//}
//
//void CPU16::loadInstruction(uint16_t instruction, uint16_t operand1, uint16_t operand2) {
//    this->instruction = instruction;
//    this->operand1 = operand1;
//    this->operand2 = operand2;
//    decodeExecute();
//}
//
//void CPU16::tickClock() {
//    clock->tick();
//}
//
//void CPU16::run() {
//    while (!halted) {
//        fetch();
//        decodeExecute();
//        tickClock();
//    }
//}
//
//void CPU16::loadProgram(const std::vector<uint16_t>& program, uint16_t startAddress) {
//    for (size_t i = 0; i < program.size(); ++i) {
//        memory->store(startAddress + i, program[i]);
//    }
//    programCounter->loadValue(startAddress);
//}
//
//void CPU16::fetch() {
//    uint16_t address = programCounter->GetFullState();
//    uint16_t instructionWord = memory->load(address);
//    instruction = (instructionWord & 0xFF00) >> 8;
//    operand1 = (instructionWord & 0x00F0) >> 4;
//    operand2 = instructionWord & 0x000F;
//    programCounter->loadValue(address + 1);
//}
//
//void CPU16::decodeExecute() {
//    auto it = opcodeMap.find(instruction);
//    if (it != opcodeMap.end()) {
//        (this->*(it->second))();
//    } else {
//        std::cerr << "Unknown instruction: " << std::hex << +instruction << std::endl;
//    }
//}
//
//void CPU16::nop() {
//    // No operation
//}
//
//void CPU16::movRegisterToRegister() {
//    uint16_t src = (operand1 & 0xF0) >> 4;
//    uint16_t dest = operand1 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        registers[dest]->loadValue(registers[src]->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::movImmediateToRegister() {
//    uint16_t dest = operand1 & 0x0F;
//    if (dest < registers.size()) {
//        registers[dest]->loadValue(operand2);
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::load() {
//    uint16_t dest = operand1 & 0x0F; // Use operand1 as the destination register index
//    uint16_t address = operand2; // Use operand2 as the memory address
//    if (dest < registers.size()) {
//        registers[dest]->loadValue(memory->load(address));
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::store() {
//    uint16_t address = operand1; // Use operand1 as the address
//    uint16_t src = operand2 & 0x0F; // Get the source register index
//    if (src < registers.size()) {
//        memory->store(address, registers[src]->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand2 << std::endl;
//    }
//}
//
//void CPU16::add() {
//    uint16_t src = (operand1 & 0xF0) >> 4;
//    uint16_t dest = operand1 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        alu->setInputs(registers[src]->GetFullState(), registers[dest]->GetFullState());
//        alu->setOperation(ALU16::ADD);
//        registers[src]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::sub() {
//    uint16_t dest = (operand1 & 0x0F);
//    uint16_t src = operand2 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
//        alu->setOperation(ALU16::SUB);
//        registers[dest]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::inc() {
//    uint16_t reg = operand1 & 0x0F;
//    if (reg < registers.size()) {
//        registers[reg]->loadValue(registers[reg]->GetFullState() + 1);
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::dec() {
//    uint16_t reg = operand1 & 0x0F;
//    if (reg < registers.size()) {
//        registers[reg]->loadValue(registers[reg]->GetFullState() - 1);
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::andOp() {
//    uint16_t dest = (operand1 & 0x0F);
//    uint16_t src = operand2 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
//        alu->setOperation(ALU16::AND);
//        registers[dest]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::orOp() {
//    uint16_t dest = (operand1 & 0x0F);
//    uint16_t src = operand2 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
//        alu->setOperation(ALU16::OR);
//        registers[dest]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::xorOp() {
//    uint16_t dest = (operand1 & 0x0F);
//    uint16_t src = operand2 & 0x0F;
//    if (dest < registers.size() && src < registers.size()) {
//        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
//        alu->setOperation(ALU16::XOR);
//        registers[dest]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::notOp() {
//    uint16_t dest = operand1 & 0x0F;
//    if (dest < registers.size()) {
//        alu->setInputs(registers[dest]->GetFullState(), 0);
//        alu->setOperation(ALU16::NOT);
//        registers[dest]->loadValue(alu->GetFullState());
//    } else {
//        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
//    }
//}
//
//void CPU16::jmp() {
//    programCounter->loadValue(operand1); // Use operand1 as the address
//}
//
//void CPU16::jz() {
//    if (zeroFlag) {
//        programCounter->loadValue(operand1); // Use operand1 as the address
//    }
//}
//
//void CPU16::jnz() {
//    if (!zeroFlag) {
//        programCounter->loadValue(operand1); // Use operand1 as the address
//    }
//}
//
//void CPU16::call() {
//    returnAddress = programCounter->GetFullState();
//    programCounter->loadValue(operand1); // Use operand1 as the subroutine address
//}
//
//void CPU16::ret() {
//    programCounter->loadValue(returnAddress);
//}
//
//void CPU16::inOp() {
//    // Input operation (not implemented)
//}
//
//void CPU16::outOp() {
//    // Output operation (not implemented)
//}
//
//void CPU16::hlt() {
//    halted = true;
//}
//
//std::vector<std::shared_ptr<Register16>> CPU16::GetRegisters() const {
//    return registers;
//}
//
//bool CPU16::GetZeroFlag() const {
//    return zeroFlag;
//}
//
//void CPU16::SetZeroFlag(bool zFlag) {
//    zeroFlag = zFlag;
//}
//
//std::shared_ptr<Register16> CPU16::GetProgramCounter() const {
//    return programCounter;
//}
//
//std::shared_ptr<Memory16> CPU16::GetMemory() const {
//    return memory;
//}

#include "CPU16/CPU16.hpp"
#include <iostream>
#include <iomanip>

CPU16::CPU16(size_t memorySize) {
    clock = std::make_shared<Clock16>(1);
    programCounter = std::make_shared<Register16>();
    alu = std::make_shared<ALU16>();
    memory = std::make_shared<Memory16>(memorySize);

    // Initialize registers
    for (int i = 0; i < 8; ++i) {
        registers.push_back(std::make_shared<Register16>());
    }

    // Map opcodes to their handlers
    opcodeMap = {
            {0x00, &CPU16::nop},
            {0x01, &CPU16::movRegisterToRegister},
            {0x02, &CPU16::movImmediateToRegister},
            {0x03, &CPU16::load},
            {0x04, &CPU16::store},
            {0x10, &CPU16::add},
            {0x11, &CPU16::sub},
            {0x12, &CPU16::inc},
            {0x13, &CPU16::dec},
            {0x20, &CPU16::andOp},
            {0x21, &CPU16::orOp},
            {0x22, &CPU16::xorOp},
            {0x23, &CPU16::notOp},
            {0x40, &CPU16::jmp},
            {0x41, &CPU16::jz},
            {0x42, &CPU16::jnz},
            {0x43, &CPU16::call},
            {0x44, &CPU16::ret},
            {0x60, &CPU16::inOp},
            {0x61, &CPU16::outOp},
            {0xFF, &CPU16::hlt}
    };
}

void CPU16::loadInstruction(uint16_t instruction, uint16_t operand1, uint16_t operand2) {
    this->instruction = instruction;
    this->operand1 = operand1;
    this->operand2 = operand2;

    uint16_t address = programCounter->GetFullState();
    memory->store(address, instruction);
    memory->store(address + 1, operand1);
    memory->store(address + 2, operand2);
    programCounter->loadValue(address);
    decodeExecute();
}

void CPU16::tickClock() {
    clock->tick();
}

void CPU16::run() {
    while (!halted) {
        fetch();
        decodeExecute();
        tickClock();
    }
}

void CPU16::loadProgram(const std::vector<uint16_t>& program, uint16_t startAddress) {
    for (size_t i = 0; i < program.size(); ++i) {
        memory->store(startAddress + i, program[i]);
    }
    programCounter->loadValue(startAddress);
}

//void CPU16::fetch() {
//    uint16_t address = programCounter->GetFullState();
//    uint16_t instructionWord = memory->load(address);
//    instruction = (instructionWord & 0xF000) >> 12;  // Highest 4 bits
//    operand1 = (instructionWord & 0x0F00) >> 8;      // Next 4 bits
//    operand2 = instructionWord & 0x00FF;             // Lowest 8 bits
//    programCounter->loadValue(address + 1);
//}

void CPU16::fetch() {
    uint16_t address = programCounter->GetFullState();
    instruction = memory->load(address);
    operand1 = memory->load(address + 1);
    operand2 = memory->load(address + 2);
    programCounter->loadValue(address+3);
}

void CPU16::decodeExecute() {
    auto it = opcodeMap.find(instruction);
    if (it != opcodeMap.end()) {
        (this->*(it->second))();
    } else {
        std::cerr << "Unknown instruction: " << std::hex << instruction << std::endl;
    }
}

void CPU16::nop() {
    // No operation
}

void CPU16::movRegisterToRegister() {
    uint16_t src = (operand1 & 0xF0) >> 4;
    uint16_t dest = operand1 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        registers[dest]->loadValue(registers[src]->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
    }
}

void CPU16::movImmediateToRegister() {
    uint16_t dest = operand1 & 0x0F;
    if (dest < registers.size()) {
        registers[dest]->loadValue(operand2);
    } else {
        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
    }
}

void CPU16::load() {
    uint16_t dest = operand1 & 0x0F; // Use operand1 as the destination register index
    uint16_t address = operand2; // Use operand2 as the memory address
    if (dest < registers.size()) {
        registers[dest]->loadValue(memory->load(address));
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::store() {
    uint16_t address = operand1; // Use operand1 as the address
    uint16_t src = operand2 & 0x0F; // Get the source register index
    if (src < registers.size()) {
        memory->store(address, registers[src]->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand2 << std::endl;
    }
}

void CPU16::add() {
    uint16_t src = (operand1 & 0xF0) >> 4;
    uint16_t dest = operand1 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        alu->setInputs(registers[src]->GetFullState(), registers[dest]->GetFullState());
        alu->setOperation(ALU16::ADD);
        registers[src]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << +operand1 << std::endl;
    }
}

void CPU16::sub() {
    uint16_t dest = (operand1 & 0x0F);
    uint16_t src = operand2 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
        alu->setOperation(ALU16::SUB);
        registers[dest]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::inc() {
    uint16_t reg = operand1 & 0x0F;
    if (reg < registers.size()) {
        registers[reg]->loadValue(registers[reg]->GetFullState() + 1);
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::dec() {
    uint16_t reg = operand1 & 0x0F;
    if (reg < registers.size()) {
        registers[reg]->loadValue(registers[reg]->GetFullState() - 1);
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::andOp() {
    uint16_t dest = (operand1 & 0x0F);
    uint16_t src = operand2 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
        alu->setOperation(ALU16::AND);
        registers[dest]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::orOp() {
    uint16_t dest = (operand1 & 0x0F);
    uint16_t src = operand2 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
        alu->setOperation(ALU16::OR);
        registers[dest]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::xorOp() {
    uint16_t dest = (operand1 & 0x0F);
    uint16_t src = operand2 & 0x0F;
    if (dest < registers.size() && src < registers.size()) {
        alu->setInputs(registers[dest]->GetFullState(), registers[src]->GetFullState());
        alu->setOperation(ALU16::XOR);
        registers[dest]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::notOp() {
    uint16_t dest = operand1 & 0x0F;
    if (dest < registers.size()) {
        alu->setInputs(registers[dest]->GetFullState(), 0);
        alu->setOperation(ALU16::NOT);
        registers[dest]->loadValue(alu->GetFullState());
    } else {
        std::cerr << "Invalid register index: " << std::hex << operand1 << std::endl;
    }
}

void CPU16::jmp() {
    programCounter->loadValue(operand1); // Use operand1 as the address
}

void CPU16::jz() {
    if (zeroFlag) {
        programCounter->loadValue(operand1); // Use operand1 as the address
    }
}

void CPU16::jnz() {
    if (!zeroFlag) {
        programCounter->loadValue(operand1); // Use operand1 as the address
    }
}

void CPU16::call() {
    returnAddress = programCounter->GetFullState();
    programCounter->loadValue(operand1); // Use operand1 as the subroutine address
}

void CPU16::ret() {
    programCounter->loadValue(returnAddress);
}

void CPU16::inOp() {
    // Input operation (not implemented)
}

void CPU16::outOp() {
    // Output operation (not implemented)
}

void CPU16::hlt() {
    halted = true;
}

std::vector<std::shared_ptr<Register16>> CPU16::GetRegisters() const {
    return registers;
}

bool CPU16::GetZeroFlag() const {
    return zeroFlag;
}

void CPU16::SetZeroFlag(bool zFlag) {
    zeroFlag = zFlag;
}

std::shared_ptr<Register16> CPU16::GetProgramCounter() const {
    return programCounter;
}

std::shared_ptr<Memory16> CPU16::GetMemory() const {
    return memory;
}
