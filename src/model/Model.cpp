/* Corresponding header inclusion */
#include "Model.h"

/* System includes */
#include <algorithm>

/* Libraries includes */

/* Project includes */
#include "operations/OperationAdd.h"
#include "operations/OperationDivide.h"
#include "operations/OperationMultiply.h"
#include "operations/OperationRemove.h"


/* ########################################################################## */
/* ########################################################################## */

Model::Model(void)
    :   m_operands( std::make_shared<Pile>() )
{
    this->m_operationsList.push_back( std::make_shared<OperationAdd>() );
    this->m_operationsList.push_back( std::make_shared<OperationDivide>() );
    this->m_operationsList.push_back( std::make_shared<OperationMultiply>() );
    this->m_operationsList.push_back( std::make_shared<OperationRemove>() );
}

/* ########################################################################## */
/* ########################################################################## */

std::shared_ptr<AbstractOperation>
        Model::operation(const std::string &pOperationID)
{
    std::shared_ptr<AbstractOperation>  retval;


    for(auto const& lValue: this->m_operationsList )
    {
        if( lValue.get()->identifier() == pOperationID )
        {
            retval  = lValue;
        }
    }

    if( ! retval )
    {
        throw   std::logic_error( std::string( __PRETTY_FUNCTION__ )
                                  + " :: Can't find operation '"
                                  + pOperationID + "' !" );
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

std::shared_ptr<Pile>   Model::operandes(void)
{
    return this->m_operands;
}

/* ########################################################################## */
/* ########################################################################## */
