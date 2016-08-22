#include <iostream>

#include "SomeClass.h"

using namespace std;

int main()
{
    SomeClass someObject(123, 456);
    
    for (int i = 0; i < 5; i++)
    {
        someObject.printA();
        someObject.printB();
    }

    return 0;
}