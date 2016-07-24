#include "ennemi.h"

using namespace std;

Ennemi::Ennemi() :
    Cible()
{
    agressif = true;
    cri = "";
    butin = QObject::tr("Caillou");
    expDonnee = 0;
    actionPrincipale = QObject::tr("Charge");
}

Ennemi::Ennemi(QString nom) :
    Cible(nom)
{
    agressif = true;
    cri = "";
    butin = QObject::tr("Caillou");
    expDonnee = 0;
    actionPrincipale = QObject::tr("Charge");
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

Element Ennemi::getFaiblesse()
{
    return faiblesse;
}

void Ennemi::setFaiblesse(const Element &value)
{
    faiblesse = value;
}

QString Ennemi::getLienImage()
{
    return lienImage;
}

void Ennemi::setLienImage(const QString &value)
{
    lienImage = value;
}

QString Ennemi::getId()
{
    return id;
}

void Ennemi::setId(const QString &value)
{
    id = value;
}
