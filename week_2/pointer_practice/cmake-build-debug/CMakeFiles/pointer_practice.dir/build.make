# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pointer_practice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pointer_practice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pointer_practice.dir/flags.make

CMakeFiles/pointer_practice.dir/main.cpp.obj: CMakeFiles/pointer_practice.dir/flags.make
CMakeFiles/pointer_practice.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pointer_practice.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pointer_practice.dir\main.cpp.obj -c D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\main.cpp

CMakeFiles/pointer_practice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pointer_practice.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\main.cpp > CMakeFiles\pointer_practice.dir\main.cpp.i

CMakeFiles/pointer_practice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pointer_practice.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\main.cpp -o CMakeFiles\pointer_practice.dir\main.cpp.s

# Object files for target pointer_practice
pointer_practice_OBJECTS = \
"CMakeFiles/pointer_practice.dir/main.cpp.obj"

# External object files for target pointer_practice
pointer_practice_EXTERNAL_OBJECTS =

pointer_practice.exe: CMakeFiles/pointer_practice.dir/main.cpp.obj
pointer_practice.exe: CMakeFiles/pointer_practice.dir/build.make
pointer_practice.exe: CMakeFiles/pointer_practice.dir/linklibs.rsp
pointer_practice.exe: CMakeFiles/pointer_practice.dir/objects1.rsp
pointer_practice.exe: CMakeFiles/pointer_practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pointer_practice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pointer_practice.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pointer_practice.dir/build: pointer_practice.exe

.PHONY : CMakeFiles/pointer_practice.dir/build

CMakeFiles/pointer_practice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pointer_practice.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pointer_practice.dir/clean

CMakeFiles/pointer_practice.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\cmake-build-debug D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\cmake-build-debug D:\Haake\Documents\seattle_u_notes\data_structures\week_2\pointer_practice\cmake-build-debug\CMakeFiles\pointer_practice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pointer_practice.dir/depend

