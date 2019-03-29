/* Corresponding header inclusion */
#include "CurrentEntry.h"

/* System includes */
#include <math.h>
#include <stdexcept>

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

CurrentEntry::CurrentEntry(void)
    :   m_hasDecimal( false )
{

}

/* ########################################################################## */
/* ########################################################################## */

void    CurrentEntry::addChar(const char pChar)
{
    if(     ( pChar < '0' || pChar > '9')
        &&  pChar != ',' )
    {
        throw std::range_error( std::string( __PRETTY_FUNCTION__ )
                                + " :: Unexpected char '" + pChar + "' !" );
    }
    else if( this->m_hasDecimal )
    {
        if( pChar == ',' )
        {
            throw std::runtime_error( std::string( __PRETTY_FUNCTION__ )
                                      + " :: Already received decimal"
                                        " separator." );
        }

        this->m_vectorDecimal.push_back( pChar );
    }
    else if( pChar == ',' )
    {
        this->m_hasDecimal  = true;
    }
    else
    {
        this->m_vectorInt.push_back( pChar );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    CurrentEntry::clear(void)
{
    this->m_hasDecimal  = false;
    this->m_vectorDecimal.clear();
    this->m_vectorInt.clear();
}

/* ########################################################################## */
/* ########################################################################## */

void    CurrentEntry::removeChar(void)
{
    if( ! this->m_vectorDecimal.empty() )
    {
        this->m_vectorDecimal.pop_back();
    }
    else if( this->m_hasDecimal )
    {
        this->m_hasDecimal  = false;
    }
    else if( ! this->m_vectorInt.empty() )
    {
        this->m_vectorInt.pop_back();
    }
    else
    {
        throw std::runtime_error( std::string( __PRETTY_FUNCTION__ )
                                  + " :: No more char to remove." );
    }
}

/* ########################################################################## */
/* ########################################################################## */

double  CurrentEntry::value(void) const
{
    double  retval  = 0;


    for( size_t i = 0 ; i < this->m_vectorInt.size() ; ++i )
    {
        retval  *= 10;
        retval  += (this->m_vectorInt.at( i ) - '0');
    }


    for( size_t i = 0 ; i < this->m_vectorDecimal.size() ; ++i )
    {
        retval  += (    ( this->m_vectorDecimal.at( i ) - '0' )
                   *    pow( 0.1, (i+1) ) );
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */
