#include <iostream>

#include "Mechanic.hpp"
#include "Car.hpp"
#include "Man.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Car aCar(1000);
    Mechanic aMehanic;
    Man aMan;
    
    aMan.crash_a_car(aCar);
    cout << aMehanic.price_for_repearing_aCar(aCar) << endl;
    aMehanic.repair_a_car(aCar);
    
    return 0;
}

