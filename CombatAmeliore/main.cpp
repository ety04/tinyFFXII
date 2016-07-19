#include "mainwindow.h"
#include "test/testmainwindow.h"
#include "test/testallie.h"
#include "test/testsysteme.h"
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

    return a.exec();
}
