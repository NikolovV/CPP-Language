#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>
#include <csignal>

using namespace std;

static volatile bool g_exit = false;
mutex mtx;

static BOOL WINAPI console_ctrl_handler(DWORD dwCtrlType)
{
    if (dwCtrlType == CTRL_CLOSE_EVENT)
    {
        g_exit = true;
        return TRUE;
    }
    return FALSE;
}

void sh()
{
    //    SetConsoleCtrlHandler(console_ctrl_handler, TRUE);
    while (1)
    {
        Sleep(1000);
        mtx.lock();
        cout << "sh()" << endl;
        mtx.unlock();

        if (g_exit == TRUE)
        {
            mtx.lock();
            cout << "CTRL C SH()" << endl;
            cout << "   SH() wait..." << endl;
            mtx.unlock();
            Sleep(5000);
            mtx.lock();
            cout << "Exit SH()" << endl;
            cout << "   SH() wait..." << endl;
            mtx.unlock();
            Sleep(3000);
            break;
        }
    }
}

void ph()
{
    //    SetConsoleCtrlHandler(console_ctrl_handler, TRUE);
    while (1)
    {
        Sleep(2000);

        mtx.lock();
        cout << "ph()" << endl;
        mtx.unlock();

        if (g_exit == TRUE)
        {
            mtx.lock();
            cout << "CTRL C PH()" << endl;
            cout << "   PH() wait..." << endl;
            mtx.unlock();
            Sleep(5000);
            mtx.lock();
            cout << "Exit PH()" << endl;
            cout << "   PH() wait..." << endl;
            mtx.unlock();
            Sleep(3000);
            break;
        }
    }
}

int main()
{
    SetConsoleCtrlHandler(console_ctrl_handler, TRUE);
    thread at1(sh);
    thread at2(ph);
    //
    at1.join();
    at2.join();

    //    sh();

    return 0;
}