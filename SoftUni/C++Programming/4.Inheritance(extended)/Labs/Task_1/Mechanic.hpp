#pragma once
#include "Car.hpp"

class Mechanic {
public:
    Mechanic();
    virtual ~Mechanic();
    
    float price_for_repearing_aCar(Car &rCar);
    void repair_a_car(Car &rCar);
};