#include <iostream>

#include "boost/program_options.hpp"
#include "Math.h"
#include "MathAPI.h"

namespace po = boost::program_options;

int main(int argc, char** argv)
{
    // Prepare command-line options.
    po::options_description desc( "prog [--version]" );
    desc.add_options()
        ( "help,h", "Display this information." )
        ( "version,v", "Display program version information.\n" );

    // Parse command line for program options.
    po::variables_map opts;
    try
    {
        po::store( parse_command_line( argc, argv, desc ), opts );
        po::notify( opts );
    }
    catch ( const po::unknown_option& exc )
    {
        std::cerr << "Unable to parse command line options: " << exc.what() << "\n\n" << desc << std::endl;
        return 1;
    }

    // Print usage?
    if ( opts.count( "help" ) || !opts.count( "input" ) )
    {
        std::cout << desc << std::endl;
        return 0;
    }

    // Print version?
    if ( opts.count( "version" ) )
    {
        std::cout << " Version  - 0.0.1" << std::endl;
        return 0;
    }

    // Normal behavior?
    outcome::result<int> returnVal = convert("Hallo Welt");
    std::cout << "convert-result: " << returnVal.value() << std::endl;


    return 0;
}
