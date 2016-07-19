#ifndef ALLIE_H
#define ALLIE_H

#include "cible.h"


class Allie : public Cible
{
public:
    Allie();
    Allie(std::string nom);

private:
    bool mysteFull;
    std::vector<Equipement> equipement;
    unsigned int exp;
};

#endif // ALLIE_H
