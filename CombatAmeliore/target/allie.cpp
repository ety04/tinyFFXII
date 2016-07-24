#include "allie.h"

using namespace std;

Allie::Allie() :
    Cible()
{

}

Allie::Allie(QString nom) :
    Cible(nom)
{
}

bool Allie::getMysteFull()
{
    return mysteFull;
}

void Allie::setMysteFull(bool value)
{
    mysteFull = value;
}

std::vector<Equipement> Allie::getEquipement()
{
    return equipement;
}

void Allie::setEquipement(const std::vector<Equipement> &value)
{
    equipement = value;
}

std::vector<QString> Allie::getButins()
{
    return butins;
}

void Allie::setButins(const std::vector<QString> &value)
{
    butins = value;
}

void Allie::addButin(QString& butin)
{
    butins.push_back(butin);
}

unsigned int Allie::getExp()
{
    return exp;
}

void Allie::setExp(unsigned int value)
{
    exp = value;
}

void Allie::addExp(unsigned int value)
{
    exp += value;
}
