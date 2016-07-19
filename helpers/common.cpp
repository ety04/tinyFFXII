#include "common.h"

#include <QThread>

void myWait(int sleepMs)
{
    unsigned long sleepSec = sleepMs/1000;
    std::cout << "Attente de: " << sleepMs << " millisecondes." << std::endl;
    QThread::sleep(sleepSec);
}
