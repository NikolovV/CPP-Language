#include "Man.hpp"
#include "Car.hpp"

Man::Man()
{
}

Man::~Man()
{
}

void Man::crash_a_car(Car &rCar)
{
    rCar.needsARepair = true;
}