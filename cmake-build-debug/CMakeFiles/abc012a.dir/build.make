# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/moosan63/CLionProjects/atcoder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/moosan63/CLionProjects/atcoder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/abc012a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/abc012a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abc012a.dir/flags.make

CMakeFiles/abc012a.dir/src/abc012c.cpp.o: CMakeFiles/abc012a.dir/flags.make
CMakeFiles/abc012a.dir/src/abc012c.cpp.o: ../src/abc012c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moosan63/CLionProjects/atcoder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/abc012a.dir/src/abc012c.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abc012a.dir/src/abc012c.cpp.o -c /Users/moosan63/CLionProjects/atcoder/src/abc012c.cpp

CMakeFiles/abc012a.dir/src/abc012c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abc012a.dir/src/abc012c.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/moosan63/CLionProjects/atcoder/src/abc012c.cpp > CMakeFiles/abc012a.dir/src/abc012c.cpp.i

CMakeFiles/abc012a.dir/src/abc012c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abc012a.dir/src/abc012c.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/moosan63/CLionProjects/atcoder/src/abc012c.cpp -o CMakeFiles/abc012a.dir/src/abc012c.cpp.s

# Object files for target abc012a
abc012a_OBJECTS = \
"CMakeFiles/abc012a.dir/src/abc012c.cpp.o"

# External object files for target abc012a
abc012a_EXTERNAL_OBJECTS =

out/abc012a: CMakeFiles/abc012a.dir/src/abc012c.cpp.o
out/abc012a: CMakeFiles/abc012a.dir/build.make
out/abc012a: CMakeFiles/abc012a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/moosan63/CLionProjects/atcoder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable out/abc012a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abc012a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abc012a.dir/build: out/abc012a

.PHONY : CMakeFiles/abc012a.dir/build

CMakeFiles/abc012a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/abc012a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/abc012a.dir/clean

CMakeFiles/abc012a.dir/depend:
	cd /Users/moosan63/CLionProjects/atcoder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/moosan63/CLionProjects/atcoder /Users/moosan63/CLionProjects/atcoder /Users/moosan63/CLionProjects/atcoder/cmake-build-debug /Users/moosan63/CLionProjects/atcoder/cmake-build-debug /Users/moosan63/CLionProjects/atcoder/cmake-build-debug/CMakeFiles/abc012a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/abc012a.dir/depend

