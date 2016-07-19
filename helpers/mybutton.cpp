#include "mybutton.h"

    //cpp

    MyButton::MyButton()
        :QPushButton()
    {
    }

    MyButton::MyButton(QWidget * parent = 0)
    :QPushButton(parent)
    {
    }

    MyButton::MyButton(const QString & text, QWidget * parent = 0)
        :QPushButton(text, parent)
    {
    }

    MyButton::MyButton(const QString & text, Allie* al, QWidget * parent = 0)
        :QPushButton(text, parent)
    {
        allie = al;
    }

    MyButton::MyButton(const QIcon& icon, const QString & text, Allie* al, QWidget * parent = 0)
        :QPushButton(icon, text, parent)
    {
        allie = al;
    }

    MyButton::MyButton(const QIcon& icon, const QString & text, Allie* al)
        :QPushButton(icon, text)
    {
        allie = al;
    }

    MyButton::MyButton(const QString & text, Allie* al)
        :QPushButton(text)
    {
        allie = al;
    }

    MyButton::~MyButton()
    {
    }

    Allie* MyButton::getAllie()
    {
        return allie;
    }

    void MyButton::setAllie(Allie*  value)
    {
        allie = value;
    }

    Ennemi& MyButton::getEnnemi()
    {
        return ennemi;
    }

    void MyButton::setEnnemi(Ennemi& value)
    {
        ennemi = value;
    }

    void MyButton::mousePressEvent(QMouseEvent*)
    {
        emit clicked();
        emit buttonClickedForBattle(allie, ennemi);
        emit buttonClickedForReset(ennemi);
    }
