#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>

//header
class MyComboBox : public QComboBox
{
   Q_OBJECT

public:
   MyComboBox();
   MyComboBox(QWidget * parent);

private slots:
   void teleportOnOff();

signals:

protected:


};

#endif // MYCOMBOBOX_H
