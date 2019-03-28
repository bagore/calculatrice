#ifndef MEMORY_H
#define MEMORY_H

/* Inherited classes */


/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   Memory
{
public:

    Memory(void);


    void    clear(void);

    void    add(const double& pValueToAdd);
    double  value(void) const;



protected:
private:



public:
protected:
private:

    double  m_value;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MEMORY_H */
