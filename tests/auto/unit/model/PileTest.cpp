/* Corresponding header inclusion */

/* System includes */
#include <vector>

/* Libraries includes */
#include "test/catch.hpp"

/* Project includes */
#include "model/Pile.hpp"
/*
Le but de ce fichier est de tester les 5 fonctions de ma classe Pile si la classe pile ne fonctionne pas il faudra penser à les changer.
le premier test case verifiera les méthodes empiler et depiler
le second verifiera nombreElements, vider et estVide.
*/
/* ########################################################################## */

TEST_CASE( "Empiler & Depiler" ) // Test case verification de Empiler et Depiler
{

Pile maPile;//Création de maPile une classe de type Pile

double NombreEmpile = 13; // initialisation du nombre qui sera stocké dans la pile

maPile.empiler(NombreEmpile); //Stockage du nombre dans la Pile

double verifNumber =0; // On initialise un nombre à 0 il servira à verifier qu'on récupere bien le nombre 13

verifNumber= maPile.depiler();


    GIVEN( "Empiler et Depiler un nombre dans une .... Pile " ) //Si je donne un nombre
    {
        THEN( "Copier le nombre dans une variable locale" )
        {
            REQUIRE( verifNumber == 13 );
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "NbElement, Vider, estVide" ) //on testera ici si on récupère le bon nombre d'element
{                                        //on testera aussi si on peut vider et verifier que la pile soit vide

    Pile maPile;//Création de maPile une classe de type Pile
    double Nombre1 = 1;
    double Nombre2 = 2;
    maPile.empiler(Nombre1); //Stockage du nombre dans la Pile
    size_t nbElements= 0;//initialisation de la variable qui contiendra le nombre d'elements
    nbElements = maPile.nombreElements();

    REQUIRE(nbElements == 1); // Test si la methode nombreElements retourne le bon nombre d'elements dans la pile
    maPile.empiler(Nombre2);
    nbElements = maPile.nombreElements();

    REQUIRE(nbElements == 2); // test une nouvelle fois
    bool pileVide= true; //j'initialise la var qui contiendra la valeur retourner par la methode estVide (true = pile vide)
    pileVide= maPile.estVide(); //la pile n'étant pas vide la variable doit passer à l'état false.

    REQUIRE(pileVide == false);

    maPile.vider();// je vide la pile

    pileVide= maPile.estVide(); // Doit passer à l'état true après vidage de la pile.

      REQUIRE(pileVide == true);
}

