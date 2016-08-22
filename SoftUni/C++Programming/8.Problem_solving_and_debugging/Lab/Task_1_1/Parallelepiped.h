#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "Figures3D.h"
#include "Rectangle.h"

class Parallelepiped : public Figure3D, public Rectangle
{
public:

    Parallelepiped(double sideA, double sideB, double sideC) :
    Rectangle(sideA, sideB)
    {
        sideC = sideC;
    }

    double perimeter()
    {
        return 
                4.0 * side['a'] + 
                4.0 * side['b'] + 
                4.0 * side['c'];
    }

    double surface()
    {
        return 2.0f *
        (side['a'] * side['b'] +
                side['b'] * side['c'] +
                side['c'] * side['a']);
    }

    double volume()
    {
        return side['a'] * side['b'] * side['c'];
    }
};

#endif /* PARALLELEPIPED_H */

