# ./external/boost_outcome/CMakeLists.txt -- More Modern CMake

# Requires CMake 3.12, but also works with 3.13 policies set.
cmake_minimum_required( VERSION 3.12...3.13 )

project( External.Reviewed_Boost.outcome
         VERSION 2.0
         DESCRIPTION "Boost.Outcome header-only lib." )

# Provide target for "Boost.Outcome" library.
add_library( Reviewed_Boost.outcome INTERFACE
    IMPORTED GLOBAL )
# Store include search-path containing headers
# of "Boost.Outcome".
target_include_directories( Reviewed_Boost.outcome SYSTEM
    INTERFACE /opt/boost-outcome/include )
# Require at least compiling with C++14.
target_compile_features( Reviewed_Boost.outcome
    INTERFACE cxx_std_14 )

# Create an alias for "Boost.Outcome".
add_library( Boost::outcome ALIAS Reviewed_Boost.outcome )