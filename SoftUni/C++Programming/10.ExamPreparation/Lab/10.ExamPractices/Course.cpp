#include "Course.h"

void CourseContainer::search_for_student(std::string facultyNumber)
{
    bool isAvailable = false;
    std::for_each(studentsContainer.begin(), studentsContainer.end(),
                  [&] (std::shared_ptr<Strudent> aStudent)
                  {
                      if (aStudent->get_faculty_number() == facultyNumber)
                      {
                          std::cout << aStudent->get_name() << std::endl;
                          isAvailable = true;
                          return;
                      }
                  }
                  );
    if (isAvailable == true)
    {
        return;
    }
    std::cout << "Can't find target\n";
}