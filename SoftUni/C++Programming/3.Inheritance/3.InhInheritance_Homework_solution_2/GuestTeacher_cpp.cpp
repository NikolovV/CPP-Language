#include <iostream>
#include "GuestTeacher.hpp"

GuestTeacher::GuestTeacher(string name, uint16_t ID,
                           School *newSchool, Course newCourse, float courseSalary) :
Person(name, ID, newSchool, newCourse), _courseSalary(courseSalary)
{
}

void GuestTeacher::show_ext_info() const
{
    cout << "Salary for course: " << get_salary() << endl;
};

void GuestTeacher::set_course_salary()
{
    cout << "Enter salary for the course: ";
    float salary;
    cin >> salary;
    cin.clear();  
    fflush(stdin);
    _courseSalary = salary;
}

void GuestTeacher::set_course_salary(float salary)
{
    _courseSalary = salary;
}

float GuestTeacher::get_salary() const
{
    return _courseSalary;
}

//void GuestTeacher::search_by_id(const GuestTeacher *guest)
//{
//    cout << "Enter ID to search: ";
//    int id;
//    cin >> id;
//    cin.clear();
//    fflush(stdin);
//    for (int i = 0; i < MAX_SIZE; i++)
//    {
//        if (guest[i].get_ID() == id)
//        {
//            guest[i].show_base_info();
//            guest[i].show_ext_info();
//            return;
//        }
//    }
//    cout << "Not found." << endl;
//}