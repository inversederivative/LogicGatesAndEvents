project(DesignPatterns)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# adding the Google_Tests_run target
add_executable(LogicGates_Tests
        ../source/Switch/Switch.cpp
        ../source/LogicGates/AndGate/AndGate.cpp
        ../source/LogicGates/OrGate/OrGate.cpp
        ../source/Display/Display.cpp

        ${SOURCE_FILES}

)

target_link_libraries(LogicGates_Tests gtest gtest_main)