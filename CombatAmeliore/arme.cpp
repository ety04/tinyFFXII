#include "arme.h"

using namespace std;

Arme::Arme()
{
    attaque = 0;
    element = (Element) NULL;
}

Arme::Arme(string nom) :
    Equipement(nom)
{

}

Arme::Arme(string nom, unsigned int att) :
    Equipement(nom)
{
    attaque = att;
}

unsigned int Arme::getAttaque() const
{
    return attaque;
}

void Arme::setAttaque(unsigned int value)
{
    attaque = value;
}
