#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include "equip/fusilliste.h"

//header
class MyComboBox : public QComboBox
{
   Q_OBJECT

public:
   MyComboBox();
   MyComboBox(QWidget * parent);

private slots:
   void teleportOnOff();
   void onIndexChanged(int index);

signals:
   void nouveauFusil(QString& nom);
   void nouveauFusilSon();

protected:

private:
   int lastIndex;
   FusilListe fl;


};

#endif // MYCOMBOBOX_H
