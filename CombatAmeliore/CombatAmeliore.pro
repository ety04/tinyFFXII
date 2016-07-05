#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T22:04:24
#
#-------------------------------------------------

QT       += core gui \
            testlib \
            multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CombatSimple
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    testmainwindow.cpp \
    mylabel.cpp \
    cible.cpp \
    mytextedit.cpp \
    equipement.cpp \
    allie.cpp \
    testallie.cpp \
    ennemi.cpp \
    apparition.cpp \
    balthier.cpp \
    arme.cpp \
    fusil.cpp \
    systeme.cpp \
    testsysteme.cpp \
    mybutton.cpp

HEADERS  += mainwindow.h \
    testrunner.h \
    testmainwindow.h \
    mylabel.h \
    cible.h \
    mytextedit.h \
    equipement.h \
    allie.h \
    testallie.h \
    ennemi.h \
    apparition.h \
    balthier.h \
    arme.h \
    fusil.h \
    systeme.h \
    common.h \
    testsysteme.h \
    mybutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/

CONFIG += c++14 \
        static


