#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>

class Environment
{
public:

    Environment()
    {
    };

    Environment(double newGravity)
    {
        gravity = newGravity;
    }
    std::string name;
    double gravity;
};


#endif /* ENVIRONMENT_H */

