cmake_minimum_required(VERSION 3.14)
project(AutomataTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Catch2
find_package(Catch2 3 REQUIRED)

# Include directories
include_directories(../Automata_Example/include)

# Source files
set(AUTOMATON_SRC ../Automata_Example/source/automaton.cpp)
set(TEST_SRC test_automaton.cpp)

# Create test executable
add_executable(run_tests ${TEST_SRC} ${AUTOMATON_SRC})

# Link with Catch2
target_link_libraries(run_tests PRIVATE Catch2::Catch2WithMain)

# Enable CTest integration
include(CTest)
include(Catch)
catch_discover_tests(run_tests)
