#include "systeme.h"

using namespace std;

Systeme::Systeme()
{
    cout << "°° Système de combat initialisé °°" << endl;
}

void Systeme::attaqueSensUniqueFusil(Allie& a, Ennemi& e)
{
    cout << a.getNom().toStdString() << " a " << a.getStat("attaque") << " d'Attaque et " << a.getStat("parade") << " de Parade." << endl;

    while(e.getPV() > 0)
    {
        double myrando = aleatoire();
        unsigned int dmg = pow(a.getStat("attaque") * myrando, 2);
        if((e.getPV() - dmg) > e.getPVmax()) // équivalent de PV-dmg < 0 si PV avait été un int
        {
            e.setPV(0);
        }
        else
        {
            e.setPV(e.getPV() - dmg);
        }
        cout << "Les PV de " << e.getNom().toStdString() << " sont à présent de " << e.getPV() << " sur " << e.getPVmax() << endl;
    }
    e.setEtat("coma", true);
    cout << e.getNom().toStdString() << " a rendu l'âme! " << a.getNom().toStdString() << " a gagné le combat" << endl;
}

void Systeme::attaqueSimpleFusil(Allie& a, Ennemi& e)
{
    double myrando = aleatoire();
    unsigned int dmg = pow(a.getStat("attaque") * myrando, 2);
    if((e.getPV() - dmg) > e.getPVmax()) // équivalent de PV-dmg < 0 si PV avait été un int
    {
        e.setPV(0);
    }
    else
    {
        e.setPV(e.getPV() - dmg);
    }
    cout << "Les PV de " << e.getNom().toStdString() << " sont à présent de " << e.getPV() << " sur " << e.getPVmax() << endl;
    if(e.getPV() == 0)
    {
        cout << e.getNom().toStdString() << " a rendu l'âme!" << endl;
    }
}

void Systeme::attaqueMonstre(Ennemi &e, Allie &a)
{
    double myrando = aleatoire();
    double dmgD = (e.getStat("attaque") * myrando - a.getStat("défense")) * e.getStat("force") * (e.getNiveau() + e.getStat("force"))/256;
    unsigned int dmg = round(dmgD);
    if((a.getPV() - dmg) > a.getPVmax()) // équivalent de PV-dmg < 0 si PV avait été un int
    {
        a.setPV(0);
    }
    else
    {
        a.setPV(a.getPV() - dmg);
    }
    cout << "Les PV de " << a.getNom().toStdString() << " sont à présent de " << a.getPV() << " sur " << a.getPVmax() << endl;
    if(a.getPV() == 0)
    {
        cout << a.getNom().toStdString() << " s'effondre..." << endl;
    }
}

void Systeme::feu2(Allie &a, Ennemi &e)
{
    double myrando = aleatoire();
    double dmgD = (70 * myrando - e.getStat("défense magique")) * (2 + a.getStat("magie") * (a.getNiveau() + a.getStat("magie"))/256);
    unsigned int dmg = round(dmgD);
    if((e.getPV() - dmg) > e.getPVmax())
    {
        e.setPV(0);
    }
    else
    {
        e.setPV(e.getPV() - dmg);
    }
    cout << "Les PV de " << e.getNom().toStdString() << " sont à présent de " << e.getPV() << " sur " << e.getPVmax() << endl;
    if(e.getPV() == 0)
    {
        cout << e.getNom().toStdString() << " a rendu l'âme!" << endl;
    }
}

double Systeme::aleatoire()
{
    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<> distr(1, 1.125);

    return distr(eng);
}
