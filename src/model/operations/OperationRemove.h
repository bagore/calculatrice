#ifndef OPERATIONREMOVE_H
#define OPERATIONREMOVE_H

/* Inherited classes */
#include "AbstractOperation.h"

/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   OperationRemove
        :   public  AbstractOperation
{
public:

    OperationRemove(void);


    virtual double  operation(const std::vector<double> pOperandsList);



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< OPERATIONREMOVE_H */
