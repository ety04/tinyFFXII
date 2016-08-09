#include "equipement.h"

using namespace std;

Equipement::Equipement()
{

}

Equipement::Equipement(QString nom)
{
    this->nom = nom;
}

QString Equipement::getNom() const
{
    return nom;
}
