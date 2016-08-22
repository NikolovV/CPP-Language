#pragma once

#include "CarDriver.hpp"
#include "MotorcycleDriver.hpp"

class Women : public MotorcycleDriver, public CarDriver {
public:
    Women();
    virtual ~Women();
    
    string name;
private:
    int age;

};