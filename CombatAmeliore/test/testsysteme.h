#ifndef TESTSYSTEME_H
#define TESTSYSTEME_H

#include <QObject>
#include <QtTest>
#include <iostream>

#include "../target/balthier.h"
#include "../target/apparition.h"
#include "systeme.h"

class TestSysteme : public QObject
{
    Q_OBJECT

public:
    static void runTests();
    void testEquals(bool a, bool b, std::string label);
    void testEquals(int a, int b, std::string label);

signals:

private slots:
    void testAttaqueSensUniqueFusil();

};

#endif // TESTSYSTEME_H
