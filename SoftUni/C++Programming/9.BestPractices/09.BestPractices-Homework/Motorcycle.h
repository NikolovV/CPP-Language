#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
    Motorcycle(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner) :
    Vehicle(reg, weight, seats, chassis, engine, owner)
    {};
    ~Motorcycle(){};
};

#endif /* MOTORCYCLE_H */