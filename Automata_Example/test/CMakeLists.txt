# Add the existing test target
add_executable(TestAutomata tests.cpp ${CMAKE_SOURCE_DIR}/source/automaton.cpp)
target_include_directories(TestAutomata PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestAutomata PUBLIC Catch2::Catch2WithMain)

# Add the new comprehensive test target
add_executable(ComprehensiveTests automaton_comprehensive_tests.cpp ${CMAKE_SOURCE_DIR}/source/automaton.cpp)
target_include_directories(ComprehensiveTests PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ComprehensiveTests PUBLIC Catch2::Catch2WithMain)

# Register the test with CTest
include(Catch)
catch_discover_tests(TestAutomata)
catch_discover_tests(ComprehensiveTests)