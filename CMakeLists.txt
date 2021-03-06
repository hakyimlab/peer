cmake_minimum_required(VERSION 2.8)
project(PEER)

#build options
#bindings
#PYTHON on by default
#option(BUILD_PYTHON_PACKAGE "Enable Python bindings" ON)
#R optional
option(BUILD_R_PACKAGE "Enable R bindings" OFF)

#build stuff
option(BUILD_UNIVERSAL "Build both 32 and 64 bit versions" OFF)

#compile i386+x86_64 universal binaries on OS X
if (BUILD_UNIVERSAL)
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
SET(CMAKE_OSX_ARCHITECTURES "i386;x86_64")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
endif (BUILD_UNIVERSAL)

## Documentation for final package
# manual installation paths

##PYTHON build options##
# Path to python executable. If specified peer is built against this
# python version, otherwise "which python" is used for auto-detection
#SET(PYTHON_EXECUTABLE "")
#Python include directory 
#normally there is no need to specify them;instead these are
#auto-determined from the location of the binary.
#SET(PYTHON_INCLUDE_DIRS "")
#Python install directory
#If specified, the peer module will be installed here. Otherwise the
#default site-packages location of the respective python installation
#is used. 
#SET(PYTHON_INSTDIR "")
#Numpy header fiels.
#Usually there is no need to specify them as they are automatically
#determined from the python binary.
#Note: it is vital that peer is built against the exact same python
#installation that you are aiming to use.
#SET(NUMPY_INCLUDE_DIR "")
#
##/PYTHON END##


##R build options###
#set(R_EXECUTABLE "/usr/local/bin/R")
#R executable 
#set(R_HOME "")
#R home directory
#set(R_H "")
#R include directory for headers
#set(R_INCLUDEDIR "")
#R include dir
#set(LIBR_SO)
#R dylib or dynamic link SO 
##/R END##


# OLI's build options
#set(LIBR_SO "/opt/local/lib/R/lib/x86_64/libR.dylib")
##/R END



# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#There are lots of scripts with cmake
#for finding external libraries. 
#see /usr/local/share/cmake-2.6/Modules/Find*.cmake for more examples

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_SWIG_FLAGS "")

set(CMAKE_MODULE_PATH "${PEER_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
include_directories(./include)

add_definitions(-g -Wextra -D_BSD_SOURCE)

#fPic while compiling on
#this seems to be needed on some linux systems
#set(CMAKE_CXX_FLAGS "-fPIC -O3 -march=core2")
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories(./External/alglib/src)

#add Cmake modules
add_subdirectory(./External/alglib/src)
add_subdirectory(./External/csv_parser)
add_subdirectory(./src)

IF (BUILD_PEERTOOL)
add_subdirectory(./External/yaml-cpp)
endif (BUILD_PEERTOOL)
#### build external interface (optional) #####
if (BUILD_PYTHON_PACKAGE)
add_subdirectory(./python)
endif (BUILD_PYTHON_PACKAGE)
if (BUILD_R_PACKAGE)
add_subdirectory(./R)
endif (BUILD_R_PACKAGE)

