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


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\technofest_st_git\Image-processing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\technofest_st_git\Image-processing

# Include any dependencies generated for this target.
include CMakeFiles/DisplayImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DisplayImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DisplayImage.dir/flags.make

CMakeFiles/DisplayImage.dir/open-video.cpp.obj: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/open-video.cpp.obj: CMakeFiles/DisplayImage.dir/includes_CXX.rsp
CMakeFiles/DisplayImage.dir/open-video.cpp.obj: open-video.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\technofest_st_git\Image-processing\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DisplayImage.dir/open-video.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DisplayImage.dir\open-video.cpp.obj -c C:\technofest_st_git\Image-processing\open-video.cpp

CMakeFiles/DisplayImage.dir/open-video.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/open-video.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\technofest_st_git\Image-processing\open-video.cpp > CMakeFiles\DisplayImage.dir\open-video.cpp.i

CMakeFiles/DisplayImage.dir/open-video.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/open-video.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\technofest_st_git\Image-processing\open-video.cpp -o CMakeFiles\DisplayImage.dir\open-video.cpp.s

# Object files for target DisplayImage
DisplayImage_OBJECTS = \
"CMakeFiles/DisplayImage.dir/open-video.cpp.obj"

# External object files for target DisplayImage
DisplayImage_EXTERNAL_OBJECTS =

DisplayImage.exe: CMakeFiles/DisplayImage.dir/open-video.cpp.obj
DisplayImage.exe: CMakeFiles/DisplayImage.dir/build.make
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_calib3d430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_core430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_dnn430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_features2d430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_flann430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_gapi430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_highgui430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_imgcodecs430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_imgproc430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_ml430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_objdetect430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_photo430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_stitching430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_video430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_videoio430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/liblibprotobuf.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libade.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_imgcodecs430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/liblibjpeg-turbo.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/liblibwebp.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/liblibpng.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/liblibtiff.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/liblibjasper.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libIlmImf.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libquirc.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_calib3d430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_features2d430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_flann430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_imgproc430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libopencv_core430.a
DisplayImage.exe: C:/technofest_st_git/lib/install/static/x64/mingw/staticlib/libzlib.a
DisplayImage.exe: CMakeFiles/DisplayImage.dir/linklibs.rsp
DisplayImage.exe: CMakeFiles/DisplayImage.dir/objects1.rsp
DisplayImage.exe: CMakeFiles/DisplayImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\technofest_st_git\Image-processing\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DisplayImage.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DisplayImage.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DisplayImage.dir/build: DisplayImage.exe

.PHONY : CMakeFiles/DisplayImage.dir/build

CMakeFiles/DisplayImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DisplayImage.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DisplayImage.dir/clean

CMakeFiles/DisplayImage.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\technofest_st_git\Image-processing C:\technofest_st_git\Image-processing C:\technofest_st_git\Image-processing C:\technofest_st_git\Image-processing C:\technofest_st_git\Image-processing\CMakeFiles\DisplayImage.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DisplayImage.dir/depend
