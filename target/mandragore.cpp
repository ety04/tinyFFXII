#include "mandragore.h"

using namespace std;

Mandragore::Mandragore() :
    Ennemi("Mandragore")
{
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

    setExpDonnee(aleatoireInt(607, 919));
    setButin("Fruit succulent");
    setActionPrincipale("Charge");
    setCri("niark niark");

    cout << "EXPERIENCE DE LA MANDRAGORE: " << getExpDonnee() << endl;
}

unsigned int Mandragore::aleatoireInt(unsigned int min, unsigned int max)
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(min, max);

    return distr(eng);
}

