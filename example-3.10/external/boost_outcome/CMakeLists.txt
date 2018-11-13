# ./external/boost_outcome/CMakeLists.txt -- Modern CMake

cmake_minimum_required( VERSION 3.10 )

project( External.Reviewed_Boost.outcome
         VERSION 2.0
         DESCRIPTION "Boost.Outcome header-only lib." )

# Provide target for "Boost.Outcome" library.
add_library( Boost::outcome INTERFACE
    IMPORTED GLOBAL )
# Store include search-path containing headers
# of "Boost.Outcome".
set_target_properties( Boost::outcome PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES /opt/boost-outcome/include ) 
# Require at least compiling with C++14.
set_target_properties( Boost::outcome PROPERTIES
    INTERFACE_COMPILE_FEATURES cxx_std_14 ) 
