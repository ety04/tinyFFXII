#include "mytextedit.h"

//cpp

MyTextEdit::MyTextEdit(QWidget * parent=0)
    :QTextEdit(parent)
{
}

MyTextEdit::MyTextEdit(const QString & text, QWidget * parent=0)
    :QTextEdit(text, parent)
{
}

MyTextEdit::~MyTextEdit()
{
}

void MyTextEdit::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}
