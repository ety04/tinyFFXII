#ifndef SYSTEME_H
#define SYSTEME_H

#include "target/cible.h"
#include "target/allie.h"
#include "target/ennemi.h"
#include "equip/equipement.h"
#include "helpers/common.h"

#include <string>
#include <iostream>
#include <random>

class Systeme
{
public:
    Systeme();
    void attaqueSensUniqueFusil(Allie& a, Ennemi& e);
    void attaqueSimpleFusil(Allie& a, Ennemi& e);
    void attaqueMonstre(Ennemi& e, Allie& a);
    void feu2(Allie& a, Ennemi& e);
};

#endif // SYSTEME_H
