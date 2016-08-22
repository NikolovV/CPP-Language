#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <iostream>
#include "Object.h"

class PhysicalObject : public Object
{
    float weight;
public:

    inline void set_weight(float newWeght)
    {
        weight = newWeght;
    }
};

#endif /* PHYSICALOBJECT_H */

