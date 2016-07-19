#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include <QTimerEvent>
#include <iostream>
#include <string>
#include "../target/allie.h"
#include "../target/ennemi.h"

//header
class MyTimer : public QTimer
{
   Q_OBJECT

public:
   MyTimer();
   MyTimer(QObject *parent);
   MyTimer(std::string name);
   MyTimer(Ennemi & en, Allie* al, QObject * parent);
   MyTimer(Ennemi & en, Allie* al);
   MyTimer(std::string name, Ennemi & en, Allie* al);
   ~MyTimer();

   Allie* getAllie();
   void setAllie(Allie* value);

   Ennemi& getEnnemi();
   void setEnnemi(Ennemi& value);

   std::string getNom();
   void setNom(std::string &value);

   void stopAndBlock();

private:
   std::string nom;
   Allie* allie;
   Ennemi ennemi;

signals:
   void timeout();
   void timeoutNowAttack(Ennemi & en, Allie* al);

protected:
   void timerEvent(QTimerEvent* e);
};

#endif // MYTIMER_H
