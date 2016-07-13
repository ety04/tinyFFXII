#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <string>

class Equipement
{
public:
    Equipement();
    Equipement(std::string nom);

private:
    std::string nom;
};

#endif // EQUIPEMENT_H
