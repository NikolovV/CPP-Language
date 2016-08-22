#ifndef CIRCLE_H
#define CIRCLE_H

#include "FigureWithouthAngles.h"
#include <math.h>

class Circle : public FigureWithoutAngles
{
public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    double perimeter()
    {
        return 2.00f * M_PI * radius;
    }
    
    double surface()
    {
        return M_PI * pow(radius, 2);
    }
};


#endif /* CIRCLE_H */

