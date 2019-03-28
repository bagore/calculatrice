/* Corresponding header inclusion */

/* System includes */
#include <vector>

/* Libraries includes */
#include "test/catch.hpp"

/* Project includes */
#include "model/Memory.h"


/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "Memory class" )
{
    GIVEN( "A default object" )
    {
        Memory  lMemory;
        THEN( "Its default value is 0" )
        {
            REQUIRE( lMemory.value() == 0 );
        }


        WHEN( "We add a value to it" )
        {
            double  lValueAdded = 42;
            lMemory.add( lValueAdded );

            THEN( "Its content is conform" )
            {
                REQUIRE( lMemory.value() == lValueAdded );
            }


            AND_WHEN( "we clear the value" )
            {
                lMemory.clear();

                THEN( "Its value is 0" )
                {
                    REQUIRE( lMemory.value() == 0 );
                }
            }
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */
