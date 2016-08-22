#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Strudent.h"

class CourseContainer
{
public:
    std::vector<std::shared_ptr<Strudent> > studentsContainer;
    ~CourseContainer(){};
    
    void search_for_student(std::string facultyNumber);
};

#endif /* COURSE_H */