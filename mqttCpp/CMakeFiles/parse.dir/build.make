# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/projects/Rasppi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/projects/Rasppi

# Include any dependencies generated for this target.
include CMakeFiles/parse.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parse.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parse.dir/flags.make

CMakeFiles/parse.dir/main.cpp.o: CMakeFiles/parse.dir/flags.make
CMakeFiles/parse.dir/main.cpp.o: main.cpp
CMakeFiles/parse.dir/main.cpp.o: CMakeFiles/parse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/projects/Rasppi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parse.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parse.dir/main.cpp.o -MF CMakeFiles/parse.dir/main.cpp.o.d -o CMakeFiles/parse.dir/main.cpp.o -c /home/pi/projects/Rasppi/main.cpp

CMakeFiles/parse.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parse.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/projects/Rasppi/main.cpp > CMakeFiles/parse.dir/main.cpp.i

CMakeFiles/parse.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parse.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/projects/Rasppi/main.cpp -o CMakeFiles/parse.dir/main.cpp.s

# Object files for target parse
parse_OBJECTS = \
"CMakeFiles/parse.dir/main.cpp.o"

# External object files for target parse
parse_EXTERNAL_OBJECTS =

parse: CMakeFiles/parse.dir/main.cpp.o
parse: CMakeFiles/parse.dir/build.make
parse: /usr/lib/arm-linux-gnueabihf/libmosquitto.so
parse: /usr/lib/arm-linux-gnueabihf/libmosquitto.so.1
parse: CMakeFiles/parse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/projects/Rasppi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable parse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parse.dir/build: parse
.PHONY : CMakeFiles/parse.dir/build

CMakeFiles/parse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parse.dir/clean

CMakeFiles/parse.dir/depend:
	cd /home/pi/projects/Rasppi && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/projects/Rasppi /home/pi/projects/Rasppi /home/pi/projects/Rasppi /home/pi/projects/Rasppi /home/pi/projects/Rasppi/CMakeFiles/parse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parse.dir/depend

