#include "mylabel.h"

    //cpp

    MyLabel::MyLabel()
        :QLabel()
    {
    }

    MyLabel::MyLabel(QWidget * parent = 0)
    :QLabel(parent)
    {
    }

    MyLabel::MyLabel(QWidget * parent = 0, Qt::WindowFlags f = 0)
        :QLabel(parent, f)
    {
    }

    MyLabel::MyLabel(const QString & text, QWidget * parent = 0)
        :QLabel(text, parent)
    {
    }

    MyLabel::MyLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0)
        :QLabel(text, parent, f)
    {
    }

    MyLabel::MyLabel(int red, int green, int blue, QWidget * parent = 0)
        :QLabel(parent)
    {
        setPalette(QPalette(QColor(red, green, blue)));
    }

    MyLabel::MyLabel(const QString & text, int red, int green, int blue, QWidget * parent = 0)
        :QLabel(text, parent)
    {
        setPalette(QPalette(QColor(red, green, blue)));
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

    void MyLabel::mousePressEvent(QMouseEvent*)
    {
        emit clicked();
        int xBio = x() + 1.5*width();
        int yBio = y() + 1.5*height();
        emit labelClicked(xBio, yBio);
        emit bigLabelClicked(x(), y(), bio);
    }
