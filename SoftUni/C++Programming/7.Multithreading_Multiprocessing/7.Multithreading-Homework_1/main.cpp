#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <csignal>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>

#include "Constants.h"
#include "prime_numbers.h"
#include "Fibonacci_numbers.h"

/**
 * Global mutex.
 */
mutex mtx;
static BOOL WINAPI console_ctrl_handler(DWORD dwCtrlType);
    
int main()
{
    SetConsoleCtrlHandler(console_ctrl_handler, TRUE);
    
    // start two threads
    thread primes(prime_numbers, 100000);
    thread fibonacci(fibonacci_numbers, 48);
    
    // join them.
    primes.join();
    fibonacci.join();

    return 0;
}

/**
 * Signal handler function.
 */
static BOOL WINAPI console_ctrl_handler(DWORD dwCtrlType)
{
    if (dwCtrlType == CTRL_CLOSE_EVENT)
    {
        g_exit = true;
        return TRUE;
    }
    return FALSE;
}