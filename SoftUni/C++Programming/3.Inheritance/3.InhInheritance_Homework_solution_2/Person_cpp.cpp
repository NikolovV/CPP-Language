#include <iostream>
#include <vector>
#include "Person.hpp"
using namespace std;

Person::Person(string name, uint16_t ID, School *newSchool, Course newCourse) :
_name(name), _ID(ID), school(newSchool), curent(newCourse)
{
}

Person::~Person()
{
}

void Person::show_base_info() const
{
    cout << "ID: " << get_ID() << endl;
    cout << "Name: " << get_name() << endl;
    cout << "Course: " << get_course() << endl;
    cout << "School: " << get_school() << endl;
}

void Person::show_ext_info() const
{
}

void Person::set_point()
{
}

void Person::set_month_salary()
{
}

void Person::set_course_salary()
{
}

//void Person::search_by_id(const Person *person)
//{
//    cout << "Enter ID to search: ";
//    int id;
//    cin >> id;
//    cin.clear();
//    fflush(stdin);
//    for (int i = 0; i < MAX_SIZE; i++)
//    {
//        if (person[i].get_ID() == id)
//        {
//            person[i].show_base_info();
//            person[i].show_ext_info();
//            return;
//        }
//    }
//    cout << "Not found." << endl;
//}

// Setters

void Person::set_name()
{
    cout << "Enter name: ";
    string newName;
    getline(cin, newName);
    cin.clear();
    fflush(stdin);
    _name = newName;
}

void Person::set_name(string name)
{
    _name = name;
}

void Person::set_ID()
{
    cout << "Enter ID: ";
    uint16_t id;
    cin >> id;
    cin.get();
    cin.clear();
    fflush(stdin);
    if (id >= 0 && id <= MAX_SIZE - 1)
    {
        _ID = id;
    }
    else
    {
        cout << "ID: 0 - 65535!" << endl;
        set_ID();
    }

}

void Person::set_ID(uint16_t ID)
{
    _ID = ID;
}

void Person::set_school(School *sc)
{
    school = sc;
}

void Person::set_course()
{
    cout << "Enter course 1 - 7: ";
    int currentCourse;
    cin >> currentCourse;
    cin.clear();
    fflush(stdin);
    switch (currentCourse)
    {
        case(CPP):
        {
            curent = CPP;
            break;
        }
        case(C):
        {
            curent = C;
            break;
        }
        case(CSH):
        {
            curent = CSH;
            break;
        }
        case(JAVA):
        {
            curent = JAVA;
            break;
        }
        case(PHP):
        {
            curent = PHP;
            break;
        }
        case(HTML):
        {
            curent = HTML;
            break;
        }
        case(CSS):
        {
            curent = CSS;
            break;
        }
        default:
        {
            cout << "Which course you are learning!!!" << endl;
            set_course();
        }
    }
}

// Getters

string Person::get_name() const
{
    return _name;
}

uint16_t Person::get_ID() const
{
    return _ID;
}

string Person::get_school() const
{
    if (school)
    {
        return school->get_school_name();
    }
    return "N/A";
}

string Person::get_course() const
{
    if (curent)
    {
        switch (curent)
        {
            case(N_A):
            {
                return "N_A";
            }
            case(CPP):
            {
                return "C++";
            }
            case(C):
            {
                return "C";
            }
            case(CSH):
            {
                return "C#";
            }
            case(JAVA):
            {
                return "JAVA";
            }
            case(PHP):
            {
                return "PHP";
            }
            case(HTML):
            {
                return "HTML";
            }
            case(CSS):
            {
                return "CSS";
            }
            default:
            {
                return "Which course you are learning!!!";
            }
        }
    }
    return "N/A";
}