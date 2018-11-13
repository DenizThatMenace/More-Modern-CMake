#./CMakeLists.txt -- More Modern CMake

# Requires CMake 3.12, but also works with 3.13 policies set.
cmake_minimum_required( VERSION 3.12...3.13 )

project( Example_for_CMake
         VERSION 3.12
         DESCRIPTION "Example project for More Modern CMake (using CMake 3.12 or newer)." )

 # Always use '-fPIC'/'-fPIE' option.
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# Make external libraries globally available.
add_subdirectory( external )

# Create targets for building the (local) libraries.
add_subdirectory( library )

# Create the targets for the entire example-app.
add_subdirectory( app )
