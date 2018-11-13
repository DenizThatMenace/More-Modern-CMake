# ./external/boost/CMakeLists.txt -- More Modern CMake

set( BOOST_VERSION 1.58.1 )

# Settings for finding correct Boost libraries.
set( Boost_USE_STATIC_LIBS      FALSE )
set( Boost_USE_MULTITHREADED    TRUE )
set( Boost_USE_STATIC_RUNTIME   FALSE )
set( Boost_ADDITIONAL_VERSIONS  "${BOOST_VERSION}" )
set( Boost_COMPILER             "-gcc" )

# Search for Boost libraries.
find_package( Boost ${BOOST_VERSION} EXACT REQUIRED
    COMPONENTS program_options
               graph )

# Make found targets globally available.
if ( Boost_FOUND )
    set_target_properties( Boost::boost
                           Boost::program_options
                           Boost::graph
        PROPERTIES IMPORTED_GLOBAL TRUE )
endif ()
