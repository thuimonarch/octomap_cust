# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thui/Documents/git_repos/octomap/octomap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thui/Documents/git_repos/octomap/octomap/build

# Include any dependencies generated for this target.
include src/CMakeFiles/normals_example.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/normals_example.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/normals_example.dir/flags.make

src/CMakeFiles/normals_example.dir/normals_example.cpp.o: src/CMakeFiles/normals_example.dir/flags.make
src/CMakeFiles/normals_example.dir/normals_example.cpp.o: ../src/normals_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thui/Documents/git_repos/octomap/octomap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/normals_example.dir/normals_example.cpp.o"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/normals_example.dir/normals_example.cpp.o -c /home/thui/Documents/git_repos/octomap/octomap/src/normals_example.cpp

src/CMakeFiles/normals_example.dir/normals_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/normals_example.dir/normals_example.cpp.i"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thui/Documents/git_repos/octomap/octomap/src/normals_example.cpp > CMakeFiles/normals_example.dir/normals_example.cpp.i

src/CMakeFiles/normals_example.dir/normals_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/normals_example.dir/normals_example.cpp.s"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thui/Documents/git_repos/octomap/octomap/src/normals_example.cpp -o CMakeFiles/normals_example.dir/normals_example.cpp.s

# Object files for target normals_example
normals_example_OBJECTS = \
"CMakeFiles/normals_example.dir/normals_example.cpp.o"

# External object files for target normals_example
normals_example_EXTERNAL_OBJECTS =

../bin/normals_example: src/CMakeFiles/normals_example.dir/normals_example.cpp.o
../bin/normals_example: src/CMakeFiles/normals_example.dir/build.make
../bin/normals_example: ../lib/liboctomap.so.1.9.8
../bin/normals_example: ../lib/liboctomath.so.1.9.8
../bin/normals_example: src/CMakeFiles/normals_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thui/Documents/git_repos/octomap/octomap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/normals_example"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/normals_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/normals_example.dir/build: ../bin/normals_example

.PHONY : src/CMakeFiles/normals_example.dir/build

src/CMakeFiles/normals_example.dir/clean:
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src && $(CMAKE_COMMAND) -P CMakeFiles/normals_example.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/normals_example.dir/clean

src/CMakeFiles/normals_example.dir/depend:
	cd /home/thui/Documents/git_repos/octomap/octomap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thui/Documents/git_repos/octomap/octomap /home/thui/Documents/git_repos/octomap/octomap/src /home/thui/Documents/git_repos/octomap/octomap/build /home/thui/Documents/git_repos/octomap/octomap/build/src /home/thui/Documents/git_repos/octomap/octomap/build/src/CMakeFiles/normals_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/normals_example.dir/depend

