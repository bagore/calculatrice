#ifndef CURRENTENTRY_H
#define CURRENTENTRY_H

/* Inherited classes */

/* System includes */
#include <vector>

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   CurrentEntry
{
public:

    CurrentEntry(void);


    void    addChar(const char pChar);
    void    removeChar(void);

    double  value(void) const;

    void    clear(void);



protected:
private:



public:
protected:
private:

    std::vector<char>   m_vectorInt;
    std::vector<char>   m_vectorDecimal;
    bool                m_hasDecimal;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CURRENTENTRY_H */
