#include "Fibonacci_numbers.h"
#include "Print_val_in_time.h"

bool g_exit = false;

void fibonacci_numbers(unsigned long long num)
{
    /**
     * First variant of clock measure.
     */
    clock_t begin;
    begin = clock();

    /**
     * Second variant of clock measure. (only for windows)
     * Calculate all time of the program.
     */
    LARGE_INTEGER start, frenq;
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
        
        // wait 100 milliseconds (for windows)
        Sleep(100);

        /**
         * Calculate difference between start and end. (first variant)
         */
//        print_val_in_time("Fibunacci", next, begin);
        
        /**
         * Calculate difference between start and end. (second variant)
         */
        print_val_in_time("Fibunacci", next, start, frenq);
    }
}