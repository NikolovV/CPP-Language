#include <iostream>
#include "Student.hpp"

Student::Student(string name, uint16_t ID, School *newSchool, Course newCourse,
                 uint16_t point, bool isFirstCourse) :
Person(name, ID, newSchool, newCourse),
_point(point), _isFirstCourse(isFirstCourse)
{
    set_mark();
}

void Student::show_ext_info() const
{
    cout << "Point: " << get_point() << endl;
    cout << "Mark: " << get_mark() << endl;
}

//void Student::search_by_id(const Student *student)
//{
//    cout << "Enter ID to search: ";
//    int id;
//    cin >> id;
//    cin.clear();
//    fflush(stdin);
//    for (int i = 0; i < MAX_SIZE; i++)
//    {
//        if (student[i].get_ID() == id)
//        {
//            student[i].show_base_info();
//            student[i].show_ext_info();
//            return;
//        }
//    }
//    cout << "Not found." << endl;
//}
void Student::set_mark()
{
    if (_isFirstCourse)
    {
        currentMark = Marks::FIRST_COURSE;
    }
    else if (_point >= 0 && _point <= 20)
    {
        currentMark = Marks::POOR;
    }
    else if (_point >= 21 && _point <= 35)
    {
        currentMark = Marks::MEDIAN;
    }
    else if (_point >= 36 && _point <= 50)
    {
        currentMark = Marks::GOOD;
    }
    else if (_point >= 51 && _point <= 70)
    {
        currentMark = Marks::VERY_GOOD;
    }
    else
    {
        currentMark = Marks::EXELENT;
    }
}

void Student::set_point()
{
    cout << "Enter point: ";
    uint16_t newPoint;
    cin >> newPoint;
    cin.clear();  
    fflush(stdin);
    if (newPoint >= 0 && newPoint <= 100)
    {
        _point = newPoint;
    }
    else
    {
        cout << "Wrong value! (0 - 100)" << endl;
        set_point();
    }
}

void Student::set_point(uint16_t point)
{
    _point = point;
}

void Student::set_is_first_course(bool isFirstCourse)
{
    _isFirstCourse = isFirstCourse;
}

uint16_t Student::get_point() const
{
    return _point;
}

int Student::get_mark() const
{
    return (int) currentMark;
}