#include "PhysicalControl.h"

float PhysicalControl::final_speed_of_free_fall_for_object(
                                const PhysicalObject& anObject, 
                                double secondsOfFreeFall)
{
    float vFinal = environment.gravity * secondsOfFreeFall;
    return vFinal;
}