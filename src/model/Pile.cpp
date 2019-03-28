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

