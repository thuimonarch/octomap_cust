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
include src/math/CMakeFiles/octomath.dir/depend.make

# Include the progress variables for this target.
include src/math/CMakeFiles/octomath.dir/progress.make

# Include the compile flags for this target's objects.
include src/math/CMakeFiles/octomath.dir/flags.make

src/math/CMakeFiles/octomath.dir/Vector3.cpp.o: src/math/CMakeFiles/octomath.dir/flags.make
src/math/CMakeFiles/octomath.dir/Vector3.cpp.o: ../src/math/Vector3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thui/Documents/git_repos/octomap/octomap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/math/CMakeFiles/octomath.dir/Vector3.cpp.o"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/octomath.dir/Vector3.cpp.o -c /home/thui/Documents/git_repos/octomap/octomap/src/math/Vector3.cpp

src/math/CMakeFiles/octomath.dir/Vector3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/octomath.dir/Vector3.cpp.i"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thui/Documents/git_repos/octomap/octomap/src/math/Vector3.cpp > CMakeFiles/octomath.dir/Vector3.cpp.i

src/math/CMakeFiles/octomath.dir/Vector3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/octomath.dir/Vector3.cpp.s"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thui/Documents/git_repos/octomap/octomap/src/math/Vector3.cpp -o CMakeFiles/octomath.dir/Vector3.cpp.s

src/math/CMakeFiles/octomath.dir/Quaternion.cpp.o: src/math/CMakeFiles/octomath.dir/flags.make
src/math/CMakeFiles/octomath.dir/Quaternion.cpp.o: ../src/math/Quaternion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thui/Documents/git_repos/octomap/octomap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/math/CMakeFiles/octomath.dir/Quaternion.cpp.o"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/octomath.dir/Quaternion.cpp.o -c /home/thui/Documents/git_repos/octomap/octomap/src/math/Quaternion.cpp

src/math/CMakeFiles/octomath.dir/Quaternion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/octomath.dir/Quaternion.cpp.i"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thui/Documents/git_repos/octomap/octomap/src/math/Quaternion.cpp > CMakeFiles/octomath.dir/Quaternion.cpp.i

src/math/CMakeFiles/octomath.dir/Quaternion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/octomath.dir/Quaternion.cpp.s"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thui/Documents/git_repos/octomap/octomap/src/math/Quaternion.cpp -o CMakeFiles/octomath.dir/Quaternion.cpp.s

src/math/CMakeFiles/octomath.dir/Pose6D.cpp.o: src/math/CMakeFiles/octomath.dir/flags.make
src/math/CMakeFiles/octomath.dir/Pose6D.cpp.o: ../src/math/Pose6D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thui/Documents/git_repos/octomap/octomap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/math/CMakeFiles/octomath.dir/Pose6D.cpp.o"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/octomath.dir/Pose6D.cpp.o -c /home/thui/Documents/git_repos/octomap/octomap/src/math/Pose6D.cpp

src/math/CMakeFiles/octomath.dir/Pose6D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/octomath.dir/Pose6D.cpp.i"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thui/Documents/git_repos/octomap/octomap/src/math/Pose6D.cpp > CMakeFiles/octomath.dir/Pose6D.cpp.i

src/math/CMakeFiles/octomath.dir/Pose6D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/octomath.dir/Pose6D.cpp.s"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thui/Documents/git_repos/octomap/octomap/src/math/Pose6D.cpp -o CMakeFiles/octomath.dir/Pose6D.cpp.s

# Object files for target octomath
octomath_OBJECTS = \
"CMakeFiles/octomath.dir/Vector3.cpp.o" \
"CMakeFiles/octomath.dir/Quaternion.cpp.o" \
"CMakeFiles/octomath.dir/Pose6D.cpp.o"

# External object files for target octomath
octomath_EXTERNAL_OBJECTS =

../lib/liboctomath.so.1.9.8: src/math/CMakeFiles/octomath.dir/Vector3.cpp.o
../lib/liboctomath.so.1.9.8: src/math/CMakeFiles/octomath.dir/Quaternion.cpp.o
../lib/liboctomath.so.1.9.8: src/math/CMakeFiles/octomath.dir/Pose6D.cpp.o
../lib/liboctomath.so.1.9.8: src/math/CMakeFiles/octomath.dir/build.make
../lib/liboctomath.so.1.9.8: src/math/CMakeFiles/octomath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thui/Documents/git_repos/octomap/octomap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../../../lib/liboctomath.so"
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/octomath.dir/link.txt --verbose=$(VERBOSE)
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../lib/liboctomath.so.1.9.8 ../../../lib/liboctomath.so.1.9 ../../../lib/liboctomath.so

../lib/liboctomath.so.1.9: ../lib/liboctomath.so.1.9.8
	@$(CMAKE_COMMAND) -E touch_nocreate ../lib/liboctomath.so.1.9

../lib/liboctomath.so: ../lib/liboctomath.so.1.9.8
	@$(CMAKE_COMMAND) -E touch_nocreate ../lib/liboctomath.so

# Rule to build all files generated by this target.
src/math/CMakeFiles/octomath.dir/build: ../lib/liboctomath.so

.PHONY : src/math/CMakeFiles/octomath.dir/build

src/math/CMakeFiles/octomath.dir/clean:
	cd /home/thui/Documents/git_repos/octomap/octomap/build/src/math && $(CMAKE_COMMAND) -P CMakeFiles/octomath.dir/cmake_clean.cmake
.PHONY : src/math/CMakeFiles/octomath.dir/clean

src/math/CMakeFiles/octomath.dir/depend:
	cd /home/thui/Documents/git_repos/octomap/octomap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thui/Documents/git_repos/octomap/octomap /home/thui/Documents/git_repos/octomap/octomap/src/math /home/thui/Documents/git_repos/octomap/octomap/build /home/thui/Documents/git_repos/octomap/octomap/build/src/math /home/thui/Documents/git_repos/octomap/octomap/build/src/math/CMakeFiles/octomath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/math/CMakeFiles/octomath.dir/depend

