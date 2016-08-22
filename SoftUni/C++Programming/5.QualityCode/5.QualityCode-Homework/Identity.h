#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>

namespace GraphicsFramework
{
// Class holding basic information about objects.
class Identity
{
public:
    Identity() {};
    Identity(unsigned int newID, std::string newName) :
    _ID(newID), _name(newName) {};
    virtual ~Identity(){};
    
    void set_id(unsigned int newID = 0) {this->_ID = newID;}
    void set_name(std::string newName = "") {this->_name = newName;}
    
    unsigned int get_id() const {return this->_ID;}
    std::string get_name() const {return this->_name;}
    
protected:
    unsigned int _ID;
    std::string _name;
};
}

#endif /* IDENTITY_H */