# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/antitoine/Programming/lutin-compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antitoine/Programming/lutin-compiler

# Include any dependencies generated for this target.
include CMakeFiles/lutin_compiler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lutin_compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lutin_compiler.dir/flags.make

CMakeFiles/lutin_compiler.dir/src/main.cpp.o: CMakeFiles/lutin_compiler.dir/flags.make
CMakeFiles/lutin_compiler.dir/src/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antitoine/Programming/lutin-compiler/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lutin_compiler.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lutin_compiler.dir/src/main.cpp.o -c /home/antitoine/Programming/lutin-compiler/src/main.cpp

CMakeFiles/lutin_compiler.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lutin_compiler.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antitoine/Programming/lutin-compiler/src/main.cpp > CMakeFiles/lutin_compiler.dir/src/main.cpp.i

CMakeFiles/lutin_compiler.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lutin_compiler.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antitoine/Programming/lutin-compiler/src/main.cpp -o CMakeFiles/lutin_compiler.dir/src/main.cpp.s

CMakeFiles/lutin_compiler.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/lutin_compiler.dir/src/main.cpp.o.requires

CMakeFiles/lutin_compiler.dir/src/main.cpp.o.provides: CMakeFiles/lutin_compiler.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lutin_compiler.dir/build.make CMakeFiles/lutin_compiler.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/lutin_compiler.dir/src/main.cpp.o.provides

CMakeFiles/lutin_compiler.dir/src/main.cpp.o.provides.build: CMakeFiles/lutin_compiler.dir/src/main.cpp.o

CMakeFiles/lutin_compiler.dir/src/state.cpp.o: CMakeFiles/lutin_compiler.dir/flags.make
CMakeFiles/lutin_compiler.dir/src/state.cpp.o: src/state.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antitoine/Programming/lutin-compiler/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lutin_compiler.dir/src/state.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lutin_compiler.dir/src/state.cpp.o -c /home/antitoine/Programming/lutin-compiler/src/state.cpp

CMakeFiles/lutin_compiler.dir/src/state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lutin_compiler.dir/src/state.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antitoine/Programming/lutin-compiler/src/state.cpp > CMakeFiles/lutin_compiler.dir/src/state.cpp.i

CMakeFiles/lutin_compiler.dir/src/state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lutin_compiler.dir/src/state.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antitoine/Programming/lutin-compiler/src/state.cpp -o CMakeFiles/lutin_compiler.dir/src/state.cpp.s

CMakeFiles/lutin_compiler.dir/src/state.cpp.o.requires:
.PHONY : CMakeFiles/lutin_compiler.dir/src/state.cpp.o.requires

CMakeFiles/lutin_compiler.dir/src/state.cpp.o.provides: CMakeFiles/lutin_compiler.dir/src/state.cpp.o.requires
	$(MAKE) -f CMakeFiles/lutin_compiler.dir/build.make CMakeFiles/lutin_compiler.dir/src/state.cpp.o.provides.build
.PHONY : CMakeFiles/lutin_compiler.dir/src/state.cpp.o.provides

CMakeFiles/lutin_compiler.dir/src/state.cpp.o.provides.build: CMakeFiles/lutin_compiler.dir/src/state.cpp.o

CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o: CMakeFiles/lutin_compiler.dir/flags.make
CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o: src/symbol.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antitoine/Programming/lutin-compiler/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o -c /home/antitoine/Programming/lutin-compiler/src/symbol.cpp

CMakeFiles/lutin_compiler.dir/src/symbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lutin_compiler.dir/src/symbol.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antitoine/Programming/lutin-compiler/src/symbol.cpp > CMakeFiles/lutin_compiler.dir/src/symbol.cpp.i

CMakeFiles/lutin_compiler.dir/src/symbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lutin_compiler.dir/src/symbol.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antitoine/Programming/lutin-compiler/src/symbol.cpp -o CMakeFiles/lutin_compiler.dir/src/symbol.cpp.s

CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.requires:
.PHONY : CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.requires

CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.provides: CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.requires
	$(MAKE) -f CMakeFiles/lutin_compiler.dir/build.make CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.provides.build
.PHONY : CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.provides

CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.provides.build: CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o

# Object files for target lutin_compiler
lutin_compiler_OBJECTS = \
"CMakeFiles/lutin_compiler.dir/src/main.cpp.o" \
"CMakeFiles/lutin_compiler.dir/src/state.cpp.o" \
"CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o"

# External object files for target lutin_compiler
lutin_compiler_EXTERNAL_OBJECTS =

lutin_compiler: CMakeFiles/lutin_compiler.dir/src/main.cpp.o
lutin_compiler: CMakeFiles/lutin_compiler.dir/src/state.cpp.o
lutin_compiler: CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o
lutin_compiler: CMakeFiles/lutin_compiler.dir/build.make
lutin_compiler: CMakeFiles/lutin_compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lutin_compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lutin_compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lutin_compiler.dir/build: lutin_compiler
.PHONY : CMakeFiles/lutin_compiler.dir/build

CMakeFiles/lutin_compiler.dir/requires: CMakeFiles/lutin_compiler.dir/src/main.cpp.o.requires
CMakeFiles/lutin_compiler.dir/requires: CMakeFiles/lutin_compiler.dir/src/state.cpp.o.requires
CMakeFiles/lutin_compiler.dir/requires: CMakeFiles/lutin_compiler.dir/src/symbol.cpp.o.requires
.PHONY : CMakeFiles/lutin_compiler.dir/requires

CMakeFiles/lutin_compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lutin_compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lutin_compiler.dir/clean

CMakeFiles/lutin_compiler.dir/depend:
	cd /home/antitoine/Programming/lutin-compiler && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antitoine/Programming/lutin-compiler /home/antitoine/Programming/lutin-compiler /home/antitoine/Programming/lutin-compiler /home/antitoine/Programming/lutin-compiler /home/antitoine/Programming/lutin-compiler/CMakeFiles/lutin_compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lutin_compiler.dir/depend

