#ifndef SYSTEME_H
#define SYSTEME_H

#include <cible.h>
#include <allie.h>
#include <ennemi.h>
#include <equipement.h>

#include <string>
#include <iostream>
#include <random>

class Systeme
{
public:
    Systeme();
    void attaqueSensUniqueFusil(Allie& a, Ennemi& e);
    void attaqueSimpleFusil(Allie& a, Ennemi& e);

};

#endif // SYSTEME_H
