#ifndef ALLIE_H
#define ALLIE_H

#include "cible.h"


class Allie : public Cible
{
public:
    Allie();
    Allie(QString nom);

    bool getMysteFull();
    void setMysteFull(bool value);

    std::vector<Equipement> getEquipement();
    void setEquipement(const std::vector<Equipement> &value);

    std::vector<QString> getButins();
    void setButins(const std::vector<QString> &value);
    void addButin(QString &butin);

    unsigned int getExp();
    void setExp(unsigned int value);
    void addExp(unsigned int value);

private:
    bool mysteFull;
    std::vector<Equipement> equipement;
    std::vector<QString> butins;
    unsigned int exp;
};

#endif // ALLIE_H
