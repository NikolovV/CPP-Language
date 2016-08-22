#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
    Truck(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner) :
    Vehicle(reg, weight, seats, chassis, engine, owner)
    {};
    ~Truck(){};
};

#endif /* TRUCK_H */

