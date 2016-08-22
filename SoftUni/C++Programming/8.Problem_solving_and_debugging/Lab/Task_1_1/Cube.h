#ifndef CUBE_H
#define CUBE_H

#include "Parallelepiped.h"

class Cube : public Parallelepiped
{
public:

    Cube(double side) : Parallelepiped(side, side, side) {}
};

#endif /* CUBE_H */