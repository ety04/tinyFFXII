#ifndef MANDRAGORE_H
#define MANDRAGORE_H

#include "ennemi.h"

#include <random>
#include <iostream>

class Mandragore : public Ennemi
{
public:
    Mandragore();
    unsigned int aleatoireInt(unsigned int min, unsigned int max);
};

#endif // MANDRAGORE_H
