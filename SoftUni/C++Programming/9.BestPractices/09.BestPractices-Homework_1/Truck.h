#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
    Truck(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner, const short id = 1) :
    Vehicle(reg, weight, seats, chassis, engine, owner, id)
    {};
    ~Truck(){};
    const short ID = 1;
};

#endif /* TRUCK_H */

