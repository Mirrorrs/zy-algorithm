# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/ma/Jetbrains/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ma/Jetbrains/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ma/ws/zy-algorithm/proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ma/ws/zy-algorithm/proj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj.dir/flags.make

CMakeFiles/proj.dir/proj.cpp.o: CMakeFiles/proj.dir/flags.make
CMakeFiles/proj.dir/proj.cpp.o: ../proj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ma/ws/zy-algorithm/proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj.dir/proj.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj.dir/proj.cpp.o -c /home/ma/ws/zy-algorithm/proj/proj.cpp

CMakeFiles/proj.dir/proj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj.dir/proj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ma/ws/zy-algorithm/proj/proj.cpp > CMakeFiles/proj.dir/proj.cpp.i

CMakeFiles/proj.dir/proj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj.dir/proj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ma/ws/zy-algorithm/proj/proj.cpp -o CMakeFiles/proj.dir/proj.cpp.s

CMakeFiles/proj.dir/proj.cpp.o.requires:

.PHONY : CMakeFiles/proj.dir/proj.cpp.o.requires

CMakeFiles/proj.dir/proj.cpp.o.provides: CMakeFiles/proj.dir/proj.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj.dir/build.make CMakeFiles/proj.dir/proj.cpp.o.provides.build
.PHONY : CMakeFiles/proj.dir/proj.cpp.o.provides

CMakeFiles/proj.dir/proj.cpp.o.provides.build: CMakeFiles/proj.dir/proj.cpp.o


# Object files for target proj
proj_OBJECTS = \
"CMakeFiles/proj.dir/proj.cpp.o"

# External object files for target proj
proj_EXTERNAL_OBJECTS =

proj: CMakeFiles/proj.dir/proj.cpp.o
proj: CMakeFiles/proj.dir/build.make
proj: CMakeFiles/proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ma/ws/zy-algorithm/proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj.dir/build: proj

.PHONY : CMakeFiles/proj.dir/build

CMakeFiles/proj.dir/requires: CMakeFiles/proj.dir/proj.cpp.o.requires

.PHONY : CMakeFiles/proj.dir/requires

CMakeFiles/proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj.dir/clean

CMakeFiles/proj.dir/depend:
	cd /home/ma/ws/zy-algorithm/proj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ma/ws/zy-algorithm/proj /home/ma/ws/zy-algorithm/proj /home/ma/ws/zy-algorithm/proj/cmake-build-debug /home/ma/ws/zy-algorithm/proj/cmake-build-debug /home/ma/ws/zy-algorithm/proj/cmake-build-debug/CMakeFiles/proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj.dir/depend
