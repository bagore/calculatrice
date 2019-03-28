/* Corresponding header inclusion */
#include "AbstractOperation.h"

/* System includes */

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

AbstractOperation::AbstractOperation(const std::string &pOperationIdentifer)
    :   m_operationIdentifer( pOperationIdentifer )
{

}

/* ########################################################################## */
/* ########################################################################## */

std::string AbstractOperation::identifier(void) const
{
    return this->m_operationIdentifer;
}

/* ########################################################################## */
/* ########################################################################## */
