#ifndef PHYSICCONTROL_H
#define PHYSICCONTROL_H

#include "Environment.h"
#include "Control.h"
#include "Characters.h"
#include "Converter.h"

namespace GraphicsFramework
{
// Implement controls on character based on environment.
class PhysicControl : public Control, public Conveter
{
public:
    PhysicControl() {}
    PhysicControl(Environment newEnvironment) {this->_environment = newEnvironment;}
    
//    PhysicControl& operator=(const PhysicControl &obj)
//    {
//        this->_environment = obj._environment;
//    }
    void set_environment(Environment *newEnvironment) {this->_environment = *newEnvironment;}
    
    float calc_max_jump_height(Characters *character);
    float time_of_jump(Characters *character);
    std::string is_able_to_jump_on_height(float maxHeight, float certainHeight);
};
}

#endif /* PHYSICCONTROL_H */