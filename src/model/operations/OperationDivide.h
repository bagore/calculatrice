#ifndef OPERATIONDIVIDE_H
#define OPERATIONDIVIDE_H

/* Inherited classes */
#include "AbstractOperation.h"

/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   OperationDivide
        :   public  AbstractOperation
{
public:

    OperationDivide(void);


    virtual double  operation(const std::vector<double> pOperandsList);



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< OPERATIONDIVIDE_H */
