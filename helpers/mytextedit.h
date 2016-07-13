#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>

//header
class MyTextEdit : public QTextEdit
{
   Q_OBJECT

public:
   MyTextEdit(QWidget * parent);
   MyTextEdit(const QString & text, QWidget * parent);
   ~MyTextEdit();

signals:
   void clicked();
protected:
   void mousePressEvent(QMouseEvent*);
};

#endif // MYTEXTEDIT_H
