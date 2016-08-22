#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"


class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {};
 };


#endif /* SQUARE_H */