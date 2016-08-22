#include <iostream>
#include <csignal>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;
mutex consoleLock;

void signaHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

void pr()
{
    while (true)
    {
        consoleLock.lock();
        cout << "Going to sleep...." << endl;
        consoleLock.unlock();
        Sleep(100);
    }
}

void sh()
{
    while (true)
    {
        consoleLock.lock();
        cout << "again" << endl;
        consoleLock.unlock();
        Sleep(100);
    }
}

int main(int argc, char** argv)
{
    signal(SIGINT, signaHandler);
    thread p(pr);
    thread s(sh);

    p.join();
    s.join();

    return 0;
}