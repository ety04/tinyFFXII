#include "balthier.h"

using namespace std;

Balthier::Balthier() :
    Allie("Balthier")
{
    setNiveau(40);
    setPVmax(1753);
    setPV(PVmax);
    setPMmax(120);
    setPM(PMmax);
    setStat("force", 44);
    setStat("magie", 32);
    setStat("vigueur", 38);
    setStat("vitesse", 29);

    QString nom("arcturus");
    setFusil(nom);
}

void Balthier::setFusil(QString& nomFusil)
{
    f = fl.getFusils().at(nomFusil);
    setStat("attaque", f->getAttaque());
    setStat("parade", getStat("parade") + f->getParade());
}

const Fusil* Balthier::getFusil() const
{
    return f;
}
