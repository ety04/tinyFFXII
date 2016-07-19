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

    Fusil* arcturus = new Fusil("Arcturus", 44);
    setStat("attaque", arcturus->getAttaque());
    setStat("parade", getStat("parade") + arcturus->getParade());
}
