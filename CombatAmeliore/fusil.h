#ifndef FUSIL_H
#define FUSIL_H

#include "arme.h"

class Fusil : public Arme
{
public:
    Fusil();
    Fusil(std::string nom);
    Fusil(std::string nom, unsigned int att);

    double getCritique() const;

    unsigned int getParade() const;

private:
    const double critique = 0.05;
    const unsigned int parade = 10;
};

#endif // FUSIL_H
