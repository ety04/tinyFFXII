#include "poulatrice.h"

Poulatrice::Poulatrice() :
    Ennemi(QObject::tr("Poulatrice"))
{
    setId("poulatrice");
    setNiveau(15);
    setPVmax(7509); setPV(getPVmax());
    setPMmax(563); setPM(getPMmax());

    setStat("attaque", 25);
    setStat("défense", 5);
    setStat("défense magique", 8);
    setStat("parade", 0);
    setStat("force", 19);
    setStat("magie", 17);
    setStat("vigueur", 34);
    setStat("vitesse", 14);

    setActionPrincipale(QObject::tr("Coups de bec"));
    setCri("Cot cot cot!");
    setFaiblesse(terre);
    setLienImage(":/images/monstres/poulatrice.png");
}
