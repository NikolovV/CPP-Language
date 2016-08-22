#ifndef PHYSICALCONTROL_H
#define PHYSICALCONTROL_H

#include <iostream>
#include "PhysicalObject.h"
#include "Environment.h"

class PhysicalControl
{
    Environment environment;
public:

    PhysicalControl() {};

    PhysicalControl(Environment newEnvironment) :
    environment(newEnvironment)
    {
    };
    float final_speed_of_free_fall_for_object(
                                              const PhysicalObject &anObject,
                                              double secondsOfFreeFall);
};

#endif /* PHYSICALCONTROL_H */

