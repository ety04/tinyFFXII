#ifndef ENNEMI_H
#define ENNEMI_H

#include "cible.h"
#include "helpers/common.h"
#include "helpers/mylabel.h"

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

    Element getFaiblesse();
    void setFaiblesse(const Element &value);

    QString getLienImage();
    void setLienImage(const QString &value);

    QString getId();
    void setId(const QString &value);

private:
    QString id;
    bool agressif;
    QString butin;
    QString actionPrincipale;
    QString cri;
    unsigned int expDonnee;
    Element faiblesse;
    QString lienImage;
};

#endif // ENNEMI_H
