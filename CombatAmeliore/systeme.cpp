#include "systeme.h"

using namespace std;

Systeme::Systeme()
{
    cout << "°° Système de combat initialisé °°" << endl;
}

void Systeme::attaqueSensUniqueFusil(Allie& a, Ennemi& e)
{
    cout << a.getNom() << " a " << a.getStat("attaque") << " d'Attaque et " << a.getStat("parade") << " de Parade." << endl;

    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<> distr(1, 1.125);

    while(e.getPV() > 0)
    {
        double myrando = distr(eng);
        unsigned int dmg = pow(a.getStat("attaque") * myrando, 2);
        if((e.getPV() - dmg) > e.getPVmax()) // équivalent de PV-dmg < 0 si PV avait été un int
        {
            e.setPV(0);
        }
        else
        {
            e.setPV(e.getPV() - dmg);
        }
        cout << "Les PV de " << e.getNom() << " sont à présent de " << e.getPV() << " sur " << e.getPVmax() << endl;
    }
    e.setEtat("coma", true);
    cout << e.getNom() << " a rendu l'âme! " << a.getNom() << " a gagné le combat" << endl;
}

void Systeme::attaqueSimpleFusil(Allie& a, Ennemi& e)
{

    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<> distr(1, 1.125);

    double myrando = distr(eng);
    unsigned int dmg = pow(a.getStat("attaque") * myrando, 2);
        if((e.getPV() - dmg) > e.getPVmax()) // équivalent de PV-dmg < 0 si PV avait été un int
        {
            e.setPV(0);
        }
        else
        {
            e.setPV(e.getPV() - dmg);
        }
     cout << "Les PV de " << e.getNom() << " sont à présent de " << e.getPV() << " sur " << e.getPVmax() << endl;
     if(e.getPV() == 0)
     {
         cout << e.getNom() << " a rendu l'âme!" << endl;
     }
}

