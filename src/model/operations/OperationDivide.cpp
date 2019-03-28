/* Corresponding header inclusion */
#include "OperationDivide.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

OperationDivide::OperationDivide(void)
    :   AbstractOperation( "/" )
{

}

/* ########################################################################## */
/* ########################################################################## */

double  OperationDivide::operation(const std::vector<double> pOperandsList)
{
    if( pOperandsList.size() != 2 )
    {
        throw   std::range_error( std::string( __PRETTY_FUNCTION__ )
                                  + "::Expects 2 arguments, "
                                  + std::to_string( pOperandsList.size())
                                  + " given!" );
    }

    /* Refuse to divide by zero */
    if( pOperandsList.at(1) == 0 )
    {
        throw   std::range_error( std::string( __PRETTY_FUNCTION__ )
                                  + "::I refuse to divide by zero! " );
    }


    return  (   pOperandsList.at(0)
            /   pOperandsList.at(1) );
}

/* ########################################################################## */
/* ########################################################################## */
