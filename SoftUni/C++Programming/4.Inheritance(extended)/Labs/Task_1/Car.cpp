#include "Car.hpp"

Car::Car()
{
}

Car::~Car()
{
}
Car::Car(float price) : priceOfCar(price)
{
    needsARepair = true;
}