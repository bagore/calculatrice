/* Corresponding header inclusion */

/* System includes */
#include <vector>

/* Libraries includes */
#include "test/catch.hpp"

/* Project includes */
#include "model/operations/OperationRemove.h"


/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "OperationRemove" )
{
    OperationRemove    lOperationRemove;

    GIVEN( "An object" )
    {
        THEN( "Its operation identifier is the expected one" )
        {
            REQUIRE( lOperationRemove.identifier() == "-" );
        }
    }

    WHEN( "Giving not enough arguments" )
    {
        std::vector<double> lArguments;
        lArguments.push_back( 1 );


        THEN( "Operation fails and throws an exception" )
        {
            REQUIRE_THROWS( lOperationRemove.operation( lArguments ) );
        }
    }

    WHEN( "Giving too many arguments" )
    {
        std::vector<double> lArguments;
        lArguments.push_back( 1 );
        lArguments.push_back( 2 );
        lArguments.push_back( 3 );


        THEN( "Operation fails and throws an exception" )
        {
            REQUIRE_THROWS( lOperationRemove.operation( lArguments ) );
        }
    }

    WHEN( "Giving the right arguments count" )
    {
        std::vector<double> lArguments;
        lArguments.push_back( 1 );
        lArguments.push_back( 2 );

        const double c_expectedResult   = -1;


        THEN( "Operation succeds and returns a valid result" )
        {
            double lResult  = 0;
            REQUIRE_NOTHROW( lResult = lOperationRemove.operation( lArguments ) );

            REQUIRE( lResult == c_expectedResult );
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */
