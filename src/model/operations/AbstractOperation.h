#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H

/* Inherited classes */


/* System includes */
#include <string>
#include <vector>

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   AbstractOperation
{
public:

    AbstractOperation(const std::string& pOperationIdentifer);


    std::string     identifier(void) const;


    virtual double  operation(const std::vector<double> pOperandsList)  = 0;



protected:
private:

    AbstractOperation(void)                 = delete;
    AbstractOperation(AbstractOperation&)   = delete;



public:
protected:
private:

    const std::string   m_operationIdentifer;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< ABSTRACTOPERATION_H */
