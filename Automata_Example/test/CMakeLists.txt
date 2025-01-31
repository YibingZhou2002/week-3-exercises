add_executable(TestAutomata tests.cpp ${CMAKE_SOURCE_DIR}/source/automaton.cpp)
target_include_directories(TestAutomata PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TestAutomata PUBLIC Catch2::Catch2WithMain)