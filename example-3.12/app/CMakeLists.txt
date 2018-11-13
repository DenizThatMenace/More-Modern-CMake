# ./app/CMakeLists.txt -- More Modern CMake

# Requires CMake 3.12, but also works with 3.13 policies set.
cmake_minimum_required( VERSION 3.12...3.13 )

project( CalculatorApp
         VERSION 1.0
         DESCRIPTION "My fancy calculator app." )

# Freely available calculator app.
add_executable( FreeCalculator )
target_sources( FreeCalculator PRIVATE "src/main.cpp" )
target_link_libraries( FreeCalculator
    PRIVATE MyCalc::basicmath
            Boost::program_options )

# Premium-calculator app (with advanced functionality)
add_executable( PremiumCalculator )
target_sources( PremiumCalculator PRIVATE "src/main.cpp" )
target_link_libraries( PremiumCalculator
    PRIVATE MyCalc::extmath
            Boost::program_options )

# Possibly, compile key-file into premium-calculator, too.
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/key-file.cpp")
    target_sources( PremiumCalculator
        PRIVATE "src/key-file.cpp" )
endif ()
