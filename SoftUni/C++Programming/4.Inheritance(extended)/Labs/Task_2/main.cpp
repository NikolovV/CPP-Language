#include <iostream>

#include "Women.hpp"

using namespace std;

int main()
{
    Women aWoman;
    aWoman.CarDriver::id = "12345678";
    aWoman.MotorcycleDriver::id = "123123";
    aWoman.maxPassengers = 8;
    aWoman.category = '1';
    
    return 0;
}

