#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

//header
class MyLabel : public QLabel
{
   Q_OBJECT

public:
   MyLabel();
   MyLabel(QWidget * parent);
   MyLabel(QWidget * parent, Qt::WindowFlags f);
   MyLabel(const QString & text, QWidget * parent, Qt::WindowFlags f);
   MyLabel(int red, int green, int blue, QWidget * parent);
   MyLabel(const QString & text, int red, int green, int blue, QWidget * parent);
   ~MyLabel();

signals:
   void clicked();
   void labelClicked(int xBio, int yBio);
   void bigLabelClicked(int x, int y);


protected:
   void mousePressEvent(QMouseEvent*);
};

#endif // MYLABEL_H
