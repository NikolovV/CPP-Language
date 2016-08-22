#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "FigureWithAngles.h"


class Rectangle : public FigureWithAngles
{
public:
    Rectangle(double sideA, double sideB)
    {
        side['a'] = sideA;
        side['b'] = sideB;
    }
    virtual double perimeter()
    {
        return 2.00f * (side['a'] + side['b']);
    }
    virtual double surface()
    {
       return side['a'] * side['b'];
    }
};

#endif /* RECTANGLE_H */