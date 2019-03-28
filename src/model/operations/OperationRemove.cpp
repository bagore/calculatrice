/* Corresponding header inclusion */
#include "OperationRemove.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

OperationRemove::OperationRemove(void)
    :   AbstractOperation( "-" )
{

}

/* ########################################################################## */
/* ########################################################################## */

double  OperationRemove::operation(const std::vector<double> pOperandsList)
{
    if( pOperandsList.size() != 2 )
    {
        throw   std::range_error( std::string( __PRETTY_FUNCTION__ )
                                  + "::Expects 2 arguments, "
                                  + std::to_string( pOperandsList.size())
                                  + " given!" );
    }


    return  (   pOperandsList.at(0)
            -   pOperandsList.at(1) );
}

/* ########################################################################## */
/* ########################################################################## */
