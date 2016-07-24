#include "treant.h"

Treant::Treant() :
    Ennemi(QObject::tr("Tréant"))
{
    setId("treant");
    setNiveau(aleatoireInt(23, 26));
    setPVmax(aleatoireInt(4274, 4874)); setPV(getPVmax());
    setPMmax(aleatoireInt(504, 760)); setPM(getPMmax());

    setStat("attaque", aleatoireInt(28, 34));
    setStat("défense", aleatoireInt(18, 20));
    setStat("défense magique", aleatoireInt(16, 17));
    setStat("parade", 0);
    setStat("force", aleatoireInt(23, 27));
    setStat("magie", aleatoireInt(13, 17));
    setStat("vigueur", aleatoireInt(24, 29));
    setStat("vitesse", aleatoireInt(14, 15));

    setActionPrincipale(QObject::tr("Charge"));
    setCri(QObject::tr("Boum"));
    setFaiblesse(air);
    setExpDonnee(aleatoireInt(327, 1242));
    setButin(QObject::tr("Rondin"));
    setLienImage(":/images/monstres/treant.png");
}
