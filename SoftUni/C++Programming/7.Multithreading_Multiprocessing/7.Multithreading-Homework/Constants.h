#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <mutex>
using namespace std;

// declare extern variable (define in some cpp file)
extern mutex mtx;
extern bool g_exit;

#define SEC_IN_MS 1000.0
#define MIN_IN_MS 60000.0

#endif /* CONSTANTS_H */