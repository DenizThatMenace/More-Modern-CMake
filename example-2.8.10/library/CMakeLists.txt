# ./library/CMakeLists.txt -- Traditional CMake

cmake_minimum_required( VERSION 2.8.10 )

project( MathLibs )
set( VERSION 1.0.0 )
set( DESCRIPTION "The internal math-libraries." )

# Sources for common functionality, used in both math-libraries.
set( BASIC_SOURCES
    "src/BasicMath.cpp"
    "src/HeavyMath.cpp"  # Takes loooooong to compile!
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Math.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/MathAPI.h" )
# An OBJECT-library, used to only compile common sources once!
add_library( basicmath_ObjLib OBJECT ${BASIC_SOURCES} )

# Required include search-paths and constexpr support.
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" CACHE
    STRING "C++ compile-flags" FORCE )

# Requires "Boost.Outcome" (which has some requirements, too).
include_directories( SYSTEM
    "$<TARGET_PROPERTY:Boost::outcome,MY_INCLUDE_DIRS>" )
get_target_property( props Boost::outcome MY_COMPILE_FEATURES )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${props}" CACHE
    STRING "C++ compile-flags" FORCE )

# A shared library for basic-math functionality.
add_library( basicmath SHARED
    $<TARGET_OBJECTS:basicmath_ObjLib> )
# The usage-requirements of the OBJECT-library (and its
# direct dependency) are already set in directory scope
# (above in lines 19 to 28).

# A shared library for advanced-math functionality.
add_library( extmath SHARED
    "src/ExtendedMath.cpp"  # Premium-content!
    $<TARGET_OBJECTS:basicmath_ObjLib> )
# The usage-requirements of the OBJECT-library (and its
# direct dependency) are already set in directory scope
# (above in lines 19 to 28).

# Target 'extmath' requires include-path and needs
# to link to library-file of its extra dependency
# "Boost.Graph".
include_directories( SYSTEM "${Boost_INCLUDE_DIRS}" )
target_link_libraries( extmath ${Boost_LIBRARIES} )