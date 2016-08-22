#include <iostream>
#include "Teacher.hpp"

Teacher::Teacher(string name, uint16_t ID, School *newSchool, Course newCourse,
                 float monthSalary, uint16_t daysOnWork) :
Person(name, ID, newSchool, newCourse),
_monthSalary(monthSalary), _daysOnWork(daysOnWork)
{
}

//void Teacher::search_by_id(const Teacher *teacher)
//{
//    cout << "Enter ID to search: ";
//    int id;
//    cin >> id;
//    cin.clear();
//    fflush(stdin);
//    for (int i = 0; i < MAX_SIZE; i++)
//    {
//        if (teacher[i].get_ID() == id)
//        {
//            teacher[i].show_base_info();
//            teacher[i].show_ext_info();
//            return;
//        }
//    }
//    cout << "Not found." << endl;
//}
// Setters

void Teacher::set_month_salary()
{
    cout << "Enter Teacher month salary: ";
    float salary;
    cin >> salary;
    cin.clear();
    fflush(stdin);
    _monthSalary = salary;
}

void Teacher::set_month_salary(float salary)
{
    _monthSalary = salary;
}

void Teacher::set_days_on_work()
{
    cout << "How many days have passed since he joined: ";
    uint16_t days;
    cin >> days;
    cin.get();
    fflush(stdin);
    _daysOnWork = days;
}

void Teacher::set_days_on_work(uint16_t daysOnWork)
{
    _daysOnWork = daysOnWork;
}
// Getter

float Teacher::get_salary() const
{
    return _monthSalary;
}

uint16_t Teacher::get_day_on_work() const
{
    return _daysOnWork;
}

void Teacher::show_ext_info() const
{
    cout << "Monthly salary: " << get_salary() << endl;
    cout << "Days in school: " << get_day_on_work() << endl;
}