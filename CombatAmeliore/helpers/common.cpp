#include "common.h"

#include <QThread>

using namespace std;


void myWait(int sleepMs)
{
    unsigned long sleepSec = sleepMs/1000;
    cout << "Attente de: " << sleepMs << " millisecondes." << endl;
    QThread::sleep(sleepSec);
}

unsigned int aleatoireInt(unsigned int min, unsigned int max)
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(min, max);

    return distr(eng);
}

double aleatoireDouble(double min, double max)
{
    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<> distr(min, max);

    return distr(eng);
}

double aleatoire()
{
    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<> distr(1, 1.125);

    return distr(eng);
}
