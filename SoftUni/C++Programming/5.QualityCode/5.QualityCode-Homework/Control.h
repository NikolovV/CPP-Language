#ifndef CONTROL_H
#define CONTROL_H

#include "Environment.h"

namespace GraphicsFramework
{
// Implement controls on character based on environment.
class Control
{
public:
    virtual ~Control() {};
protected:
    Environment _environment;
};
}

#endif /* CONTROL_H */