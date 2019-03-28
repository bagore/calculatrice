#ifndef OPERATIONMULTIPLY_H
#define OPERATIONMULTIPLY_H

/* Inherited classes */
#include "AbstractOperation.h"

/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   OperationMultiply
        :   public  AbstractOperation
{
public:

    OperationMultiply(void);


    virtual double  operation(const std::vector<double> pOperandsList);



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< OPERATIONMULTIPLY_H */
