#pragma once

#include "Size.hpp"

class Whale {
public:
    Whale();
    virtual ~Whale();

    Size size;
    char skinColor[4];
    unsigned short mass;
};