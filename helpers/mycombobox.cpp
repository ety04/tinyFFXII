#include "mycombobox.h"

    //cpp

    MyComboBox::MyComboBox()
        :QComboBox()
    {
    }


    MyComboBox::MyComboBox(QWidget *parent = 0)
        :QComboBox(parent)
    {

    }

    void MyComboBox::teleportOnOff()
    {
        if(isVisible())
            setVisible(false);
        else
            setVisible(true);
    }
