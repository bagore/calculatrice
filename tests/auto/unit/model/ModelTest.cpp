/* Corresponding header inclusion */

/* System includes */
#include <vector>

/* Libraries includes */
#include "test/catch.hpp"

/* Project includes */
#include "model/Model.h"


/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "Model interface - Operations list" )
{
    GIVEN( "The model" )
    {
        Model   lModel;

        THEN( "The model contains operations" )
        {
            REQUIRE_THROWS( lModel.operation( "<invalid operation ID>" ) );
            REQUIRE_NOTHROW( lModel.operation( "+" ) );
            REQUIRE_NOTHROW( lModel.operation( "-" ) );
            REQUIRE_NOTHROW( lModel.operation( "x" ) );
            REQUIRE_NOTHROW( lModel.operation( "/" ) );
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "Model interface -Operands list" )
{
    Model   lModel;

    REQUIRE( lModel.operandes().get()->nombreElements() == 0 );
}

/* ########################################################################## */
/* ########################################################################## */
