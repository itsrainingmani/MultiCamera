# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/build

# Include any dependencies generated for this target.
include CMakeFiles/SingleThread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SingleThread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SingleThread.dir/flags.make

CMakeFiles/SingleThread.dir/SingleThread.cpp.o: CMakeFiles/SingleThread.dir/flags.make
CMakeFiles/SingleThread.dir/SingleThread.cpp.o: ../SingleThread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SingleThread.dir/SingleThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SingleThread.dir/SingleThread.cpp.o -c /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/SingleThread.cpp

CMakeFiles/SingleThread.dir/SingleThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SingleThread.dir/SingleThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/SingleThread.cpp > CMakeFiles/SingleThread.dir/SingleThread.cpp.i

CMakeFiles/SingleThread.dir/SingleThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SingleThread.dir/SingleThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/SingleThread.cpp -o CMakeFiles/SingleThread.dir/SingleThread.cpp.s

CMakeFiles/SingleThread.dir/SingleThread.cpp.o.requires:
.PHONY : CMakeFiles/SingleThread.dir/SingleThread.cpp.o.requires

CMakeFiles/SingleThread.dir/SingleThread.cpp.o.provides: CMakeFiles/SingleThread.dir/SingleThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/SingleThread.dir/build.make CMakeFiles/SingleThread.dir/SingleThread.cpp.o.provides.build
.PHONY : CMakeFiles/SingleThread.dir/SingleThread.cpp.o.provides

CMakeFiles/SingleThread.dir/SingleThread.cpp.o.provides.build: CMakeFiles/SingleThread.dir/SingleThread.cpp.o

# Object files for target SingleThread
SingleThread_OBJECTS = \
"CMakeFiles/SingleThread.dir/SingleThread.cpp.o"

# External object files for target SingleThread
SingleThread_EXTERNAL_OBJECTS =

SingleThread: CMakeFiles/SingleThread.dir/SingleThread.cpp.o
SingleThread: CMakeFiles/SingleThread.dir/build.make
SingleThread: CMakeFiles/SingleThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SingleThread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SingleThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SingleThread.dir/build: SingleThread
.PHONY : CMakeFiles/SingleThread.dir/build

CMakeFiles/SingleThread.dir/requires: CMakeFiles/SingleThread.dir/SingleThread.cpp.o.requires
.PHONY : CMakeFiles/SingleThread.dir/requires

CMakeFiles/SingleThread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SingleThread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SingleThread.dir/clean

CMakeFiles/SingleThread.dir/depend:
	cd /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/build /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/build /home/money/DroneLab/MultiCamera/SingleThreadedCameraStreamer/build/CMakeFiles/SingleThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SingleThread.dir/depend

