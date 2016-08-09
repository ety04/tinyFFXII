#include "mylabel.h"

//cpp

MyLabel::MyLabel()
    :QLabel()
{
    bio = "";
    resize(100, 100);
}

MyLabel::MyLabel(QWidget * parent = 0)
    :QLabel(parent)
{
    bio = "";
    resize(100, 100);
}

MyLabel::MyLabel(QWidget * parent = 0, Qt::WindowFlags f = 0)
    :QLabel(parent, f)
{
    bio = "";
    resize(100, 100);
}

MyLabel::MyLabel(const QString & text, QWidget * parent = 0)
    :QLabel(text, parent)
{
    bio = "";
}

MyLabel::MyLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0)
    :QLabel(text, parent, f)
{
    bio = "";
    resize(100, 100);
}

MyLabel::MyLabel(int red, int green, int blue, QWidget * parent = 0)
    :QLabel(parent)
{
    setPalette(QPalette(QColor(red, green, blue)));
    bio = "";
    resize(100, 100);
}

MyLabel::MyLabel(const QString & text, int red, int green, int blue, QWidget * parent = 0)
    :QLabel(text, parent)
{
    setPalette(QPalette(QColor(red, green, blue)));
    bio = "";
    resize(100, 100);
}

MyLabel::~MyLabel()
{
}

QString MyLabel::getBio()
{
    return bio;
}

void MyLabel::setBio(const QString &value)
{
    bio = value;
}

/** La redéfinition de cette méthode permet d'émettre un signal lorsqu'on clique sur l'image */
void MyLabel::mousePressEvent(QMouseEvent*)
{
    emit clicked();
    int xBio = x() + 1.5*width();
    int yBio = y() + 1.5*height();
    emit labelClicked(xBio, yBio);
    emit bigLabelClicked(x(), y(), bio);
}

/** Ce slot sert à définir ou changer l'image de l'arme affichée pour Balthier */
void MyLabel::setPicArme(QString& id)
{
    QString url = ":/images/fusils/" + id + ".png";
    setPixmap(QPixmap(url));
    move(850, 210);
    setScaledContents(true);
}

/** Ce slot permet d'agrandir la miniature de l'image et de la centrer */
void MyLabel::agrandir()
{
    resize(400, 400);
    setScaledContents(true);
    move(250, 200);
    raise();
}

/** Ce slot ramène la miniature comme elle était */
void MyLabel::reduire()
{
    resize(100, 100);
    setScaledContents(true);
    move(850, 210);
}

/** La redéfinition de cette méthode permet d'émettre un signal lorsqu'on entre dans la zone de l'image... */
void MyLabel::enterEvent(QEvent*)
{
    emit agrandis();
}

/** ... Et celle-ci lorsqu'on la quitte */
void MyLabel::leaveEvent(QEvent*)
{
    emit reduis();
}
