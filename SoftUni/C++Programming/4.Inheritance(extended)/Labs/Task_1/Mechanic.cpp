#include "Mechanic.hpp"

Mechanic::Mechanic()
{
}

Mechanic::~Mechanic()
{
}

float Mechanic::price_for_repearing_aCar(Car &rCar)
{
    return rCar.priceOfCar * 0.05;
}

void Mechanic::repair_a_car(Car &rCar)
{
    rCar.needsARepair = false;
}