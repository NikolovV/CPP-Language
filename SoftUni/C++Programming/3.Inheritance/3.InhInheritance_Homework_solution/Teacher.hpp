#ifndef TEACHER_HPP
#define TEACHER_HPP

#include <iostream>
#include "Person.hpp"
using namespace std;

class Teacher : public Person {
public:
    Teacher(string name = "N/A", uint16_t ID = 0,
            School *newSchool = NULL, Course newCourse = N_A,
            float monthSalary = 0.0, uint16_t daysOnWork = 0);

    void set_month_salary();
    void set_month_salary(float salary);
    void set_days_on_work();
    void set_days_on_work(uint16_t daysOnWork);

    float get_salary() const;
    uint16_t get_day_on_work() const;

    void show_ext_info() const;
    void search_by_id(const Teacher *teacher);
private:
    float _monthSalary;
    uint16_t _daysOnWork;
};

#endif /* TEACHER_HPP */

