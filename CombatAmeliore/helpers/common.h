#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <random>


enum Element { feu, eau, terre, air, foudre, glace, lumiere, tenebres };


void myWait(int sleepMs);
unsigned int aleatoireInt(unsigned int min, unsigned int max);
double aleatoireDouble(double min, double max);
double aleatoire();

#endif // COMMON_H

