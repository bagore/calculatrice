#ifndef  PILE_H
#define  PILE_H
#include <iostream>
#include <stack>


/* ------------- Declaration de la classe Pile ----------- */



class Pile
{
    /* Declaration des membres privés */
    std::stack<double> m_pile;

public:

    Pile(); //Constructeur par defaut
    void empiler(const double &inValue);
    double depiler();
    void vider();
    size_t nombreElements() const;
    bool estVide() const;
};

#endif