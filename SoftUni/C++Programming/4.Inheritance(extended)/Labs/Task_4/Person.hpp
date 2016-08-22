#pragma once

#include "BancAccount.hpp"

class Person {
public:
    Person();
    virtual ~Person();
    
    BankAccount bankAccount;
};