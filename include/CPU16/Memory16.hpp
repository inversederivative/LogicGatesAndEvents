//
// Created by John on 6/2/2024.
//
#include <cstdint>
#include <vector>

#ifndef LOGICGATESANDEVENTS_MEMORY16_HPP
#define LOGICGATESANDEVENTS_MEMORY16_HPP

class Memory16 {
public:
    Memory16(size_t size) : memory(size, 0) {}

    uint16_t load(uint16_t address) const {
        if (address < memory.size()) {
            return memory[address];
        } else {
            throw std::out_of_range("Memory access out of bounds");
        }
    }

    void store(uint16_t address, uint16_t value) {
        if (address < memory.size()) {
            memory[address] = value;
        } else {
            throw std::out_of_range("Memory access out of bounds");
        }
    }

private:
    std::vector<uint16_t> memory;
};

#endif //LOGICGATESANDEVENTS_MEMORY16_HPP
