#include "fusil.h"

using namespace std;

Fusil::Fusil()
{

}

Fusil::Fusil(string nom) :
    Arme(nom)
{

}

Fusil::Fusil(string nom, unsigned int att) :
    Arme(nom, att)
{

}

double Fusil::getCritique() const
{
    return critique;
}

unsigned int Fusil::getParade() const
{
    return parade;
}
