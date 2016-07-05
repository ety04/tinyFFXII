#include <testsysteme.h>

using namespace std;

void TestSysteme::testAttaqueSensUniqueFusil()
{

    Balthier ba;
    Apparition ap;

    Systeme s;
    s.attaqueSensUniqueFusil(ba, ap);

}

void TestSysteme::testEquals(bool a, bool b, string label)
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

void TestSysteme::testEquals(int a, int b, string label)
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

void TestSysteme::runTests()
{
    TestSysteme* test = new TestSysteme();

    test->testAttaqueSensUniqueFusil();
    delete test;
}
