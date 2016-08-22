#ifndef GUESTTEACHER_HPP
#define GUESTTEACHER_HPP

#include <iostream>
#include "Person.hpp"
using namespace std;

class GuestTeacher : public Person {
public:
    GuestTeacher(string name = "N/A", uint16_t ID = 0,
            School *newSchool = NULL, Course newCourse = N_A,
            float courseSalary = 0.0);

    void set_course_salary();
    void set_course_salary(float salary);
    
    float get_salary() const;

    void show_ext_info() const;
//    void search_by_id(const GuestTeacher *guest);
private:
    float _courseSalary;
};

#endif /* GUESTTEACHER_HPP */

