#include <cmath>
#include "PhysicControl.h"

namespace GraphicsFramework
{

float PhysicControl::calc_max_jump_height(Characters *character)
{
    // h = v0^2 / 2*g
    float height = powf(convert_kmH_in_ms(character->get_jump_speed()), 2) /
            2 * _environment.get_gravity();
    return height;
}

float PhysicControl::time_of_jump(Characters *character)
{
    // t = 2*v0 / g
    float timeOfFlight = 2*convert_kmH_in_ms(character->get_jump_speed()) / 
    _environment.get_gravity();
    return timeOfFlight;
}

std::string PhysicControl::is_able_to_jump_on_height(float maxHeight, float certainHeight)
{
    return (maxHeight > certainHeight) ? "YES" : "NO";
}
}