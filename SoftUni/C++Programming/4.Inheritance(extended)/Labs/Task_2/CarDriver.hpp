#pragma once

#include "Driver.hpp"

class CarDriver : public Driver{
public:
    CarDriver();
    virtual ~CarDriver();
    int maxPassengers;
private:

};