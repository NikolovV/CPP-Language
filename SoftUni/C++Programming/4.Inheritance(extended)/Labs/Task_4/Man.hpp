#pragma once

#include "Person.hpp"

class Man : private Person{
public:
    Man();
    virtual ~Man();
    
    friend class Women;
    friend void add_money_to_mans_card(float amount, Man &aMan);
};