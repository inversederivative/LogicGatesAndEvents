# Recursively find all .cpp files in the source directory
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
        LogicGates/AbstractTwoInputOneOutputNode.cpp
        Adders/FourBitAdder/FourBitAdder.cpp

)