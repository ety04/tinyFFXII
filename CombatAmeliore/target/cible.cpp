
#include "cible.h"

using namespace std;

Cible::Cible()
{
	
}

Cible::Cible(QString nom)
{
    this->nom = nom;
    this->PV = PVmax;
    this->PM = PMmax;

    etat = {

        // Altérations d'état négatives

             {"inconnu", false},
             {"coma", false},
             {"pierre", false},
             {"sclérose", false},
             {"stop", false},
             {"glas", false},
             {"confusion", false},
             {"sommeil", false},
             {"virus", false},
             {"paradoxe", false},
             {"lenteur", false},
             {"inaction", false},
             {"inertie", false},
             {"silence", false},
             {"cécité", false},
             {"poison", false},
             {"huile", false},
             {"nécrose", false},
             {"danger", false},

        // Altérations d'état positives

             {"leurre", false},
             {"miroir", false},
             {"bouclier", false},
             {"barrière", false},
             {"célérité", false},
             {"bravoure", false},
             {"foi", false},
             {"invisible", false},
             {"regain", false},
             {"lévitation", false},
             {"furie", false},
             {"vitalité", false},
             {"acuité", false}

           };

    stats =
    {
        { "attaque", 11 },
        { "défense", 0 },
        { "défense magique", 0 },
        { "parade", 0 },
        { "parade magique", 0 },
        { "force", 0 },
        { "magie", 0 },
        { "vigueur", 0 },
        { "vitesse", 0}
    };


}

QString& Cible::getNom()
{
    return nom;
}

void Cible::setNom(const QString& value)
{
    nom = value;
}

unsigned int Cible::getNiveau() const
{
    return niveau;
}

void Cible::setNiveau(unsigned int value)
{
    niveau = value;
}

unsigned int Cible::getPVmax() const
{
    return PVmax;
}

void Cible::setPVmax(unsigned int value)
{
    PVmax = value;
}

unsigned int Cible::getPMmax() const
{
    return PMmax;
}

void Cible::setPMmax(unsigned int value)
{
    PMmax = value;
}

unsigned int Cible::getPV() const
{
    return PV;
}

void Cible::setPV(unsigned int value)
{
    PV = value;
}

unsigned int Cible::getPM() const
{
    return PM;
}

void Cible::setPM(unsigned int value)
{
    PM = value;
}

std::map<std::string, bool> Cible::getEtat() const
{
    return etat;
}

bool Cible::getEtat(std::string etat)
{
    return this->etat[etat];
}

void Cible::setEtat(const std::map<std::string, bool> &value)
{
    etat = value;
}

void Cible::setEtat(std::string etat, bool value)
{
    this->etat[etat] = value;
}

std::map<std::string, unsigned int> Cible::getStats() const
{
    return stats;
}

unsigned int Cible::getStat(string stat)
{
    return this->stats[stat];
}

void Cible::setStats(const std::map<std::string, unsigned int> &value)
{
    stats = value;
}

void Cible::setStat(std::string stat, unsigned int value)
{
    this->stats[stat] = value;
}
