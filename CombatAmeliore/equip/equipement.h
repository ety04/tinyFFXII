#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>

class Equipement
{
public:
    Equipement();
    Equipement(QString nom);

    QString getNom() const;

protected:
    QString nom;
};

#endif // EQUIPEMENT_H
