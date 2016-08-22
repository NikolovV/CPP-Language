#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

mutex mx;
#define STEP 3

class A
{
public:

    void sh(string msg, int id)
    {
        if (mx.try_lock() == false)
        {
            mx.lock();
            usleep(1000000);
            cout << "mx locked - sh() " << id << " waiting..." << endl;
            mx.unlock();
            sleep(8);
        }
        usleep(10);
        cout << msg << ' ' << id << endl;
        mx.unlock();
    }

    void ph(string msg, int id)
    {
        if (mx.try_lock() == false)
        {
            mx.lock();
            usleep(1000000);
            cout << "mx locked - ph() " << id << " waiting..." << endl;
            mx.unlock();
            sleep(2);
        }
        usleep(10);
        cout << msg << ' ' << id << endl;
        mx.unlock();
    }

    void pr()
    {
        thread th[STEP], at[STEP];
        for (int i = 0; i < STEP; i++)
        {
            th[i] = thread([&] ()
            {
                sh("sh()", i);
            });
            at[i] = thread(&A::ph, A(), "ph()", i);
        }

        for (int i = 0; i < STEP; i++)
        {
            th[i].join();
            at[i].join();
        }
    }
};

int main()
{
    A a;
    a.pr();
    //    thread at(
    //    [&a] ()
    //    {
    //        mx.try_lock();
    //        a.sh("main sh()");
    //        mx.unlock();
    //        
    //    }
    //    ); 

    //        thread at(&A::sh, A(), "main sh()");
    //        at.join();

    //    thread at[STEP];
    //    for (int i = 0; i < STEP; i++)
    //    {
    //        at[i] = thread(&A::ph, A(), "main->ph()", i);
    //    }
    //
    //    for (int i = 0; i < STEP; i++)
    //    {
    //        at[i].join();
    //    }

    return 0;
}