#include "Print_val_in_time.h"

/**
 * Variant 1
 * @param msg - some const massage
 * @param val - unsigned long long variable to print
 * @param start - start clock time.
 */
void print_val_in_time(const char *msg, unsigned long long val, clock_t start)
{
    clock_t end;
    double time_spent;

    // Calculate difference between start and end. (first variant)
    end = clock();
    time_spent = (double) (end - start); /// CLOCKS_PER_SEC;
       
    mtx.lock();
    if (time_spent < SEC_IN_MS)
    {
        //                cout << lastFound << " - " << diff << " ms" << endl;
        printf("%s %llu - %.3lf ms\n", msg, val, time_spent);
    }
    else if (time_spent > SEC_IN_MS && time_spent < MIN_IN_MS)
    {
        //                cout << lastFound << " - " << (diff / SEC_IN_MS) << " sec" << endl;
        printf("%s %llu - %.3lf sec\n", msg, val, (time_spent / SEC_IN_MS));
    }
    else if (time_spent > MIN_IN_MS)
    {
        //                cout << lastFound << " - " << (diff / MIN_IN_MS) << " min" << endl;
        printf("%s %llu - %.3lf min\n", msg, val, (time_spent / MIN_IN_MS));
    }
    mtx.unlock();
}

/**
 * Variant 2
 * @param msg - some const massage
 * @param val - unsigned long long variable to print
 * @param startTime - start clock time
 * @param frenq
 */
void print_val_in_time(const char *msg, unsigned long long val, LARGE_INTEGER startTime, LARGE_INTEGER frenq)
{
    LARGE_INTEGER end;
    double diff;
    /**
     * Calculate difference between start and end. (second variant)
     */
    QueryPerformanceCounter(&end);
    diff = (end.QuadPart - startTime.QuadPart);
    diff *= SEC_IN_MS;
    diff /= frenq.QuadPart;

    // lock console and print in corresponding time.
    mtx.lock();
    if (diff < SEC_IN_MS)
    {
        //                cout << lastFound << " - " << diff << " ms" << endl;
        printf("%s %llu - %.3lf ms\n", msg, val, diff);
    }
    else if (diff > SEC_IN_MS && diff < MIN_IN_MS)
    {
        //                cout << lastFound << " - " << (diff / SEC_IN_MS) << " sec" << endl;
        printf("%s %llu - %.3lf sec\n", msg, val, (diff / SEC_IN_MS));
    }
    else if (diff > MIN_IN_MS)
    {
        //                cout << lastFound << " - " << (diff / MIN_IN_MS) << " min" << endl;
        printf("%s %llu - %.3lf min\n", msg, val, (diff / MIN_IN_MS));
    }
    mtx.unlock();
}