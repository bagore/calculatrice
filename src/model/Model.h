#ifndef MODEL_H
#define MODEL_H

/* Inherited classes */


/* System includes */
#include <memory>
#include <string>
#include <vector>

/* Libraries includes */

/* Project includes */
#include "CurrentEntry.h"
#include "Memory.h"
#include "operations/AbstractOperation.h"
#include "Pile.h"

/* ########################################################################## */
/* ########################################################################## */

class   Model
{
public:

    Model(void);


    std::shared_ptr<CurrentEntry>   currentEntry(void);


    std::shared_ptr<AbstractOperation>
            operation(const std::string& pOperationID);


    std::shared_ptr<Pile>   operandes(void);


    std::shared_ptr<Memory> memoire(void);



protected:
private:



public:
protected:
private:

    std::shared_ptr<CurrentEntry>                       m_currentEntry;
    std::shared_ptr<Memory>                             m_memory;
    std::vector<std::shared_ptr<AbstractOperation>>     m_operationsList;
    std::shared_ptr<Pile>                               m_operands;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MODEL_H */
