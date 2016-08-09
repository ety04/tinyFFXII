#include "fusilliste.h"

using namespace std;

FusilListe::FusilListe()
{
    fusils["altair"] = altair;
    fusils["capella"] = capella;
    fusils["vega"] = vega;
    fusils["sirius"] = sirius;
    fusils["betelgeuse"] = betelgeuse;
    fusils["ras_algethi"] = ras_algethi;
    fusils["aldebaran"] = aldebaran;
    fusils["spica"] = spica;
    fusils["antares"] = antares;
    fusils["arcturus"] = arcturus;
    fusils["fomalhaut"] = fomalhaut;
}


map<QString, const Fusil *> FusilListe::getFusils() const
{
    return fusils;
}

/** Cette méthode renvoie la clé de l'entrée de la map ayant pour valeur le Fusil en paramètre */
QString FusilListe::donneCle(const Fusil* valeur)
{
    QString cle = "";
    map<QString, const Fusil*>::const_iterator it = fusils.begin();
    while(it != fusils.end())
    {
        if (*(it->second) == *valeur)
        {
            cle = it->first;
        }
        ++it;
    }
    return cle;
}
