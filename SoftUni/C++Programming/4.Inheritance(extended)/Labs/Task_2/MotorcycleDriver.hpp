#pragma once

#include "Driver.hpp"

class MotorcycleDriver : public Driver{
public:
    MotorcycleDriver();
    virtual ~MotorcycleDriver();
    char category;
private:

};