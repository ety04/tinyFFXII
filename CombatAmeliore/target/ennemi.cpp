#include "ennemi.h"

using namespace std;

Ennemi::Ennemi()
{
    agressif = true;
}

Ennemi::Ennemi(QString nom) :
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

QString& Ennemi::getButin()
{
    return butin;
}

void Ennemi::setButin(const QString& value)
{
    butin = value;
}

QString& Ennemi::getActionPrincipale()
{
    return actionPrincipale;
}

void Ennemi::setActionPrincipale(const QString &value)
{
    actionPrincipale = value;
}

QString Ennemi::getCri()
{
    return cri;
}

void Ennemi::setCri(const QString &value)
{
    cri = value;
}

unsigned int Ennemi::getExpDonnee()
{
    return expDonnee;
}

void Ennemi::setExpDonnee(unsigned int value)
{
    expDonnee = value;
}
