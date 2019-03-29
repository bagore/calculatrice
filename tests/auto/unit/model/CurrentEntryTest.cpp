/* Corresponding header inclusion */

/* System includes */
#include <vector>

/* Libraries includes */
#include "test/catch.hpp"

/* Project includes */
#include "model/CurrentEntry.h"


/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "CurrentEntry class" )
{
    GIVEN( "A default object" )
    {
        CurrentEntry  lCE;
        THEN( "Its default value is 0" )
        {
            REQUIRE( lCE.value() == 0 );
        }


        WHEN( "We add a few chars to it (integer value)" )
        {
            lCE.addChar( '1' );
            lCE.addChar( '2' );
            lCE.addChar( '3' );

            THEN( "Its content is conform" )
            {
                REQUIRE( lCE.value() == 123 );
            }

            AND_THEN( "If we do a clear" )
            {
                lCE.clear();

                THEN( "Its value is null" )
                {
                    REQUIRE( lCE.value() == 0 );
                }
            }
        }


        WHEN( "We add a few chars to it (decimal value)" )
        {
            lCE.addChar( '1' );
            lCE.addChar( '2' );
            lCE.addChar( '3' );
            lCE.addChar( ',' );
            lCE.addChar( '4' );
            lCE.addChar( '5' );
            lCE.addChar( '6' );

            THEN( "Its content is conform" )
            {
                REQUIRE( lCE.value() == 123.456 );
            }

            AND_WHEN( "We delete a few chars" )
            {
                lCE.removeChar();
                lCE.removeChar();
                lCE.removeChar();
                lCE.removeChar();
                lCE.removeChar();

                THEN( "Its content is conform" )
                {
                    REQUIRE( lCE.value() == 12 );
                }
            }
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */
