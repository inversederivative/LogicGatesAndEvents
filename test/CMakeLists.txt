project(DesignPatterns)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# adding the Google_Tests_run target
add_executable(LogicGates_Tests
        ../source/LogicGates/AbstractTwoInputOneOutputNode.cpp
        ../source/Switch/Switch.cpp
        ../source/LogicGates/AndGate/AndGate.cpp
        ../source/LogicGates/OrGate/OrGate.cpp
        ../source/LogicGates/XorGate/XorGate.cpp
        ../source/LogicGates/TriStateBufferGate/TriStateBufferGate.cpp
        ../source/LogicGates/NotGate/NotGate.cpp
        ../source/LogicGates/NorGate/NorGate.cpp
        ../source/Adders/HalfAdder/HalfAdder.cpp
        ../source/Adders/FullAdder/FullAdder.cpp
        ../source/Adders/FourBitAdder/FourBitAdder.cpp
        ../source/LogicGates/BufferGate/BufferGate.cpp
        ../source/Display/Display.cpp
        ../source/Memory/D_FlipFlop.cpp
        ../source/Memory/FourBitFourWordRAM.cpp
        ../source/Memory/EightBit256WordRAM.cpp

        ${SOURCE_FILES}
        Integration/MultipleOutputsFromSameNode_Test.cpp
        Adders/FourBitAdder/FourBitAdder_tests.cpp

)

target_link_libraries(LogicGates_Tests gtest gtest_main)