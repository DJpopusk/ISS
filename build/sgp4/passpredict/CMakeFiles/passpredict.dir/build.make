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
include sgp4/passpredict/CMakeFiles/passpredict.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sgp4/passpredict/CMakeFiles/passpredict.dir/compiler_depend.make

# Include the progress variables for this target.
include sgp4/passpredict/CMakeFiles/passpredict.dir/progress.make

# Include the compile flags for this target's objects.
include sgp4/passpredict/CMakeFiles/passpredict.dir/flags.make

sgp4/passpredict/CMakeFiles/passpredict.dir/codegen:
.PHONY : sgp4/passpredict/CMakeFiles/passpredict.dir/codegen

sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.o: sgp4/passpredict/CMakeFiles/passpredict.dir/flags.make
sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.o: /Users/phonkyponky/CLionProjects/ISS/sgp4/passpredict/passpredict.cc
sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.o: sgp4/passpredict/CMakeFiles/passpredict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.o"
	cd /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.o -MF CMakeFiles/passpredict.dir/passpredict.cc.o.d -o CMakeFiles/passpredict.dir/passpredict.cc.o -c /Users/phonkyponky/CLionProjects/ISS/sgp4/passpredict/passpredict.cc

sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/passpredict.dir/passpredict.cc.i"
	cd /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phonkyponky/CLionProjects/ISS/sgp4/passpredict/passpredict.cc > CMakeFiles/passpredict.dir/passpredict.cc.i

sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/passpredict.dir/passpredict.cc.s"
	cd /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phonkyponky/CLionProjects/ISS/sgp4/passpredict/passpredict.cc -o CMakeFiles/passpredict.dir/passpredict.cc.s

# Object files for target passpredict
passpredict_OBJECTS = \
"CMakeFiles/passpredict.dir/passpredict.cc.o"

# External object files for target passpredict
passpredict_EXTERNAL_OBJECTS =

sgp4/passpredict/passpredict: sgp4/passpredict/CMakeFiles/passpredict.dir/passpredict.cc.o
sgp4/passpredict/passpredict: sgp4/passpredict/CMakeFiles/passpredict.dir/build.make
sgp4/passpredict/passpredict: sgp4/libsgp4/libsgp4.a
sgp4/passpredict/passpredict: sgp4/passpredict/CMakeFiles/passpredict.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable passpredict"
	cd /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/passpredict.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sgp4/passpredict/CMakeFiles/passpredict.dir/build: sgp4/passpredict/passpredict
.PHONY : sgp4/passpredict/CMakeFiles/passpredict.dir/build

sgp4/passpredict/CMakeFiles/passpredict.dir/clean:
	cd /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict && $(CMAKE_COMMAND) -P CMakeFiles/passpredict.dir/cmake_clean.cmake
.PHONY : sgp4/passpredict/CMakeFiles/passpredict.dir/clean

sgp4/passpredict/CMakeFiles/passpredict.dir/depend:
	cd /Users/phonkyponky/CLionProjects/ISS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phonkyponky/CLionProjects/ISS /Users/phonkyponky/CLionProjects/ISS/sgp4/passpredict /Users/phonkyponky/CLionProjects/ISS/build /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict /Users/phonkyponky/CLionProjects/ISS/build/sgp4/passpredict/CMakeFiles/passpredict.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : sgp4/passpredict/CMakeFiles/passpredict.dir/depend

