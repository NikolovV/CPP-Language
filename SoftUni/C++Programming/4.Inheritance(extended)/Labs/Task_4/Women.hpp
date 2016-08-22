#pragma once

#include "Person.hpp"
#include "Man.hpp"

class Women : private Person{
public:
    Women();
    virtual ~Women();
    
    Women &operator=(Man &aMan);
    void waste_money();
};