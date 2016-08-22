#pragma once

#include "Size.hpp"

class PaintObject {
public:
    PaintObject();
    virtual ~PaintObject();

    char color[4];
    Size size;
    Size sheetSize;
    char backgroundColor[4];
};