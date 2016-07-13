#ifndef TESTALLIE_H
#define TESTALLIE_H

#include <QObject>
#include <QtTest>
#include <iostream>

#include "../target/allie.h"

class TestAllie : public QObject
{
    Q_OBJECT

public:
    static void runTests();
    void testEquals(bool a, bool b, std::string label);
    void testEquals(int a, int b, std::string label);

signals:

private slots:
    void testEtat();
    void testStats();

};

#endif // TESTALLIE_H
