#ifndef PRINT_VAL_IN_TIME_H
#define PRINT_VAL_IN_TIME_H

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Constants.h"

void print_val_in_time(const char *msg, unsigned long long val, LARGE_INTEGER startTime, LARGE_INTEGER frenq);
void print_val_in_time(const char *msg, unsigned long long val, clock_t start);

#endif /* PRINT_VAL_IN_TIME_H */

