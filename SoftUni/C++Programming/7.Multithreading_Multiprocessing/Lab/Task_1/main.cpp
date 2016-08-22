#include <iostream>
#include <time.h>
#include <thread>
#include <math.h>
#include <vector>
#include <mutex>
#include <windows.h>

using namespace std;

mutex mtx;

int frequercyOfPrims(int n)
{
    int i, j;
    int freq = n - 1;
    for (int i = 2; i < n; ++i)
    {
        for (int j = sqrt(i); j > 1; --j)
        {
            if (i % j == 0)
            {
                --freq;
                break;
            }
        }
    }
    return freq;
}

void printFreqOfPrimes(int n, int i)
{
    mtx.lock();
    Sleep(20);
//    cout << frequercyOfPrims(n) << ' ' << i << endl;
    cout << i << endl;
    mtx.unlock();
}

int main()
{
    int n = 100000;
    unsigned long long t = clock();
    int freqOfPrime = 0;
    vector<thread> aThread;
    aThread.reserve(1000);
//    thread aThread;
    for (int i = 0; i < 900; ++i)
    {
//        freqOfPrime = frequercyOfPrims(n);
        aThread.push_back(thread(printFreqOfPrimes, n, i));
    }
    for (int i = 0; i < aThread.size(); i++)
    {
        aThread[i].join();
//        aThread.join();
    }
    cout << "Time is: " << (double) ((double) clock() - t) / CLOCKS_PER_SEC;
    return 0;
}