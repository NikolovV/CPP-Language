#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "Person.hpp"
using namespace std;

class Student : public Person {
public:
    Student(string name = "N/A", uint16_t ID = 0,
            School *newSchool = NULL, Course newCourse = N_A,
            uint16_t point = 0, bool isFirstCourse = 1);

    void show_ext_info() const;
    void search_by_id(const Student *student);

    void set_mark();
    void set_point();
    void set_point(uint16_t point);
    void set_is_first_course();
    void set_is_first_course(bool isFirstCourse);

    uint16_t get_point() const;
    int get_mark() const;
    bool get_isFirstCourse() const;

private:
    uint16_t _point;
    bool _isFirstCourse;

    enum class Marks : uint8_t {
        FIRST_COURSE = 0, POOR = 2,
        MEDIAN, GOOD, VERY_GOOD, EXELENT
    }
    currentMark = Marks::FIRST_COURSE;
};

#endif /* STUDENT_HPP */

