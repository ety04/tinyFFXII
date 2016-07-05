#include "mainwindow.h"
#include "testmainwindow.h"
#include "testallie.h"
#include "testsysteme.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    TestMainWindow::runTests();
    TestAllie::runTests();
    TestSysteme::runTests();
    //QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
    MainWindow w(1000, 700);
    w.show();

    /*TestRunner testrunner;
    testrunner.addTest(new TestMainWindow());
    qDebug() << "Overall result: " << (testrunner.runTests()?"PASS":"FAIL");*/

    return a.exec();
}
