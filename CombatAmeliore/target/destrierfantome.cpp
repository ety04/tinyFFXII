#include "destrierfantome.h"

DestrierFantome::DestrierFantome() :
    Ennemi(QObject::tr("Destrier fantôme"))
{
    setId("destrier_fantome");
    setNiveau(aleatoireInt(45, 48));
    setPVmax(aleatoireInt(10135, 11095)); setPV(getPVmax());
    setPMmax(aleatoireInt(630, 720)); setPM(getPMmax());

    setStat("attaque", aleatoireInt(64, 70));
    setStat("défense", aleatoireInt(28, 31));
    setStat("défense magique", aleatoireInt(32, 38));
    setStat("parade", 0);
    setStat("force", aleatoireInt(34, 43));
    setStat("magie", 19);
    setStat("vigueur", aleatoireInt(55, 58));
    setStat("vitesse", aleatoireInt(22, 28));

    setActionPrincipale(QObject::tr("Ruade"));
    setCri("Huuuuuuuuuuu!");
    setFaiblesse(lumiere);
    setExpDonnee(aleatoireInt(3047, 3569));
    setButin(QObject::tr("Parure de monture"));
    setLienImage(":/images/monstres/destrier_fantome.png");
}
