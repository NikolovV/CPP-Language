#pragma once
#include "Man.hpp"

class Car {
public:
    Car();
    Car(float price);
    virtual ~Car();
    
    friend class Mechanic;
    friend void Man::crash_a_car(Car &rCar);
    
    float priceOfCar;
private:
    bool needsARepair;
};