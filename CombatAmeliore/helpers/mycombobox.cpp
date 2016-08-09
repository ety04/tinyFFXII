#include "mycombobox.h"

using namespace std;

//cpp

MyComboBox::MyComboBox()
    :QComboBox()
{
}


MyComboBox::MyComboBox(QWidget *parent = 0)
    :QComboBox(parent)
{
    lastIndex = currentIndex();
    connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)));
}

/** Ce slot permet de rendre visible ou invisible la liste déroulante */
void MyComboBox::teleportOnOff()
{
    if(isVisible())
        setVisible(false);
    else
        setVisible(true);
}

/** Ce slot permet d'émettre un signal avec l'ID du fusil correspondant à la sélection */
void MyComboBox::onIndexChanged(int index) // index = currentIndex()
{
    if(index != lastIndex)
    {
        lastIndex = index;
        QVariant varF = currentData();
        const Fusil* f = NULL;
        if(varF.canConvert<const Fusil *>())
        {
            f = varF.value<const Fusil*>();
        }
        else
            cout << "/!\\ Conversion vers 'const Fusil*' impossible!!" << endl;

        if(f == NULL)
        {
            cout << "Pointeur sur l'arme NUL!!" << endl;
            return;
        }
        else if(f->getAttaque() == 0)
            cout << "Attaque nulle! Arme par défaut" << endl;

        QString id = fl.donneCle(f);
        if(id != "")
        {
            emit nouveauFusil(id);
            emit nouveauFusilSon();
        }
    }
}
