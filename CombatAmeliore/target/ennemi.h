#ifndef ENNEMI_H
#define ENNEMI_H

#include "cible.h"
#include <QString>

class Ennemi : public Cible
{
public:
    Ennemi();
    Ennemi(QString nom);

    bool getAgressif() const;
    void setAgressif(bool value);

    QString& getButin();
    void setButin(const QString &value);

    QString& getActionPrincipale();
    void setActionPrincipale(const QString & value);

    QString getCri();
    void setCri(const QString &value);

    unsigned int getExpDonnee();
    void setExpDonnee(unsigned int value);

private:
    bool agressif;
    QString butin;
    QString actionPrincipale;
    QString cri;
    unsigned int expDonnee;
};

#endif // ENNEMI_H
