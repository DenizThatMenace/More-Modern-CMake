#./CMakeLists.txt -- Modern CMake

cmake_minimum_required( VERSION 3.10 )

project( Example_for_CMake
         VERSION 3.10
         DESCRIPTION "Example project for Modern CMake" )

 # Always use '-fPIC'/'-fPIE' option.
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# Make external libraries globally available.
add_subdirectory( external )
include( external/boost/CMakeLists.txt )

# Create targets for building the (local) libraries.
add_subdirectory( library )

# Create the targets for the entire example-app.
add_subdirectory( app )
