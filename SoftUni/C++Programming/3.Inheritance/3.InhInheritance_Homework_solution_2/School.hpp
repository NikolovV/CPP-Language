#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <iostream>
using namespace std;

class School {
public:
    School(string name = "SoftUni");

    void set_name(string name);
    string get_school_name();
private:
    string _scName;
};

#endif /* SCHOOL_HPP */

