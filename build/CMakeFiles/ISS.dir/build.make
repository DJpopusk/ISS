# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /Users/phonkyponky/CLionProjects/ISS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phonkyponky/CLionProjects/ISS/build

# Include any dependencies generated for this target.
include CMakeFiles/ISS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ISS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ISS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ISS.dir/flags.make

CMakeFiles/ISS.dir/codegen:
.PHONY : CMakeFiles/ISS.dir/codegen

CMakeFiles/ISS.dir/src/main.cpp.o: CMakeFiles/ISS.dir/flags.make
CMakeFiles/ISS.dir/src/main.cpp.o: /Users/phonkyponky/CLionProjects/ISS/src/main.cpp
CMakeFiles/ISS.dir/src/main.cpp.o: CMakeFiles/ISS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ISS.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ISS.dir/src/main.cpp.o -MF CMakeFiles/ISS.dir/src/main.cpp.o.d -o CMakeFiles/ISS.dir/src/main.cpp.o -c /Users/phonkyponky/CLionProjects/ISS/src/main.cpp

CMakeFiles/ISS.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ISS.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phonkyponky/CLionProjects/ISS/src/main.cpp > CMakeFiles/ISS.dir/src/main.cpp.i

CMakeFiles/ISS.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ISS.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phonkyponky/CLionProjects/ISS/src/main.cpp -o CMakeFiles/ISS.dir/src/main.cpp.s

CMakeFiles/ISS.dir/src/propulsion.cpp.o: CMakeFiles/ISS.dir/flags.make
CMakeFiles/ISS.dir/src/propulsion.cpp.o: /Users/phonkyponky/CLionProjects/ISS/src/propulsion.cpp
CMakeFiles/ISS.dir/src/propulsion.cpp.o: CMakeFiles/ISS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ISS.dir/src/propulsion.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ISS.dir/src/propulsion.cpp.o -MF CMakeFiles/ISS.dir/src/propulsion.cpp.o.d -o CMakeFiles/ISS.dir/src/propulsion.cpp.o -c /Users/phonkyponky/CLionProjects/ISS/src/propulsion.cpp

CMakeFiles/ISS.dir/src/propulsion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ISS.dir/src/propulsion.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phonkyponky/CLionProjects/ISS/src/propulsion.cpp > CMakeFiles/ISS.dir/src/propulsion.cpp.i

CMakeFiles/ISS.dir/src/propulsion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ISS.dir/src/propulsion.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phonkyponky/CLionProjects/ISS/src/propulsion.cpp -o CMakeFiles/ISS.dir/src/propulsion.cpp.s

# Object files for target ISS
ISS_OBJECTS = \
"CMakeFiles/ISS.dir/src/main.cpp.o" \
"CMakeFiles/ISS.dir/src/propulsion.cpp.o"

# External object files for target ISS
ISS_EXTERNAL_OBJECTS =

ISS: CMakeFiles/ISS.dir/src/main.cpp.o
ISS: CMakeFiles/ISS.dir/src/propulsion.cpp.o
ISS: CMakeFiles/ISS.dir/build.make
ISS: CMakeFiles/ISS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ISS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ISS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ISS.dir/build: ISS
.PHONY : CMakeFiles/ISS.dir/build

CMakeFiles/ISS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ISS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ISS.dir/clean

CMakeFiles/ISS.dir/depend:
	cd /Users/phonkyponky/CLionProjects/ISS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phonkyponky/CLionProjects/ISS /Users/phonkyponky/CLionProjects/ISS /Users/phonkyponky/CLionProjects/ISS/build /Users/phonkyponky/CLionProjects/ISS/build /Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles/ISS.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ISS.dir/depend
