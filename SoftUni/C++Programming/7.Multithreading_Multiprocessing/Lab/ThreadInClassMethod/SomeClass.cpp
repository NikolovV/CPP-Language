#include "SomeClass.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex mLock;

void SomeClass::printA()
{
    std::thread printThreadt(
                             [&] ()
                             {
                                 mLock.lock();
                                 sleep(1);
                                 std::cout << "a = " << _a << std::endl;
                                 mLock.unlock();
                             }
                             );
    printThreadt.join();
}

void SomeClass::printB()
{
    std::thread printThreadt(
                             [&] ()
                             {
                                 mLock.lock();
                                 sleep(1);
                                 std::cout << "b = " << _b << std::endl;
                                 mLock.unlock();
                             }
                             );
    printThreadt.join();
}