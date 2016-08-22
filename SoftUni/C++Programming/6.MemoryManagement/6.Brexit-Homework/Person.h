#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "Gender.h"

/**
 * Base class for people.
 */
class Person
{
public:
    Person(){};
    Person(std::string name, unsigned int age, Gender gender, 
    std::string livingCity, std::string ethnos) : _name(name), _age(age),
    _gender(gender), _livingCity(livingCity), _ethnos(ethnos) {};
    virtual ~Person() {};
    
protected:
    std::string _name;
    unsigned int _age;
    Gender _gender;
    std::string _livingCity;
    std::string _ethnos;
};

#endif /* PERSON_H */