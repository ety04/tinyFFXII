#ifndef ENNEMI_H
#define ENNEMI_H

#include "cible.h"

class Ennemi : public Cible
{
public:
    Ennemi();
    Ennemi(std::string nom);

    bool getAgressif() const;
    void setAgressif(bool value);

    std::string getButin() const;
    void setButin(const std::string &value);

private:
    bool agressif;
    std::string butin;
};

#endif // ENNEMI_H
