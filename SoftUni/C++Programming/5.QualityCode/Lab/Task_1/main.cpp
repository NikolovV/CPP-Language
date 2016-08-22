#include <iostream>

using namespace std;
#include "Environment.h"
#include "PhysicalObject.h"
#include "PhysicalControl.h"

#define EARTH_GRAVITY 9.81

int main()
{
    PhysicalObject myObject;
    myObject.set_weight(100);
    Environment surroundingEnvironment =
            Environment(EARTH_GRAVITY);
    PhysicalControl physiscsControl = PhysicalControl(surroundingEnvironment);
    cout << physiscsControl.final_speed_of_free_fall_for_object(myObject, 30) << endl;

    return 0;
}