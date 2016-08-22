#pragma once

#include "Whale.hpp"
#include "PaintObject.hpp"

class PaintWhale : public Whale, public PaintObject {
public:
    PaintWhale();
    virtual ~PaintWhale();

    void calc_whale_size_on_sheet();
    double scale_factor();
};