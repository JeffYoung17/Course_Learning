# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/fqy/project/Course/slam_tutorial/5_BA_GN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fqy/project/Course/slam_tutorial/5_BA_GN/build

# Include any dependencies generated for this target.
include CMakeFiles/BA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BA.dir/flags.make

CMakeFiles/BA.dir/GN-BA.cpp.o: CMakeFiles/BA.dir/flags.make
CMakeFiles/BA.dir/GN-BA.cpp.o: ../GN-BA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fqy/project/Course/slam_tutorial/5_BA_GN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BA.dir/GN-BA.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BA.dir/GN-BA.cpp.o -c /home/fqy/project/Course/slam_tutorial/5_BA_GN/GN-BA.cpp

CMakeFiles/BA.dir/GN-BA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BA.dir/GN-BA.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fqy/project/Course/slam_tutorial/5_BA_GN/GN-BA.cpp > CMakeFiles/BA.dir/GN-BA.cpp.i

CMakeFiles/BA.dir/GN-BA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BA.dir/GN-BA.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fqy/project/Course/slam_tutorial/5_BA_GN/GN-BA.cpp -o CMakeFiles/BA.dir/GN-BA.cpp.s

CMakeFiles/BA.dir/GN-BA.cpp.o.requires:

.PHONY : CMakeFiles/BA.dir/GN-BA.cpp.o.requires

CMakeFiles/BA.dir/GN-BA.cpp.o.provides: CMakeFiles/BA.dir/GN-BA.cpp.o.requires
	$(MAKE) -f CMakeFiles/BA.dir/build.make CMakeFiles/BA.dir/GN-BA.cpp.o.provides.build
.PHONY : CMakeFiles/BA.dir/GN-BA.cpp.o.provides

CMakeFiles/BA.dir/GN-BA.cpp.o.provides.build: CMakeFiles/BA.dir/GN-BA.cpp.o


# Object files for target BA
BA_OBJECTS = \
"CMakeFiles/BA.dir/GN-BA.cpp.o"

# External object files for target BA
BA_EXTERNAL_OBJECTS =

BA: CMakeFiles/BA.dir/GN-BA.cpp.o
BA: CMakeFiles/BA.dir/build.make
BA: /home/fqy/dependency/Sophus/build/libSophus.so
BA: /usr/local/lib/libpangolin.so
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_dnn.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_ml.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_objdetect.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_shape.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_stitching.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_superres.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_videostab.so.3.3.0
BA: /usr/local/lib/libceres.a
BA: /usr/lib/x86_64-linux-gnu/libGLU.so
BA: /usr/lib/x86_64-linux-gnu/libGL.so
BA: /usr/lib/x86_64-linux-gnu/libGLEW.so
BA: /usr/lib/x86_64-linux-gnu/libSM.so
BA: /usr/lib/x86_64-linux-gnu/libICE.so
BA: /usr/lib/x86_64-linux-gnu/libX11.so
BA: /usr/lib/x86_64-linux-gnu/libXext.so
BA: /usr/lib/x86_64-linux-gnu/libdc1394.so
BA: /opt/ros/kinetic/lib/librealsense.so
BA: /usr/lib/libOpenNI.so
BA: /usr/lib/libOpenNI2.so
BA: /usr/lib/x86_64-linux-gnu/libpng.so
BA: /usr/lib/x86_64-linux-gnu/libz.so
BA: /usr/lib/x86_64-linux-gnu/libjpeg.so
BA: /usr/lib/x86_64-linux-gnu/libtiff.so
BA: /usr/lib/x86_64-linux-gnu/libIlmImf.so
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_calib3d.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_features2d.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_flann.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_highgui.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_photo.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_video.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_videoio.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_imgcodecs.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_imgproc.so.3.3.0
BA: /home/fqy/dependency/OpenCV330/lib/libopencv_core.so.3.3.0
BA: /usr/lib/x86_64-linux-gnu/libglog.so
BA: /usr/lib/x86_64-linux-gnu/libgflags.so
BA: /usr/lib/x86_64-linux-gnu/libspqr.so
BA: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so
BA: /usr/lib/x86_64-linux-gnu/libtbb.so
BA: /usr/lib/x86_64-linux-gnu/libcholmod.so
BA: /usr/lib/x86_64-linux-gnu/libccolamd.so
BA: /usr/lib/x86_64-linux-gnu/libcamd.so
BA: /usr/lib/x86_64-linux-gnu/libcolamd.so
BA: /usr/lib/x86_64-linux-gnu/libamd.so
BA: /usr/lib/liblapack.so
BA: /usr/lib/libblas.so
BA: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
BA: /usr/lib/x86_64-linux-gnu/librt.so
BA: /usr/lib/x86_64-linux-gnu/libcxsparse.so
BA: /usr/lib/liblapack.so
BA: /usr/lib/libblas.so
BA: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
BA: /usr/lib/x86_64-linux-gnu/librt.so
BA: /usr/lib/x86_64-linux-gnu/libcxsparse.so
BA: CMakeFiles/BA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fqy/project/Course/slam_tutorial/5_BA_GN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BA.dir/build: BA

.PHONY : CMakeFiles/BA.dir/build

CMakeFiles/BA.dir/requires: CMakeFiles/BA.dir/GN-BA.cpp.o.requires

.PHONY : CMakeFiles/BA.dir/requires

CMakeFiles/BA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BA.dir/clean

CMakeFiles/BA.dir/depend:
	cd /home/fqy/project/Course/slam_tutorial/5_BA_GN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fqy/project/Course/slam_tutorial/5_BA_GN /home/fqy/project/Course/slam_tutorial/5_BA_GN /home/fqy/project/Course/slam_tutorial/5_BA_GN/build /home/fqy/project/Course/slam_tutorial/5_BA_GN/build /home/fqy/project/Course/slam_tutorial/5_BA_GN/build/CMakeFiles/BA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BA.dir/depend
