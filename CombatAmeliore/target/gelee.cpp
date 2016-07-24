#include "gelee.h"

Gelee::Gelee() :
    Ennemi(QObject::tr("Gelée"))
{
    setId("gelee");
    setNiveau(aleatoireInt(24, 25));
    setPVmax(aleatoireInt(1913, 2018)); setPV(getPVmax());
    setPMmax(aleatoireInt(810, 850)); setPM(getPMmax());

    setStat("attaque", aleatoireInt(31, 33));
    setStat("défense", aleatoireInt(28, 31));
    setStat("défense magique", aleatoireInt(10, 12));
    setStat("parade", 0);
    setStat("force", aleatoireInt(27, 28));
    setStat("magie", aleatoireInt(18, 20));
    setStat("vigueur", aleatoireInt(32, 33));
    setStat("vitesse", 14);

    setActionPrincipale(QObject::tr("Baffes"));
    setCri("Blob");
    setFaiblesse(feu);
    setExpDonnee(aleatoireInt(1104, 1213));
    setButin(QObject::tr("Liquide jaune"));
    setLienImage(":/images/monstres/gelee.png");
}
