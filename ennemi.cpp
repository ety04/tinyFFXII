#include "ennemi.h"

using namespace std;

Ennemi::Ennemi()
{
    agressif = true;
}

Ennemi::Ennemi(string nom) :
    Cible(nom)
{
    agressif = true;
}

bool Ennemi::getAgressif() const
{
    return agressif;
}

void Ennemi::setAgressif(bool value)
{
    agressif = value;
}

std::string Ennemi::getButin() const
{
    return butin;
}

void Ennemi::setButin(const std::string &value)
{
    butin = value;
}
