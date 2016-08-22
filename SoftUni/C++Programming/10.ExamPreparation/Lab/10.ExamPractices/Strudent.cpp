#include "Strudent.h"

void Strudent::fill_info()
{
    std::cout << "Please enter name" << std::endl;
    std::string name;
    std::cin >> name;
    set_name(name);

    std::cout << "Please enter number\n";
    std::string facultyNumber;
    std::cin >> facultyNumber;
    set_faculty_number(facultyNumber);

    int group;
    do
    {
        std::cout << "Please enter group from 40 to 44\n";
        std::cin >> group;
    }
    while (set_group(group) == false);
    
    int course;
    do
    {
        std::cout << "Please enter course from 1 to 3\n";
        std::cin >> course;
    }
    while (set_course(course) == false);
    
    do
    {
        std::string subject;
        std::cout << "Please enter subject name\n";
        std::cin >> subject;
        if (subject[0] == 27) break;
        std::cout << "Please enter subject mark\n";
        int mark;
        std::cin >> mark;
        add_mark(subject, mark);
    }
    while(true);
}

void Strudent::add_mark(std::string subject, float mark)
{
    //        _marks.insert(std::pair<std::string, float>(subject, mark));
    _subject.insert(subject);
    _marks[subject] = mark;
}
