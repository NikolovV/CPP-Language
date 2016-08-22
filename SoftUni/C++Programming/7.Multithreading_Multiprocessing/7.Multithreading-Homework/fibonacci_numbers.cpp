#include "Fibonacci_numbers.h"
bool g_exit = false;

void fibonacci_numbers(unsigned long long num)
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

    unsigned long long first = 0, second = 1, next = 1;
    for (unsigned long long i = 0; i < num /*&& g_exit == FALSE*/; ++i)
    {
        if (next < first)
        {
            break;
        }
        if (i <= 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        // if CTTL + C or close the console, stop, print massage and exit current thread
        if (g_exit == TRUE)
        {
            // lock the console to print only current thread.
            mtx.lock();
            cout << "CTRL C Fibunacci()" << endl;
            cout << "Fibunacci exit... in 10 seconds" << endl;
            // unlock
            mtx.unlock();
            Sleep(10000);
            break;
        }
        //        end = clock();
        //        time_spent = (double) (end - begin); /// CLOCKS_PER_SEC;
        //        mtx.lock();
        //        printf("%llu - %.3lf\n", next, time_spent);
        //        mtx.unlock();
        
        // wait 100 milliseconds (for windows)
        Sleep(100);
        
        /**
         * Calculate difference between start and end. (second variant)
         */
        QueryPerformanceCounter(&end);
        diff = (end.QuadPart - start.QuadPart);
        diff *= 1000;
        diff /= frenq.QuadPart;
        
        // lock console and print in corresponding time. (first variant)
        mtx.lock();
        if (diff < SEC_IN_MS)
        {
            //        cout << time_spent << " ms" << endl;
            printf("Fibunacci %llu - %.3lf ms\n", next, diff);
        }
        else if (diff > SEC_IN_MS && diff < MIN_IN_MS)
        {
            //        cout << time_spent / 1000 << " sec" << endl;
            printf("Fibunacci %llu - %.3lf sec\n", next, (diff / SEC_IN_MS));
        }
        else if (diff > MIN_IN_MS)
        {
            //        cout << time_spent / 60000 << " min" << endl;
            printf("Fibunacci %llu - %.3lf min\n", next, (diff / MIN_IN_MS));
        }
        mtx.unlock();
    }
}