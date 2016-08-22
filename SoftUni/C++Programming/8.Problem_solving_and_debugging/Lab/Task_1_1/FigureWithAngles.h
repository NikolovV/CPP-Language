#ifndef FIGUREWITHANGLES_H
#define FIGUREWITHANGLES_H

#include "Figure.h"

class FigureWithAngles : public Figure
{
public:
    std::map<char, double> side;
};


#endif /* FIGUREWITHANGLES_H */