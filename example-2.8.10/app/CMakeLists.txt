# ./app/CMakeLists.txt -- Traditional CMake

cmake_minimum_required( VERSION 2.8.10 )

project( CalculatorApp )
set( VERSION 1.0 )
set( DESCRIPTION "My fancy calculator app." )

# Freely available calculator app.
add_executable( FreeCalculator "src/main.cpp" )
target_link_libraries( FreeCalculator basicmath )

# Possibly, compile key-file into premium-calculator, too.
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/key-file.cpp")
    set( EXTRA_SOURCES "src/key-file.cpp" )
endif ()

# Premium-calculator app (with advanced functionality)
add_executable( PremiumCalculator "src/main.cpp"
                                  ${EXTRA_SOURCES} )
target_link_libraries( PremiumCalculator extmath )

# Both targets require "Boost.Program_Options".
include_directories( SYSTEM "${Boost_INCLUDE_DIRS}" )
target_link_libraries( FreeCalculator ${Boost_LIBRARIES} )
target_link_libraries( PremiumCalculator
                                      ${Boost_LIBRARIES} )
# Both targets require the include-path to their direct
# dependency 'basicmath'/'extmath' and indirect dependency
# "Boost.Outcome".
include_directories( "../library/include" )  # This is ugly!
include_directories( SYSTEM
            "$<TARGET_PROPERTY:Boost::outcome,MY_INCLUDE_DIRS>" )

