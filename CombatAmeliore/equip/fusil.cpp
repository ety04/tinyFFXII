#include "fusil.h"

using namespace std;

Fusil::Fusil() :
    Arme()
{

}

Fusil::Fusil(QString nom) :
    Arme(nom)
{

}

Fusil::Fusil(QString nom, unsigned int att) :
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

bool operator ==(const Fusil &f1, const Fusil &f2)
{
    if(!f2.getNom().isEmpty())
    {
        return (f1.getNom() == f2.getNom() && f1.getAttaque() == f2.getAttaque());
    }
    else
    {
        cout << "/!\\ Le deuxième fusil n'a pas de nom!!" << endl;
        return false;
    }
}
