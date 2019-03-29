#include "Pile.h"


Pile::Pile()//Définition du constructeur
{

}

void Pile::empiler(const double &inValue)
{
    this-> m_pile.push(inValue);
}

size_t Pile::nombreElements() const
{
    return this->m_pile.size();
}

double Pile::depiler()
{
    if( this->m_pile.empty() )
    {
        throw   std::runtime_error( std::string(__PRETTY_FUNCTION__)
                                    + " :\nOperands stack is empty !" );
    }

    double toto =0;
    toto = this->m_pile.top();
    this->m_pile.pop();
    return toto;
}

void Pile::vider()
{
    while(this->m_pile.empty() == false)
    {
        this->m_pile.pop();
    }
}

bool Pile::estVide()const
{
    return this->m_pile.empty();
}

std::stack<double> Pile::getClonePile(){
    std::stack<double> clonePile = this->m_pile; // = operator is sucharged in order to clone
    return clonePile;
}
