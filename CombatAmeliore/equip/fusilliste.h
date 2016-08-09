#ifndef FUSILLISTE_H
#define FUSILLISTE_H

#include "fusil.h"
#include <map>
#include <QString>

class FusilListe
{
public:
    FusilListe();
    std::map<QString, const Fusil *> getFusils() const;
    QString donneCle(const Fusil *valeur);

private:
    const Fusil* altair = new Fusil("Altaïr", 6);
    const Fusil* capella = new Fusil("Capella", 10);
    const Fusil* vega = new Fusil("Véga", 14);
    const Fusil* sirius = new Fusil("Sirius", 18);
    const Fusil* betelgeuse = new Fusil("Bételgeuse", 22);
    const Fusil* ras_algethi = new Fusil("Ras Algethi", 26);
    const Fusil* aldebaran = new Fusil("Aldébaran", 30);
    const Fusil* spica = new Fusil("Spica", 34);
    const Fusil* antares = new Fusil("Antarès", 39);
    const Fusil* arcturus = new Fusil("Arcturus", 44);
    const Fusil* fomalhaut = new Fusil("Fomalhaut", 50);

    std::map<QString, const Fusil*> fusils;

};

#endif // FUSILLISTE_H
