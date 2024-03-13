project(DesignPatterns)

# adding the Google_Tests_run target
add_executable(LogicGates_Tests
        ../source/Switch/Switch.cpp
        ../source/LogicGates/AndGate/AndGate.cpp
        ../source/Display/Display.cpp

        Integration/Integration_tests.cpp
        LogicGates/AndGate/AndGate_tests.cpp

)

target_link_libraries(LogicGates_Tests gtest gtest_main)