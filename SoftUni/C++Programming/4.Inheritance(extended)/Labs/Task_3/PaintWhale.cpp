#include "PaintWhale.hpp"

PaintWhale::PaintWhale()
{
}

PaintWhale::~PaintWhale()
{
}

double PaintWhale::scale_factor()
{
    return this->PaintObject::size.x / this->Whale::size.x;
}

void PaintWhale::calc_whale_size_on_sheet()
{
    double scaleFactorOnX = this->Whale::size.x / this->PaintObject::sheetSize.x;
    double scaleFactorOnY = this->Whale::size.y / this->PaintObject::sheetSize.y;
    double desiredScaledFactor;
    if (scaleFactorOnX > scaleFactorOnY)
    {
        desiredScaledFactor = scaleFactorOnX;
    }
    else
    {
        desiredScaledFactor = scaleFactorOnY;
    }
    this->PaintObject::size.x = this->Whale::size.x / desiredScaledFactor;
    this->PaintObject::size.y = this->Whale::size.y / desiredScaledFactor;
}