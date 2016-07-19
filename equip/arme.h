#ifndef ARME_H
#define ARME_H

#include "equip/equipement.h"
#include "helpers/common.h"

class Arme : public Equipement
{
public:
    Arme();
    Arme(std::string nom);
    Arme(std::string nom, unsigned int att);

    unsigned int getAttaque() const;
    void setAttaque(unsigned int value);

private:
    unsigned int attaque;
    Element element;
};

#endif // ARME_H
