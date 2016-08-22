#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Identity.h"

namespace GraphicsFramework
{
// Implement additional info about characters.
class Characters : public Identity
{
public:
    Characters() {};
    Characters(unsigned int newID, std::string newName,
         float newWeightInKG, float newJumpSpeedInKmH)
    : Identity(newID, newName),
    _weightInKG(newWeightInKG), _jumpSpeedInKmH(newJumpSpeedInKmH) {};
    
    void set_weight(float newWeight = 0) {this->_weightInKG = newWeight;}
    void set_jump_speed(float newJumpSpeed = 0.0) {this->_jumpSpeedInKmH = newJumpSpeed;}
    
    float get_weight() const {return this->_weightInKG;}
    float get_jump_speed() const {return this->_jumpSpeedInKmH;}
protected:
    float _weightInKG;
    float _jumpSpeedInKmH;
};
}

#endif /* CHARACTERS_H */