#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QObject>
#include <QtTest>

#include "mainwindow.h"

class TestMainWindow : public QObject
{
    Q_OBJECT

public:
    static void runTests();
    void testEquals(QString a, QString b, std::string label);
    void testLog();

signals:

private slots:

};

#endif // TESTMAINWINDOW_H
