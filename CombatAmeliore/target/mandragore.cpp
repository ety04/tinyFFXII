#include "mandragore.h"

using namespace std;

Mandragore::Mandragore() :
    Ennemi(QObject::tr("Mandragore"))
{
    setId("mandragore");
    setNiveau(aleatoireInt(34, 37));
    setPVmax(aleatoireInt(2739, 3099)); setPV(getPVmax());
    setPMmax(999); setPM(getPMmax());

    setStat("attaque", aleatoireInt(47, 53));
    setStat("défense", aleatoireInt(19, 25));
    setStat("défense magique", aleatoireInt(26, 29));
    setStat("parade", 7);
    setStat("force", aleatoireInt(28, 31));
    setStat("magie", aleatoireInt(23, 29));
    setStat("vigueur", aleatoireInt(48, 57));
    setStat("vitesse", 21);

    setActionPrincipale(QObject::tr("Charge"));
    setCri("niark niark");
    setFaiblesse(feu);
    setExpDonnee(aleatoireInt(607, 919));
    setButin(QObject::tr("Fruit succulent"));
    setLienImage(":/images/monstres/mandragore.png");

    cout << "EXPERIENCE DE LA MANDRAGORE: " << getExpDonnee() << endl;
}

