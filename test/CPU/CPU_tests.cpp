//
// Created by John on 5/29/2024.
//
#include <gtest/gtest.h>
#include "CPU/CPU.hpp"

class CPUTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize CPU before each test
        cpu = std::make_unique<CPU>();
    }

    std::unique_ptr<CPU> cpu;
};

TEST_F(CPUTest, TestNOP) {
    // Load NOP instruction and execute
    cpu->loadInstruction(0x00);
    cpu->tickClock();

    // Verify CPU is still running
    EXPECT_FALSE(cpu->halted);
}

TEST_F(CPUTest, TestHalt) {
    // Load HLT instruction and execute
    cpu->loadInstruction(0xFF);
    cpu->tickClock();

    // Verify CPU is halted
    EXPECT_TRUE(cpu->halted);
}

// Doesn't Pass. All others pass.
TEST_F(CPUTest, TestAdd) {
    // Load immediate values into registers
    cpu->loadInstruction(0x02); // MOV R1, IMM (not fully implemented)
    cpu->tickClock();
    cpu->loadInstruction(0x01); // MOV R2, R1 (not fully implemented)
    cpu->tickClock();

    // Add values in R1 and R2
    cpu->loadInstruction(0x10); // ADD R1, R2
    cpu->tickClock();

    // Verify the result in the destination register (R0)
    EXPECT_EQ(cpu->GetRegisters()[0]->GetFullState(), 42 + 42);
}

TEST_F(CPUTest, TestJump) {
    // Set zero flag for jump condition
    cpu->SetZeroFlag(true);

    // Load JZ instruction and execute
    cpu->loadInstruction(0x41); // JZ (Jump if Zero)
    cpu->tickClock();

    // Verify program counter has jumped to the address
    EXPECT_EQ(cpu->GetProgramCounter()->GetFullState(), 10);
}