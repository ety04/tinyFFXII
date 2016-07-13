#include "testmainwindow.h"

using namespace std;

void TestMainWindow::testLog()
{

    const QString message = "lalala";
    MainWindow m;
    QTextEdit* boite = new QTextEdit();
    m.setLog(message, *boite);
    //QCOMPARE(m.getLog(boite), message); // ne marche pas
    testEquals(m.getLog(boite), message, "Log");

}

void TestMainWindow::testEquals(QString a, QString b, string label)
{
    cout << "****** Test: " << label << " ******" << endl;
    if(a == b)
    {
        cout << "Test " << label << " réussi." << endl;
    }
    else
    {
        cout << "Test " << label << " échoué!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }
}

void TestMainWindow::runTests()
{
    TestMainWindow* test = new TestMainWindow();

    test->testLog();
    delete test;
}
