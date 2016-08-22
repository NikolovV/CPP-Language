#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner) : 
            Vehicle(reg, weight, seats, chassis, engine, owner)
     {};
    ~Car(){};
};

#endif /* CAR_H */