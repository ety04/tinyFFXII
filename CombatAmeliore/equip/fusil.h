#ifndef FUSIL_H
#define FUSIL_H

#include <QMetaType>
#include "arme.h"

class Fusil : public Arme
{
public:
    Fusil();
    Fusil(QString nom);
    Fusil(QString nom, unsigned int att);

    double getCritique() const;

    unsigned int getParade() const;

    friend bool operator ==(const Fusil& f1, const Fusil& f2);

private:
    const double critique = 0.05;
    const unsigned int parade = 10;
};
Q_DECLARE_METATYPE(const Fusil*)

#endif // FUSIL_H
