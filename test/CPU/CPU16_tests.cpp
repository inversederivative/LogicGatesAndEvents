//
// Created by John on 5/29/2024.
//
#include <gtest/gtest.h>
#include "CPU16/CPU16.hpp"

class CPU16_Tests : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize CPU before each test
        cpu = std::make_unique<CPU16>(256);
    }

    std::unique_ptr<CPU16> cpu;
};

TEST_F(CPU16_Tests, TestNOP) {
    // Load NOP instruction and execute
    cpu->loadInstruction(0x00);
    cpu->tickClock();

    // Verify CPU is still running
    EXPECT_FALSE(cpu->halted);
}

TEST_F(CPU16_Tests, TestHalt) {
    // Load HLT instruction and execute
    cpu->loadInstruction(0xFF); // HLT instruction
    cpu->tickClock();

    // Verify CPU is halted
    EXPECT_TRUE(cpu->halted);
}

TEST_F(CPU16_Tests, TestMovImmediateToRegister) {
    // Load immediate value into register 1
    cpu->loadInstruction(0x02, 0x01, 42); // MOV R1, 42
    cpu->tickClock();

    // Verify the value in register 1
    EXPECT_EQ(cpu->GetRegisters()[1]->GetFullState(), 42);
}

TEST_F(CPU16_Tests, TestMovRegisterToRegister) {
    // Load immediate value into register 1
    cpu->loadInstruction(0x02, 0x01, 42); // MOV R1, 42
    cpu->tickClock();

    // Move value from register 1 to register 2
    cpu->loadInstruction(0x01, 0x12); // MOV R2, R1
    cpu->tickClock();

    // Verify the value in register 2
    EXPECT_EQ(cpu->GetRegisters()[2]->GetFullState(), 42);
}

TEST_F(CPU16_Tests, TestAddRegisters) {
    // Load immediate values into registers
    cpu->loadInstruction(0x02, 0x01, 42); // MOV R1, 42
    cpu->tickClock();
    cpu->loadInstruction(0x02, 0x02, 58); // MOV R2, 58
    cpu->tickClock();

    // Add values in R1 and R2, store result in R1
    cpu->loadInstruction(0x10, 0x12); // ADD R1, R2, store the result in R1.
    cpu->tickClock();

    // Verify the result in register 1
    EXPECT_EQ(cpu->GetRegisters()[1]->GetFullState(), 42 + 58);
}

TEST_F(CPU16_Tests, TestLoadAndStore) {
    // Load immediate value into register 1
    cpu->loadInstruction(0x02, 0x01, 100); // MOV R1, 100
    cpu->tickClock();

    // Store value from register 1 to memory address 10
    cpu->loadInstruction(0x04, 0x0A, 0x1); // STORE [10], R1
    cpu->tickClock();

    // Verify the value in memory at address 10
    EXPECT_EQ(cpu->GetMemory()->load(10), 100);

    // Load value from memory address 10 to register 2
    cpu->loadInstruction(0x03, 0x02, 0xA); // LOAD R2, [10]
    cpu->tickClock();

    // Verify the value in register 2
    EXPECT_EQ(cpu->GetRegisters()[2]->GetFullState(), 100);
}
