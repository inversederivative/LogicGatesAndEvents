CPU16 Instruction Set and Usage Guide
Introduction

The CPU16 interpreter allows you to simulate a 16-bit CPU with various instructions. This guide provides an overview of the available instructions and demonstrates how to use them in the interpreter.
Instructions
NOP (No Operation)

    Opcode: 0x00
    Description: Performs no operation.
    Usage: load 0
    Example:

    load 0

MOV (Move)
Register to Register

    Opcode: 0x01
    Description: Moves the value from one register to another.
    Usage: load 1 <src_reg> <dest_reg>
    Example:

    load 1 2 1  # MOV R2 to R1

Immediate to Register

    Opcode: 0x02
    Description: Moves an immediate value to a register.
    Usage: load 2 <reg> <value>
    Example:

    load 2 1 2A  # MOV 42 (0x2A) to R1

LOAD (Load from Memory)

    Opcode: 0x03
    Description: Loads a value from memory to a register.
    Usage: load 3 <reg> <address>
    Example:

    load 3 2 A  # LOAD value from memory address 10 (0xA) to R2

STORE (Store to Memory)

    Opcode: 0x04
    Description: Stores a value from a register to memory.
    Usage: load 4 <address> <reg>
    Example:

    load 4 A 1  # STORE value of R1 to memory address 10 (0xA)

ADD (Add Registers)

    Opcode: 0x10
    Description: Adds the values of two registers and stores the result in the first register.
    Usage: load 10 <reg1> <reg2>
    Example:

    load 10 1 2  # ADD R1 and R2, store result in R1

SUB (Subtract Registers)

    Opcode: 0x11
    Description: Subtracts the value of the second register from the first register and stores the result in the first register.
    Usage: load 11 <reg1> <reg2>
    Example:

    load 11 1 2  # SUB R2 from R1, store result in R1

INC (Increment Register)

    Opcode: 0x12
    Description: Increments the value of a register by 1.
    Usage: load 12 <reg>
    Example:

    load 12 1  # INC R1

DEC (Decrement Register)

    Opcode: 0x13
    Description: Decrements the value of a register by 1.
    Usage: load 13 <reg>
    Example:

    load 13 1  # DEC R1

AND (Logical AND)

    Opcode: 0x20
    Description: Performs a bitwise AND on the values of two registers and stores the result in the first register.
    Usage: load 20 <reg1> <reg2>
    Example:

    load 20 1 2  # AND R1 and R2, store result in R1

OR (Logical OR)

    Opcode: 0x21
    Description: Performs a bitwise OR on the values of two registers and stores the result in the first register.
    Usage: load 21 <reg1> <reg2>
    Example:

    load 21 1 2  # OR R1 and R2, store result in R1

XOR (Logical XOR)

    Opcode: 0x22
    Description: Performs a bitwise XOR on the values of two registers and stores the result in the first register.
    Usage: load 22 <reg1> <reg2>
    Example:

    load 22 1 2  # XOR R1 and R2, store result in R1

NOT (Logical NOT)

    Opcode: 0x23
    Description: Performs a bitwise NOT on the value of a register.
    Usage: load 23 <reg>
    Example:

    load 23 1  # NOT R1

JMP (Jump to Address)

    Opcode: 0x40
    Description: Jumps to a specific address in memory.
    Usage: load 40 <address>
    Example:

    load 40 A  # JMP to address 10 (0xA)

JZ (Jump if Zero)

    Opcode: 0x41
    Description: Jumps to a specific address if the zero flag is set.
    Usage: load 41 <address>
    Example:

    load 41 A  # JZ to address 10 (0xA)

JNZ (Jump if Not Zero)

    Opcode: 0x42
    Description: Jumps to a specific address if the zero flag is not set.
    Usage: load 42 <address>
    Example:

    load 42 A  # JNZ to address 10 (0xA)

CALL (Call Subroutine)

    Opcode: 0x43
    Description: Calls a subroutine at a specific address.
    Usage: load 43 <address>
    Example:

    load 43 A  # CALL subroutine at address 10 (0xA)

RET (Return from Subroutine)

    Opcode: 0x44
    Description: Returns from a subroutine.
    Usage: load 44
    Example:

    load 44  # RET

IN (Input Operation)

    Opcode: 0x60
    Description: Performs an input operation (not implemented).
    Usage: load 60
    Example:

    load 60  # IN

OUT (Output Operation)

    Opcode: 0x61
    Description: Performs an output operation (not implemented).
    Usage: load 61
    Example:

    load 61  # OUT

HLT (Halt)

    Opcode: 0xFF
    Description: Halts the CPU.
    Usage: load FF
    Example:

    load FF  # HLT

Usage Example

Here's an example of a complete session with the interpreter:

Welcome to the CPU16 interpreter!
Enter memory size: 256
> load 2 1 2A
> load 2 2 1E
> load 10 1 2
> load 4 A 1
> execute
> print
Registers:
  R0: 0
  R1: 68
  R2: 30
  R3: 0
  R4: 0
  R5: 0
  R6: 0
  R7: 0
Program Counter: 4
Zero Flag: 0
Halted: Yes

In this example:

    The user sets the memory size to 256.
    load 2 1 2A moves the value 0x2A (42) into register R1.
    load 2 2 1E moves the value 0x1E (30) into register R2.
    load 10 1 2 adds the values of R1 and R2 and stores the result in R1.
    load 4 A 1 stores the value of R1 (which is now 68) into memory address 10 (0xA).
    execute runs the program.
    print displays the state of the CPU and registers.

Use this guide to interact with the CPU16 interpreter and execute various instructions.