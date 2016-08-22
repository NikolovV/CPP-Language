#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Identity.h"

namespace GraphicsFramework
{
class Environment : public Identity
{
// Implement additional info about surrounding environment.
public:
    Environment() {};
    Environment(unsigned int newID, std::string newName, float newGravity) :
    Identity(newID, newName), _gravity(newGravity) {};
    
    void set_gravity(float newGravity = 0.0) {this->_gravity = newGravity;}
    
    float get_gravity() const {return this->_gravity;}
protected :
    float _gravity;
};
}
#endif /* ENVIRONMENT_H */