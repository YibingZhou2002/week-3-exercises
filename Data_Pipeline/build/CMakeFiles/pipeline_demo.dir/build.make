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
CMAKE_SOURCE_DIR = /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build

# Include any dependencies generated for this target.
include CMakeFiles/pipeline_demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pipeline_demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pipeline_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipeline_demo.dir/flags.make

CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o: CMakeFiles/pipeline_demo.dir/flags.make
CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o: /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/pipeline_demo.cpp
CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o: CMakeFiles/pipeline_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o -MF CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o.d -o CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o -c /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/pipeline_demo.cpp

CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/pipeline_demo.cpp > CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.i

CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/pipeline_demo.cpp -o CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.s

CMakeFiles/pipeline_demo.dir/source/simple.cpp.o: CMakeFiles/pipeline_demo.dir/flags.make
CMakeFiles/pipeline_demo.dir/source/simple.cpp.o: /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/simple.cpp
CMakeFiles/pipeline_demo.dir/source/simple.cpp.o: CMakeFiles/pipeline_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pipeline_demo.dir/source/simple.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pipeline_demo.dir/source/simple.cpp.o -MF CMakeFiles/pipeline_demo.dir/source/simple.cpp.o.d -o CMakeFiles/pipeline_demo.dir/source/simple.cpp.o -c /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/simple.cpp

CMakeFiles/pipeline_demo.dir/source/simple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pipeline_demo.dir/source/simple.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/simple.cpp > CMakeFiles/pipeline_demo.dir/source/simple.cpp.i

CMakeFiles/pipeline_demo.dir/source/simple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pipeline_demo.dir/source/simple.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/source/simple.cpp -o CMakeFiles/pipeline_demo.dir/source/simple.cpp.s

# Object files for target pipeline_demo
pipeline_demo_OBJECTS = \
"CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o" \
"CMakeFiles/pipeline_demo.dir/source/simple.cpp.o"

# External object files for target pipeline_demo
pipeline_demo_EXTERNAL_OBJECTS =

pipeline_demo: CMakeFiles/pipeline_demo.dir/source/pipeline_demo.cpp.o
pipeline_demo: CMakeFiles/pipeline_demo.dir/source/simple.cpp.o
pipeline_demo: CMakeFiles/pipeline_demo.dir/build.make
pipeline_demo: CMakeFiles/pipeline_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pipeline_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipeline_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipeline_demo.dir/build: pipeline_demo
.PHONY : CMakeFiles/pipeline_demo.dir/build

CMakeFiles/pipeline_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipeline_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipeline_demo.dir/clean

CMakeFiles/pipeline_demo.dir/depend:
	cd /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build /home/yibingzhou/wk3/week-3-exercises/Data_Pipeline/build/CMakeFiles/pipeline_demo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pipeline_demo.dir/depend

