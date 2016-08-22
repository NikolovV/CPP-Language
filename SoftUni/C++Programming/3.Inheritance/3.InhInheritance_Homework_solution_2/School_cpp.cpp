#include <iostream>
#include "School.hpp"
using namespace std;

School::School(string name) : _scName(name)
{
}

void School::set_name(string name)
{
    _scName = name;
}

string School::get_school_name()
{
    return _scName;
}