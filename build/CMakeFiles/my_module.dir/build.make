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
include CMakeFiles/my_module.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_module.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_module.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_module.dir/flags.make

CMakeFiles/my_module.dir/codegen:
.PHONY : CMakeFiles/my_module.dir/codegen

CMakeFiles/my_module.dir/src/my_bindings.cpp.o: CMakeFiles/my_module.dir/flags.make
CMakeFiles/my_module.dir/src/my_bindings.cpp.o: /Users/phonkyponky/CLionProjects/ISS/src/my_bindings.cpp
CMakeFiles/my_module.dir/src/my_bindings.cpp.o: CMakeFiles/my_module.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_module.dir/src/my_bindings.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_module.dir/src/my_bindings.cpp.o -MF CMakeFiles/my_module.dir/src/my_bindings.cpp.o.d -o CMakeFiles/my_module.dir/src/my_bindings.cpp.o -c /Users/phonkyponky/CLionProjects/ISS/src/my_bindings.cpp

CMakeFiles/my_module.dir/src/my_bindings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my_module.dir/src/my_bindings.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phonkyponky/CLionProjects/ISS/src/my_bindings.cpp > CMakeFiles/my_module.dir/src/my_bindings.cpp.i

CMakeFiles/my_module.dir/src/my_bindings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my_module.dir/src/my_bindings.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phonkyponky/CLionProjects/ISS/src/my_bindings.cpp -o CMakeFiles/my_module.dir/src/my_bindings.cpp.s

# Object files for target my_module
my_module_OBJECTS = \
"CMakeFiles/my_module.dir/src/my_bindings.cpp.o"

# External object files for target my_module
my_module_EXTERNAL_OBJECTS =

my_module.cpython-312-darwin.so: CMakeFiles/my_module.dir/src/my_bindings.cpp.o
my_module.cpython-312-darwin.so: CMakeFiles/my_module.dir/build.make
my_module.cpython-312-darwin.so: CMakeFiles/my_module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module my_module.cpython-312-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_module.dir/link.txt --verbose=$(VERBOSE)
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip -x /Users/phonkyponky/CLionProjects/ISS/build/my_module.cpython-312-darwin.so

# Rule to build all files generated by this target.
CMakeFiles/my_module.dir/build: my_module.cpython-312-darwin.so
.PHONY : CMakeFiles/my_module.dir/build

CMakeFiles/my_module.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_module.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_module.dir/clean

CMakeFiles/my_module.dir/depend:
	cd /Users/phonkyponky/CLionProjects/ISS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phonkyponky/CLionProjects/ISS /Users/phonkyponky/CLionProjects/ISS /Users/phonkyponky/CLionProjects/ISS/build /Users/phonkyponky/CLionProjects/ISS/build /Users/phonkyponky/CLionProjects/ISS/build/CMakeFiles/my_module.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/my_module.dir/depend
