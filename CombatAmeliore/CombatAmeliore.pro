#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T22:04:24
#
#-------------------------------------------------

QT       += core gui \
            testlib \
            multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CombatAmeliore
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    systeme.cpp \
    environment/lieu.cpp \
    equip/arme.cpp \
    equip/equipement.cpp \
    equip/fusil.cpp \
    helpers/common.cpp \
    helpers/mybutton.cpp \
    helpers/mycombobox.cpp \
    helpers/mylabel.cpp \
    helpers/mytextedit.cpp \
    helpers/mytimer.cpp \
    target/allie.cpp \
    target/apparition.cpp \
    target/balthier.cpp \
    target/cible.cpp \
    target/ennemi.cpp \
    test/testallie.cpp \
    test/testmainwindow.cpp \
    test/testsysteme.cpp \
    target/mandragore.cpp \
    target/fran.cpp

HEADERS  += mainwindow.h \
    systeme.h \
    environment/lieu.h \
    equip/arme.h \
    equip/equipement.h \
    equip/fusil.h \
    helpers/common.h \
    helpers/mybutton.h \
    helpers/mycombobox.h \
    helpers/mylabel.h \
    helpers/mytextedit.h \
    helpers/mytimer.h \
    target/allie.h \
    target/apparition.h \
    target/balthier.h \
    target/cible.h \
    target/ennemi.h \
    test/testallie.h \
    test/testmainwindow.h \
    test/testsysteme.h \
    target/mandragore.h \
    target/fran.h

FORMS    += mainwindow.ui

RESOURCES += \
    media.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/

CONFIG += c++14 \
        static


