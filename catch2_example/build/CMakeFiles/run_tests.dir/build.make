# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yibingzhou/wk3/week-3-exercises/catch2_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yibingzhou/wk3/week-3-exercises/catch2_example/build

# Include any dependencies generated for this target.
include CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_tests.dir/flags.make

CMakeFiles/run_tests.dir/test_automaton.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/test_automaton.cpp.o: /home/yibingzhou/wk3/week-3-exercises/catch2_example/test_automaton.cpp
CMakeFiles/run_tests.dir/test_automaton.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yibingzhou/wk3/week-3-exercises/catch2_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_tests.dir/test_automaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/test_automaton.cpp.o -MF CMakeFiles/run_tests.dir/test_automaton.cpp.o.d -o CMakeFiles/run_tests.dir/test_automaton.cpp.o -c /home/yibingzhou/wk3/week-3-exercises/catch2_example/test_automaton.cpp

CMakeFiles/run_tests.dir/test_automaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/test_automaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yibingzhou/wk3/week-3-exercises/catch2_example/test_automaton.cpp > CMakeFiles/run_tests.dir/test_automaton.cpp.i

CMakeFiles/run_tests.dir/test_automaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/test_automaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yibingzhou/wk3/week-3-exercises/catch2_example/test_automaton.cpp -o CMakeFiles/run_tests.dir/test_automaton.cpp.s

CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o: /home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp
CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yibingzhou/wk3/week-3-exercises/catch2_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o -MF CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o.d -o CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o -c /home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp

CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp > CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.i

CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp -o CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/test_automaton.cpp.o" \
"CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

run_tests: CMakeFiles/run_tests.dir/test_automaton.cpp.o
run_tests: CMakeFiles/run_tests.dir/home/yibingzhou/wk3/week-3-exercises/Automata_Example/source/automaton.cpp.o
run_tests: CMakeFiles/run_tests.dir/build.make
run_tests: /usr/local/lib/libCatch2Main.a
run_tests: /usr/local/lib/libCatch2.a
run_tests: CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yibingzhou/wk3/week-3-exercises/catch2_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=run_tests -D TEST_EXECUTABLE=/home/yibingzhou/wk3/week-3-exercises/catch2_example/build/run_tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/yibingzhou/wk3/week-3-exercises/catch2_example/build -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=run_tests_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D TEST_DL_PATHS= -D CTEST_FILE=/home/yibingzhou/wk3/week-3-exercises/catch2_example/build/run_tests_tests-b12d07c.cmake -P /usr/local/lib/cmake/Catch2/CatchAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/run_tests.dir/build: run_tests
.PHONY : CMakeFiles/run_tests.dir/build

CMakeFiles/run_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_tests.dir/clean

CMakeFiles/run_tests.dir/depend:
	cd /home/yibingzhou/wk3/week-3-exercises/catch2_example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yibingzhou/wk3/week-3-exercises/catch2_example /home/yibingzhou/wk3/week-3-exercises/catch2_example /home/yibingzhou/wk3/week-3-exercises/catch2_example/build /home/yibingzhou/wk3/week-3-exercises/catch2_example/build /home/yibingzhou/wk3/week-3-exercises/catch2_example/build/CMakeFiles/run_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run_tests.dir/depend

