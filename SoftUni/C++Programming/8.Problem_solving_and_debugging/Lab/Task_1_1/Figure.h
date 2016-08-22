#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <map>

class Figure
{
public:
    virtual double perimeter()=0;
    virtual double surface()=0;
};


#endif /* FIGURE_H */