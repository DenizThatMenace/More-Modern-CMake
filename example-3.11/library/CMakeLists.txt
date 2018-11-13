# ./library/CMakeLists.txt -- (More) Modern CMake

cmake_minimum_required( VERSION 3.11 )

project( MathLibs
         VERSION 1.0.0
         DESCRIPTION "The internal math-libraries." )

# An OBJECT-library, used to only compile common sources once
# which are used in both math-libraries.
add_library( basicmath_ObjLib OBJECT )
target_sources( basicmath_ObjLib
    PRIVATE   "src/BasicMath.cpp"
              "src/HeavyMath.cpp"  # Takes loooooong to compile!
    PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/include/Math.h"
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/MathAPI.h" )

# Required include search-paths and constexpr support.
target_include_directories( basicmath_ObjLib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_compile_features( basicmath_ObjLib
    PUBLIC cxx_constexpr )

# Requires "Boost.Outcome" (which has some requirements, too).
target_include_directories( basicmath_ObjLib SYSTEM
    PUBLIC
        $<TARGET_PROPERTY:Boost::outcome,INTERFACE_INCLUDE_DIRECTORIES> )
target_compile_features( basicmath_ObjLib
    PUBLIC $<TARGET_PROPERTY:Boost::outcome,INTERFACE_COMPILE_FEATURES> )
 
# A shared library for basic-math functionality.
add_library( basicmath SHARED )
target_sources( basicmath
    PRIVATE $<TARGET_OBJECTS:basicmath_ObjLib> )
# Inherit the usage-requirements from direct dependency 'basicmath_ObjLib'
# (and its indirect dependency "Boost.Outcome").
target_include_directories( basicmath
    PUBLIC
        $<TARGET_PROPERTY:basicmath_ObjLib,INTERFACE_INCLUDE_DIRECTORIES> )
target_compile_features( basicmath
    PUBLIC $<TARGET_PROPERTY:basicmath_ObjLib,INTERFACE_COMPILE_FEATURES> )

# A shared library for advanced-math functionality.
add_library( extmath SHARED )
target_sources( extmath
    PRIVATE "src/ExtendedMath.cpp"  # Premium-content!
            $<TARGET_OBJECTS:basicmath_ObjLib> )
# Inherit the usage-requirements from direct dependency 'basicmath_ObjLib'
# (and its indirect dependency "Boost.Outcome").
target_include_directories( extmath
    PUBLIC
        $<TARGET_PROPERTY:basicmath_ObjLib,INTERFACE_INCLUDE_DIRECTORIES> )
target_compile_features( extmath
    PUBLIC $<TARGET_PROPERTY:basicmath_ObjLib,INTERFACE_COMPILE_FEATURES> )
# "Boost.Graph" is an additional dependency.
target_link_libraries( extmath PRIVATE Boost::graph )

# Create ALIAS targets.
add_library( MyCalc::basicmath ALIAS basicmath )
add_library( MyCalc::extmath ALIAS extmath )
