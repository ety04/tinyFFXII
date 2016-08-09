#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QString>
#include "../target/allie.h"
#include "target/balthier.h"
#include "../target/apparition.h"

//header
class MyButton : public QPushButton
{
   Q_OBJECT

public:
   MyButton();
   MyButton(QWidget * parent);
   MyButton(const QString & text, QWidget * parent);
   MyButton(const QString &text, Allie* al);
   MyButton(const QString & text, Allie* al, QWidget * parent);
   MyButton(const QIcon& icon, const QString &text, Allie* al, QWidget* parent);
   MyButton(const QIcon& icon, const QString & text, Allie* al);
   ~MyButton();

   Allie* getAllie();
   void setAllie(Allie* value);

   Ennemi& getEnnemi();
   void setEnnemi(Ennemi& value);

private:
   Allie* allie;
   Ennemi ennemi = Apparition();

signals:
   void clicked();
   void buttonClickedForBattle(Allie* al, Ennemi& en);
   void buttonClickedForReset(Ennemi& en);

private slots:
   void setArmeAllie(QString &arme);

protected:
   void mousePressEvent(QMouseEvent*);
};

#endif // MYBUTTON_H
