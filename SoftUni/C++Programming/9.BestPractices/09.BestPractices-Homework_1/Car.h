#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner, const short id = 0) : 
            Vehicle(reg, weight, seats, chassis, engine, owner, id)
     {};
    ~Car(){};
    const short ID = 0;
};

#endif /* CAR_H */