# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/triangulation-planar-embedding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/triangulation-planar-embedding/build

# Include any dependencies generated for this target.
include test/writer/CMakeFiles/test_writer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/writer/CMakeFiles/test_writer.dir/compiler_depend.make

# Include the progress variables for this target.
include test/writer/CMakeFiles/test_writer.dir/progress.make

# Include the compile flags for this target's objects.
include test/writer/CMakeFiles/test_writer.dir/flags.make

test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.o: test/writer/CMakeFiles/test_writer.dir/flags.make
test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.o: ../test/writer/test_writer.cxx
test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.o: test/writer/CMakeFiles/test_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.o"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.o -MF CMakeFiles/test_writer.dir/test_writer.cxx.o.d -o CMakeFiles/test_writer.dir/test_writer.cxx.o -c /mnt/triangulation-planar-embedding/test/writer/test_writer.cxx

test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_writer.dir/test_writer.cxx.i"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/triangulation-planar-embedding/test/writer/test_writer.cxx > CMakeFiles/test_writer.dir/test_writer.cxx.i

test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_writer.dir/test_writer.cxx.s"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/triangulation-planar-embedding/test/writer/test_writer.cxx -o CMakeFiles/test_writer.dir/test_writer.cxx.s

test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o: test/writer/CMakeFiles/test_writer.dir/flags.make
test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o: ../src/io/reader.cxx
test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o: test/writer/CMakeFiles/test_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o -MF CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o.d -o CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o -c /mnt/triangulation-planar-embedding/src/io/reader.cxx

test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.i"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/triangulation-planar-embedding/src/io/reader.cxx > CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.i

test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.s"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/triangulation-planar-embedding/src/io/reader.cxx -o CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.s

test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o: test/writer/CMakeFiles/test_writer.dir/flags.make
test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o: ../src/io/writer.cxx
test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o: test/writer/CMakeFiles/test_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o -MF CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o.d -o CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o -c /mnt/triangulation-planar-embedding/src/io/writer.cxx

test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.i"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/triangulation-planar-embedding/src/io/writer.cxx > CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.i

test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.s"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/triangulation-planar-embedding/src/io/writer.cxx -o CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.s

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o: test/writer/CMakeFiles/test_writer.dir/flags.make
test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o: ../src/common/global.cxx
test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o: test/writer/CMakeFiles/test_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o -MF CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o.d -o CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o -c /mnt/triangulation-planar-embedding/src/common/global.cxx

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.i"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/triangulation-planar-embedding/src/common/global.cxx > CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.i

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.s"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/triangulation-planar-embedding/src/common/global.cxx -o CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.s

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o: test/writer/CMakeFiles/test_writer.dir/flags.make
test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o: ../src/common/math.cxx
test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o: test/writer/CMakeFiles/test_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o -MF CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o.d -o CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o -c /mnt/triangulation-planar-embedding/src/common/math.cxx

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.i"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/triangulation-planar-embedding/src/common/math.cxx > CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.i

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.s"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/triangulation-planar-embedding/src/common/math.cxx -o CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.s

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o: test/writer/CMakeFiles/test_writer.dir/flags.make
test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o: ../src/common/random.cxx
test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o: test/writer/CMakeFiles/test_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o -MF CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o.d -o CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o -c /mnt/triangulation-planar-embedding/src/common/random.cxx

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.i"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/triangulation-planar-embedding/src/common/random.cxx > CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.i

test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.s"
	cd /mnt/triangulation-planar-embedding/build/test/writer && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/triangulation-planar-embedding/src/common/random.cxx -o CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.s

# Object files for target test_writer
test_writer_OBJECTS = \
"CMakeFiles/test_writer.dir/test_writer.cxx.o" \
"CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o" \
"CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o" \
"CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o" \
"CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o" \
"CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o"

# External object files for target test_writer
test_writer_EXTERNAL_OBJECTS =

../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/test_writer.cxx.o
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/__/__/src/io/reader.cxx.o
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/__/__/src/io/writer.cxx.o
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/__/__/src/common/global.cxx.o
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/__/__/src/common/math.cxx.o
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/__/__/src/common/random.cxx.o
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/build.make
../bin/test_writer: test/writer/CMakeFiles/test_writer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/triangulation-planar-embedding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../../../bin/test_writer"
	cd /mnt/triangulation-planar-embedding/build/test/writer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_writer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/writer/CMakeFiles/test_writer.dir/build: ../bin/test_writer
.PHONY : test/writer/CMakeFiles/test_writer.dir/build

test/writer/CMakeFiles/test_writer.dir/clean:
	cd /mnt/triangulation-planar-embedding/build/test/writer && $(CMAKE_COMMAND) -P CMakeFiles/test_writer.dir/cmake_clean.cmake
.PHONY : test/writer/CMakeFiles/test_writer.dir/clean

test/writer/CMakeFiles/test_writer.dir/depend:
	cd /mnt/triangulation-planar-embedding/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/triangulation-planar-embedding /mnt/triangulation-planar-embedding/test/writer /mnt/triangulation-planar-embedding/build /mnt/triangulation-planar-embedding/build/test/writer /mnt/triangulation-planar-embedding/build/test/writer/CMakeFiles/test_writer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/writer/CMakeFiles/test_writer.dir/depend

