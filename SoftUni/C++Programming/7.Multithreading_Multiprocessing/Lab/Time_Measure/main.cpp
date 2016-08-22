#include <iostream>
#include <stdio.h>
#include <ctime>
#include <windows.h>

#define SEC_IN_MS 1000.0
#define MIN_IN_MS 60000.0

using namespace std;

int main()
{
//        clock_t begin, end;
//        double time_spent;
    LARGE_INTEGER start, end, frenq;
    double diff;

    int number = 1000, flag, count = 0;

    int i, j;
    QueryPerformanceFrequency(&frenq);
    QueryPerformanceCounter(&start);

//    begin = clock();
    for (i = 3; i <= number; i = i + 2)
    {
        Sleep(1);
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if ((i % j) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            count++;
        }
    }

//    QueryPerformanceCounter(&end);
//    diff.QuadPart = end.QuadPart - start.QuadPart;
//    diff.QuadPart *= 1000;
//    diff.QuadPart /= frenq.QuadPart;
    
    QueryPerformanceCounter(&end);
    diff = (end.QuadPart - start.QuadPart);
    diff *= 1000;
    diff /= frenq.QuadPart;

//    printf("Number of primes upto %d is %d\n", number, count);
//            end = clock();
//            time_spent = (double) (end - begin); /// CLOCKS_PER_SEC;
//            
//            if (time_spent < SEC_IN_MS)
//            {
//                //        cout << time_spent << " ms" << endl;
//                printf("%.3lf ms\n", time_spent);
//            }
//            else if (time_spent > SEC_IN_MS && time_spent < MIN_IN_MS)
//            {
//                //        cout << time_spent / 1000 << " sec" << endl;
//                printf("%.3lf sec\n", time_spent / SEC_IN_MS);
//            }
//            else if (time_spent > MIN_IN_MS)
//            {
//                //        cout << time_spent / 60000 << " min" << endl;
//                printf("%.3lf min\n", time_spent / MIN_IN_MS);
//            }

//    if (diff.QuadPart < SEC_IN_MS)
//    {
//        //        cout << time_spent << " ms" << endl;
//        printf("%d ms\n", diff);
//    }
//    else if (diff.QuadPart > SEC_IN_MS && diff.QuadPart < MIN_IN_MS)
//    {
//        //        cout << time_spent / 1000 << " sec" << endl;
//        printf("%d sec\n", diff.QuadPart / SEC_IN_MS);
//    }
//    else if (diff.QuadPart > MIN_IN_MS)
//    {
//        //        cout << time_spent / 60000 << " min" << endl;
//        printf("%d min\n", diff.QuadPart / MIN_IN_MS);
//    }
    
    
    if (diff < SEC_IN_MS)
    {
        //        cout << time_spent << " ms" << endl;
        printf("%.3lf ms\n", diff);
    }
    else if (diff > SEC_IN_MS && diff < MIN_IN_MS)
    {
        //        cout << time_spent / 1000 << " sec" << endl;
        printf("%.3lf sec\n", diff / SEC_IN_MS);
    }
    else if (diff > MIN_IN_MS)
    {
        //        cout << time_spent / 60000 << " min" << endl;
        printf("%.3lf min\n", diff / MIN_IN_MS);
    }


    //    printf("%.3lf seconds\n", time_spent);
    //    printf("%.3lf ms\n", time_spent);
//    printf("%d ms\n", diff);

    return 0;
}
