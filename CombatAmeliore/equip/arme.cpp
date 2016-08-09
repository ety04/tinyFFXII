#include "arme.h"

using namespace std;

Arme::Arme() :
    Equipement()
{
    attaque = 0;
    element = (Element) NULL;
}

Arme::Arme(QString nom) :
    Equipement(nom)
{

}

Arme::Arme(QString nom, unsigned int att) :
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
