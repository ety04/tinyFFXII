#include "apparition.h"

Apparition::Apparition() :
    Ennemi(QObject::tr("Apparition"))
{
   setId("apparition");
   setNiveau(9);
   setPVmax(5146); setPV(getPVmax());
   setPMmax(600); setPM(getPMmax());

   setStat("attaque", 20);
   setStat("défense", 7);
   setStat("défense magique", 10);
   setStat("parade", 1);
   setStat("force", 18);
   setStat("magie", 13);
   setStat("vigueur", 33);
   setStat("vitesse", 15);

   setActionPrincipale(QObject::tr("Glas"));
   setCri(QObject::tr("BOOOOOOOOOOOOOOOOOUH!"));
   setLienImage(":/images/monstres/wraith_apparition.png");
}
