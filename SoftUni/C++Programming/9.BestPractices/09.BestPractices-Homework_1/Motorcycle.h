#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
    Motorcycle(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner, const short id = 2) :
    Vehicle(reg, weight, seats, chassis, engine, owner, id)
    {};
    ~Motorcycle(){};
    const short ID = 2;
};

#endif /* MOTORCYCLE_H */