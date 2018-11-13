# ./external/boost_outcome/CMakeLists.txt -- Traditional CMake

cmake_minimum_required( VERSION 2.8.10 )

project( External.Reviewed_Boost.outcome )
set( VERSION 2.0 )
set( DESCRIPTION "Boost.Outcome header-only lib." )

# Provide target for "Boost.Outcome" library.
add_library( Boost::outcome UNKNOWN
    IMPORTED GLOBAL )
# Store include search-path containing headers
# of "Boost.Outcome".
set_target_properties( Boost::outcome PROPERTIES
    MY_INCLUDE_DIRS /opt/boost-outcome/include )
# Require at least compiling with C++14.
set_target_properties( Boost::outcome PROPERTIES
    MY_COMPILE_FEATURES "-std=c++14" )
