#include "prime_numbers.h"

void prime_numbers(unsigned long long num)
{
    /**
     * First variant of clock measure.
     */
    //    clock_t begin, end;
    //    double time_spent;
    //    begin = clock();

    /**
     * Second variant of clock measure. (only for windows)
     * Calculate all time of the program.
     */
    LARGE_INTEGER start, end, frenq;
    double diff;
    QueryPerformanceFrequency(&frenq);
    QueryPerformanceCounter(&start);

    // fast algorithm
    bool flag = false;
    unsigned long long lastFound, i;
    for (unsigned long long i = 2; i < num /*&& g_exit == FALSE*/; ++i)
    {
        flag = 0;
        for (unsigned long long j = sqrt(i); j > 1; --j)
        {
            if (i % j == 0)
            {
                flag = true;
                break;
            }
        }
        // if CTTL + C or close the console, stop, print massage and exit current thread
        if (g_exit == TRUE)
        {
            // lock the console to print only current thread.
            mtx.lock();
            cout << "CTRL C Primes()" << endl;
            cout << "Primes exit... in 10 seconds" << endl;
            // unlock
            mtx.unlock();
            Sleep(10000);
            break;
        }
        // found prime.
        if (flag == 0)
        {
            lastFound = i;
            // wait 100 milliseconds (for windows)
            Sleep(100);
            /**
             * Calculate difference between start and end. (second variant)
             */
            QueryPerformanceCounter(&end);
            diff = (end.QuadPart - start.QuadPart);
            diff *= SEC_IN_MS;
            diff /= frenq.QuadPart;
            
            // lock console and print in corresponding time.
            mtx.lock();
            if (diff < SEC_IN_MS)
            {
                //                cout << lastFound << " - " << diff << " ms" << endl;
                printf("Prime %llu - %.3lf ms\n", lastFound, diff);
            }
            else if (diff > SEC_IN_MS && diff < MIN_IN_MS)
            {
                //                cout << lastFound << " - " << (diff / SEC_IN_MS) << " sec" << endl;
                printf("Prime %llu - %.3lf sec\n", lastFound, (diff / SEC_IN_MS));
            }
            else if (diff > MIN_IN_MS)
            {
                //                cout << lastFound << " - " << (diff / MIN_IN_MS) << " min" << endl;
                printf("Prime %llu - %.3lf min\n", lastFound, (diff / MIN_IN_MS));
            }
            mtx.unlock();

            // Calculate difference between start and end. (first variant)
            //            end = clock();
            //            time_spent = (double) (end - begin); /// CLOCKS_PER_SEC;
            //            mtx.lock();
            //            printf("Prime %llu - %.3lf min\n", next, time_spent);
            //            mtx.lock();
        }
    }
    /**
     * other algorithms 
     */
    // slow algorithm
    //    for (unsigned long long i = 3; i < num; i = i + 2)
    //    {
    //        bool flag = false;
    //        for (unsigned long long j = 2; j <= i / 2; j++)
    //        {
    //            if ((i % j) == 0)
    //            {
    //                flag = true;
    //                break;
    //            }
    //        }
    //    }

    // very fast algorithm
    //    for (unsigned long long i = 2; i < num; ++i)
    //    {
    //        bool prime = true;
    //        for (unsigned long long j = 2; j * j <= i; ++j)
    //        {
    //            if (i % j == 0)
    //            {
    //                prime = false;
    //                break;
    //            }
    //        }
    //    }
}