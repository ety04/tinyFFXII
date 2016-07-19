#include "testallie.h"

using namespace std;

void TestAllie::testEtat()
{

    Allie a("test");
    a.setEtat("poison", true);
    //cout << "Poison status of " << a.getNom() << ": " << boolalpha << a.getEtat("poison") << endl;
    //QCOMPARE(a.getEtat("poison"), true); // ne marche pas
    testEquals(a.getEtat("poison"), true, "Etat");

}

void TestAllie::testStats()
{
    Allie a("test");
    a.setStat("vitesse", 30);
    testEquals(a.getStat("vitesse"), 30, "Statistiques");
}

void TestAllie::testEquals(bool a, bool b, string label)
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

void TestAllie::testEquals(int a, int b, string label)
{
    cout << "****** Test: " << label << " ******" << endl;
    if(a == b)
    {
        cout << "Test " << label << " réussi." << endl;
    }
    else
    {
        cout << "Test " << label << " échoué!" << endl;
    }
}

void TestAllie::runTests()
{
    TestAllie* test = new TestAllie();

    test->testEtat();
    test->testStats();
    delete test;
}
