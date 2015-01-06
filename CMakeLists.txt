# face recognition
# 2015
# 

project(faceRec)

cmake_minimum_required(VERSION 3.0.2)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(Qt5_DIR "D:\\development\\Qt\\5.3\\msvc2013_64\\")
set(CMAKE_PREFIX_PATH ${Qt5_DIR})

find_package(OpenCV REQUIRED)
find_package(Qt5Core  REQUIRED)
find_package(Qt5Gui  REQUIRED)
find_package(Qt5Widgets  REQUIRED)

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(core)
add_subdirectory(control)
add_subdirectory(frontend)
add_subdirectory(3rdparty)

#
# Organize projects into folders
#
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
SET_PROPERTY(TARGET libopentld             PROPERTY FOLDER "3rdparty/")
SET_PROPERTY(TARGET cvblobs                PROPERTY FOLDER "3rdparty/")
SET_PROPERTY(TARGET config++               PROPERTY FOLDER "3rdparty/")