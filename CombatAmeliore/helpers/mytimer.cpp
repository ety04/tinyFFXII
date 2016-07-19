#include "mytimer.h"

using namespace std;

    //cpp

    MyTimer::MyTimer()
        :QTimer()
    {
        setSingleShot(true);
    }

    MyTimer::MyTimer(QObject * parent = 0)
        :QTimer(parent)
    {
        setSingleShot(true);
    }

    MyTimer::MyTimer(string name)
        :QTimer()
    {
        setSingleShot(true);
        nom = name;
    }

    MyTimer::MyTimer(Ennemi & en, Allie* al, QObject* parent = 0)
        :QTimer(parent)
    {
        setSingleShot(true);
        allie = al;
        ennemi = en;
    }

    MyTimer::MyTimer(Ennemi & en, Allie* al)
        :QTimer()
    {
        setSingleShot(true);
        allie = al;
        ennemi = en;
    }

    MyTimer::MyTimer(string name, Ennemi & en, Allie* al)
        :QTimer()
    {
        setSingleShot(true);
        nom = name;
        allie = al;
        ennemi = en;
    }

    MyTimer::~MyTimer()
    {
    }

    Allie* MyTimer::getAllie()
    {
        return allie;
    }

    void MyTimer::setAllie(Allie*  value)
    {
        allie = value;
    }

    Ennemi& MyTimer::getEnnemi()
    {
        return ennemi;
    }

    void MyTimer::setEnnemi(Ennemi& value)
    {
        ennemi = value;
    }

    std::string MyTimer::getNom()
    {
        return nom;
    }

    void MyTimer::setNom(string& value)
    {
        nom = value;
    }

    void MyTimer::timerEvent(QTimerEvent* e)
    {
        if(e->timerId() == this->timerId())
        {
            std::cout << "TIMEOUT EMITTED - " << nom << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            emit timeout();
            emit timeoutNowAttack(ennemi, allie);
        }
    }

    void MyTimer::stopAndBlock()
    {
        blockSignals(true);
        stop();
    }
