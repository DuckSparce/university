# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/USER/source/repos/Labs_KDM_1sem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/USER/source/repos/Labs_KDM_1sem/build

# Include any dependencies generated for this target.
include CMakeFiles/testproject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testproject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testproject.dir/flags.make

CMakeFiles/testproject.dir/main.c.obj: CMakeFiles/testproject.dir/flags.make
CMakeFiles/testproject.dir/main.c.obj: C:/Users/USER/source/repos/Labs_KDM_1sem/main.c
CMakeFiles/testproject.dir/main.c.obj: CMakeFiles/testproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/USER/source/repos/Labs_KDM_1sem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testproject.dir/main.c.obj"
	C:/Users/USER/Compilers/gcc-v13.2.0-mingw-v11.0.0-i686/gcc-v13.2.0-mingw-v11.0.0-i686/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/testproject.dir/main.c.obj -MF CMakeFiles/testproject.dir/main.c.obj.d -o CMakeFiles/testproject.dir/main.c.obj -c C:/Users/USER/source/repos/Labs_KDM_1sem/main.c

CMakeFiles/testproject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/testproject.dir/main.c.i"
	C:/Users/USER/Compilers/gcc-v13.2.0-mingw-v11.0.0-i686/gcc-v13.2.0-mingw-v11.0.0-i686/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/USER/source/repos/Labs_KDM_1sem/main.c > CMakeFiles/testproject.dir/main.c.i

CMakeFiles/testproject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/testproject.dir/main.c.s"
	C:/Users/USER/Compilers/gcc-v13.2.0-mingw-v11.0.0-i686/gcc-v13.2.0-mingw-v11.0.0-i686/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/USER/source/repos/Labs_KDM_1sem/main.c -o CMakeFiles/testproject.dir/main.c.s

# Object files for target testproject
testproject_OBJECTS = \
"CMakeFiles/testproject.dir/main.c.obj"

# External object files for target testproject
testproject_EXTERNAL_OBJECTS =

testproject.exe: CMakeFiles/testproject.dir/main.c.obj
testproject.exe: CMakeFiles/testproject.dir/build.make
testproject.exe: CMakeFiles/testproject.dir/linkLibs.rsp
testproject.exe: CMakeFiles/testproject.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/USER/source/repos/Labs_KDM_1sem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable testproject.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/testproject.dir/objects.a
	C:/Users/USER/Compilers/gcc-v13.2.0-mingw-v11.0.0-i686/gcc-v13.2.0-mingw-v11.0.0-i686/bin/ar.exe qc CMakeFiles/testproject.dir/objects.a @CMakeFiles/testproject.dir/objects1.rsp
	C:/Users/USER/Compilers/gcc-v13.2.0-mingw-v11.0.0-i686/gcc-v13.2.0-mingw-v11.0.0-i686/bin/gcc.exe -g -Wl,--whole-archive CMakeFiles/testproject.dir/objects.a -Wl,--no-whole-archive -o testproject.exe -Wl,--out-implib,libtestproject.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/testproject.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/testproject.dir/build: testproject.exe
.PHONY : CMakeFiles/testproject.dir/build

CMakeFiles/testproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testproject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testproject.dir/clean

CMakeFiles/testproject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/USER/source/repos/Labs_KDM_1sem C:/Users/USER/source/repos/Labs_KDM_1sem C:/Users/USER/source/repos/Labs_KDM_1sem/build C:/Users/USER/source/repos/Labs_KDM_1sem/build C:/Users/USER/source/repos/Labs_KDM_1sem/build/CMakeFiles/testproject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/testproject.dir/depend

