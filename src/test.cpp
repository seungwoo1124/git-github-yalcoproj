#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    long prevTick = clock();
    long sumTick = 0;
    double prevsec = 0.0;
    while (sumTick < 10000000)
    {
        long curTick = clock();
        long deltaTick = curTick - prevTick;
        double realsec = (double)(curTick / CLOCKS_PER_SEC);
        sumTick += deltaTick;
        if (realsec != prevsec)
        {
            cout << realsec << endl;
            prevsec = realsec;
        }
        prevTick = curTick;

    }
}