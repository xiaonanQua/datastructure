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
CMAKE_COMMAND = /home/xiaonan/软件/clion/clion-2018.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/xiaonan/软件/clion/clion-2018.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xiaonan/C_workplace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xiaonan/C_workplace/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C_workplace.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C_workplace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C_workplace.dir/flags.make

CMakeFiles/C_workplace.dir/StackList.c.o: CMakeFiles/C_workplace.dir/flags.make
CMakeFiles/C_workplace.dir/StackList.c.o: ../StackList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaonan/C_workplace/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C_workplace.dir/StackList.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C_workplace.dir/StackList.c.o   -c /home/xiaonan/C_workplace/StackList.c

CMakeFiles/C_workplace.dir/StackList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C_workplace.dir/StackList.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xiaonan/C_workplace/StackList.c > CMakeFiles/C_workplace.dir/StackList.c.i

CMakeFiles/C_workplace.dir/StackList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C_workplace.dir/StackList.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xiaonan/C_workplace/StackList.c -o CMakeFiles/C_workplace.dir/StackList.c.s

CMakeFiles/C_workplace.dir/StackList.c.o.requires:

.PHONY : CMakeFiles/C_workplace.dir/StackList.c.o.requires

CMakeFiles/C_workplace.dir/StackList.c.o.provides: CMakeFiles/C_workplace.dir/StackList.c.o.requires
	$(MAKE) -f CMakeFiles/C_workplace.dir/build.make CMakeFiles/C_workplace.dir/StackList.c.o.provides.build
.PHONY : CMakeFiles/C_workplace.dir/StackList.c.o.provides

CMakeFiles/C_workplace.dir/StackList.c.o.provides.build: CMakeFiles/C_workplace.dir/StackList.c.o


# Object files for target C_workplace
C_workplace_OBJECTS = \
"CMakeFiles/C_workplace.dir/StackList.c.o"

# External object files for target C_workplace
C_workplace_EXTERNAL_OBJECTS =

C_workplace: CMakeFiles/C_workplace.dir/StackList.c.o
C_workplace: CMakeFiles/C_workplace.dir/build.make
C_workplace: CMakeFiles/C_workplace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xiaonan/C_workplace/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable C_workplace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C_workplace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C_workplace.dir/build: C_workplace

.PHONY : CMakeFiles/C_workplace.dir/build

CMakeFiles/C_workplace.dir/requires: CMakeFiles/C_workplace.dir/StackList.c.o.requires

.PHONY : CMakeFiles/C_workplace.dir/requires

CMakeFiles/C_workplace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C_workplace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C_workplace.dir/clean

CMakeFiles/C_workplace.dir/depend:
	cd /home/xiaonan/C_workplace/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaonan/C_workplace /home/xiaonan/C_workplace /home/xiaonan/C_workplace/cmake-build-debug /home/xiaonan/C_workplace/cmake-build-debug /home/xiaonan/C_workplace/cmake-build-debug/CMakeFiles/C_workplace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C_workplace.dir/depend
