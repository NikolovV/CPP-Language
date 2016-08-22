#include <iostream>

#include "PaintWhale.hpp"

using namespace std;

int main()
{
    PaintWhale aPanitWhale;
    aPanitWhale.Whale::size.x = 12; // in meters
    aPanitWhale.Whale::size.y = 4; // in meters
    aPanitWhale.PaintObject::sheetSize.x = 0.3;
    aPanitWhale.PaintObject::sheetSize.y = 0.2;
    aPanitWhale.calc_whale_size_on_sheet();
    cout << aPanitWhale.scale_factor() << endl;

    return 0;
}