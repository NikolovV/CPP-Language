#ifndef STRUDENT_H
#define STRUDENT_H

#include <iostream>
#include <set>
#include <map>

enum Groups
{
    GROUP_40 = 40,
    GROUP_41,
    GROUP_42,
    GROUP_43,
    GROUP_44
};

enum Course
{
    COURSE_1 = 1,
    COURSE_2,
    COURSE_3,
};
class Strudent
{
public:
    Strudent(){};
    ~Strudent(){};
    void add_mark(std::string subject, float mark);
     void fill_info();
    float average_marks();
    // Setters
    void set_name(std::string name) {_name = name;}
    void set_faculty_number(std::string facultyNumber) {_facultyNumber = facultyNumber;}
    bool set_group(int group) 
    {
        switch ((Groups)group)
        {
        case GROUP_40:
        case GROUP_41:
        case GROUP_42:
        case GROUP_43:
        case GROUP_44:
            _group = (Groups)group;
            return true;
        default:
            return false;
        }
    }
    bool set_course(int course) 
    {
        switch ((Course)course)
        {
        case COURSE_1:
        case COURSE_2:
        case COURSE_3:
             _course = (Course)course;
            return true;
        default:
            return false;
        }
    }
    void set_subgects(std::set<std::string> subjects) {_subject = subjects;}
    void set_marks (std::map<std::string, float> marks) {_marks = marks;}
    // Getters
    std::string get_name() const {return _name;}
    std::string get_faculty_number() const {return _facultyNumber;}
    Groups get_group() const {return _group;}
    Course get_course() const {return _course;}
    std::set<std::string> get_subjets () const {return _subject;}
    std::map<std::string, float> get_mark () const {return _marks;}
    
protected:
    std::string _name;
    std::string _facultyNumber;
    Groups _group;
    Course _course;
    std::set<std::string> _subject;
    std::map<std::string, float> _marks;
};

#endif /* STRUDENT_H */