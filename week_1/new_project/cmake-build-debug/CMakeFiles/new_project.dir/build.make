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
CMAKE_SOURCE_DIR = D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/new_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/new_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new_project.dir/flags.make

CMakeFiles/new_project.dir/main.cpp.obj: CMakeFiles/new_project.dir/flags.make
CMakeFiles/new_project.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/new_project.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\new_project.dir\main.cpp.obj -c D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\main.cpp

CMakeFiles/new_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/new_project.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\main.cpp > CMakeFiles\new_project.dir\main.cpp.i

CMakeFiles/new_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/new_project.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\main.cpp -o CMakeFiles\new_project.dir\main.cpp.s

CMakeFiles/new_project.dir/Rectangle.cpp.obj: CMakeFiles/new_project.dir/flags.make
CMakeFiles/new_project.dir/Rectangle.cpp.obj: ../Rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/new_project.dir/Rectangle.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\new_project.dir\Rectangle.cpp.obj -c D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\Rectangle.cpp

CMakeFiles/new_project.dir/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/new_project.dir/Rectangle.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\Rectangle.cpp > CMakeFiles\new_project.dir\Rectangle.cpp.i

CMakeFiles/new_project.dir/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/new_project.dir/Rectangle.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\Rectangle.cpp -o CMakeFiles\new_project.dir\Rectangle.cpp.s

# Object files for target new_project
new_project_OBJECTS = \
"CMakeFiles/new_project.dir/main.cpp.obj" \
"CMakeFiles/new_project.dir/Rectangle.cpp.obj"

# External object files for target new_project
new_project_EXTERNAL_OBJECTS =

new_project.exe: CMakeFiles/new_project.dir/main.cpp.obj
new_project.exe: CMakeFiles/new_project.dir/Rectangle.cpp.obj
new_project.exe: CMakeFiles/new_project.dir/build.make
new_project.exe: CMakeFiles/new_project.dir/linklibs.rsp
new_project.exe: CMakeFiles/new_project.dir/objects1.rsp
new_project.exe: CMakeFiles/new_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable new_project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\new_project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new_project.dir/build: new_project.exe

.PHONY : CMakeFiles/new_project.dir/build

CMakeFiles/new_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\new_project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/new_project.dir/clean

CMakeFiles/new_project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug D:\Haake\Documents\seattle_u_notes\data_structures\week_1\new_project\cmake-build-debug\CMakeFiles\new_project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/new_project.dir/depend

