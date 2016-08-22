#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
using namespace std;

#include "School.hpp"
#include "Enums.hpp"

class Person {
public:
    Person(string name = "N/A", uint16_t ID = 0,
            School *newSchool = NULL, Course newCourse = N_A);
    virtual ~Person();

    void set_name();
    void set_name(string name);
    
    void set_ID();
    void set_ID(uint16_t ID);
    void set_school(School *sc);
    void set_course();
    
    string get_name() const;
    uint16_t get_ID() const;
    string get_school() const;
    string get_course() const;

    virtual void show_base_info() const;
    virtual void show_ext_info() const;
    virtual void set_point();
    virtual void set_month_salary();
    virtual void set_course_salary();
//    virtual void search_by_id(const Person *person);


protected:
    uint16_t _ID;
    string _name;
    School *school;
    Course curent;
};

#endif /* PERSON_HPP */

