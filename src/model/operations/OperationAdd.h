#ifndef OPERATIONADD_H
#define OPERATIONADD_H

/* Inherited classes */
#include "AbstractOperation.h"

/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   OperationAdd
        :   public  AbstractOperation
{
public:

    OperationAdd(void);


    virtual double  operation(const std::vector<double> pOperandsList);



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< OPERATIONADD_H */
