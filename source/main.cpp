//
// Created by John on 3/12/2024.
//

//#include <iostream>
//#include <vector>
//#include <sstream>
//#include "CPU16/CPU16.hpp"
//
//void printHelp() {
//    std::cout << "Available commands:\n";
//    std::cout << "  load <opcode> <operand1> <operand2>  - Load an instruction\n";
//    std::cout << "  execute                              - Execute the loaded instructions\n";
//    std::cout << "  print                                - Print the state of the CPU and memory\n";
//    std::cout << "  help                                 - Print this help message\n";
//    std::cout << "  exit                                 - Exit the interpreter\n";
//}
//
//void printCPUState(const CPU16 &cpu) {
//    std::cout << "Registers:\n";
//    for (size_t i = 0; i < cpu.GetRegisters().size(); ++i) {
//        uint16_t value = cpu.GetRegisters()[i]->GetFullState();
//        std::cout << "  R" << i << ": " << value << " (0x" << std::hex << value << std::dec << ")\n";
//    }
//    uint16_t pc = cpu.GetProgramCounter()->GetFullState();
//    std::cout << "Program Counter: " << pc << " (0x" << std::hex << pc << std::dec << ")\n";
//    std::cout << "Zero Flag: " << cpu.GetZeroFlag() << "\n";
//    std::cout << "Halted: " << (cpu.halted ? "Yes" : "No") << "\n";
//}
//
//int main() {
//    std::cout << "Welcome to the CPU16 interpreter!\n";
//
//    size_t memorySize;
//    std::cout << "Enter memory size: ";
//    std::cin >> memorySize;
//
//    CPU16 cpu(memorySize);
//    std::vector<uint16_t> program;
//
//    std::string line;
//    std::cin.ignore(); // Ignore remaining newline from previous input
//    while (true) {
//        std::cout << "> ";
//        std::getline(std::cin, line);
//
//        std::istringstream iss(line);
//        std::string command;
//        iss >> command;
//
//        if (command == "load") {
//            uint16_t opcode, operand1 = 0, operand2 = 0;
//            if (!(iss >> std::hex >> opcode)) {
//                std::cerr << "Invalid opcode\n";
//                continue;
//            }
//            if (!(iss >> std::hex >> operand1)) {
//                operand1 = 0xFFFF; // Use a value that indicates no operand
//            }
//            if (!(iss >> std::hex >> operand2)) {
//                operand2 = 0xFFFF; // Use a value that indicates no operand
//            }
//            cpu.loadInstruction(opcode, operand1, operand2);
//        } else if (command == "execute") {
//            cpu.run();
//        } else if (command == "print") {
//            printCPUState(cpu);
//        } else if (command == "help") {
//            printHelp();
//        } else if (command == "exit") {
//            break;
//        } else {
//            std::cout << "Unknown command: " << command << "\n";
//            printHelp();
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <sstream>
#include "CPU16/CPU16.hpp"

void printHelp() {
    std::cout << "Available commands:\n";
    std::cout << "  load <opcode> <operand1> <operand2>  - Load an instruction\n";
    std::cout << "  execute                              - Execute the loaded instructions\n";
    std::cout << "  print                                - Print the state of the CPU and memory\n";
    std::cout << "  memory <address>                     - Print the contents of the specified memory address\n";
    std::cout << "  help                                 - Print this help message\n";
    std::cout << "  exit                                 - Exit the interpreter\n";
}

void printCPUState(const CPU16 &cpu) {
    std::cout << "Registers:\n";
    for (size_t i = 0; i < cpu.GetRegisters().size(); ++i) {
        uint16_t value = cpu.GetRegisters()[i]->GetFullState();
        std::cout << "  R" << i << ": " << value << " (0x" << std::hex << value << std::dec << ")\n";
    }
    uint16_t pc = cpu.GetProgramCounter()->GetFullState();
    std::cout << "Program Counter: " << pc << " (0x" << std::hex << pc << std::dec << ")\n";
    std::cout << "Zero Flag: " << cpu.GetZeroFlag() << "\n";
    std::cout << "Halted: " << (cpu.halted ? "Yes" : "No") << "\n";
}

void printMemory(const CPU16 &cpu, uint16_t address) {
    uint16_t value = cpu.GetMemory()->load(address);
    std::cout << "Memory[" << address << "]: " << value << " (0x" << std::hex << value << std::dec << ")\n";
}

int main() {
    std::cout << "Welcome to the CPU16 interpreter!\n";

    size_t memorySize;
    std::cout << "Enter memory size: ";
    std::cin >> memorySize;

    CPU16 cpu(memorySize);
    std::vector<uint16_t> program;

    std::string line;
    std::cin.ignore(); // Ignore remaining newline from previous input
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "load") {
            uint16_t opcode, operand1 = 0, operand2 = 0;
            if (!(iss >> std::hex >> opcode)) {
                std::cerr << "Invalid opcode\n";
                continue;
            }
            if (!(iss >> std::hex >> operand1)) {
                operand1 = 0xFFFF; // Use a value that indicates no operand
            }
            if (!(iss >> std::hex >> operand2)) {
                operand2 = 0xFFFF; // Use a value that indicates no operand
            }
            cpu.loadInstruction(opcode, operand1, operand2);
        } else if (command == "execute") {
            cpu.run();
        } else if (command == "print") {
            printCPUState(cpu);
        } else if (command == "memory") {
            uint16_t address;
            if (iss >> std::hex >> address) {
                printMemory(cpu, address);
            } else {
                std::cerr << "Invalid address\n";
            }
        } else if (command == "help") {
            printHelp();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command: " << command << "\n";
            printHelp();
        }
    }

    return 0;
}
