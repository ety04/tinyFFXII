#ifndef BALTHIER_H
#define BALTHIER_H

#include <string>

#include "allie.h"
#include "equip/fusilliste.h"

class Balthier : public Allie
{
public:
    Balthier();
    const Fusil *getFusil() const;

private:
    FusilListe fl;
    const Fusil* f;

public slots:
    void setFusil(QString &nomFusil);
};

#endif // BALTHIER_H
