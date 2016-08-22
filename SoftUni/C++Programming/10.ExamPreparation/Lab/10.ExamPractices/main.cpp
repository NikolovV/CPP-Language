#include <iostream>
#include <thread>

using namespace std;
#include "Strudent.h"
#include "Course.h"

int main()
{ 
    Strudent *student1 = new Strudent();
    student1->set_name("Go6o");
    student1->set_faculty_number("1234");
    student1->set_group(42);
    
    Strudent *student2 = new Strudent();
    student2->set_name("Mi6o");
    student2->set_faculty_number("12345");
    student2->set_group(41);
    
    Strudent *student3 = new Strudent();
    student3->set_name("Tisho");
    student3->set_faculty_number("12346");
    student3->set_group(43);
    
    CourseContainer aContainer;
    aContainer.studentsContainer.push_back(std::shared_ptr<Strudent> (student1));
    aContainer.studentsContainer.push_back(std::shared_ptr<Strudent> (student2));
    aContainer.studentsContainer.push_back(std::shared_ptr<Strudent> (student3));
    
//    cout << aContainer.studentsContainer.at(0)->get_name() << endl; // Student::get_name()

    std::thread aThread(&CourseContainer::search_for_student, aContainer, "1234");
//    aContainer.search("1234");
    
    aThread.join();
    
    return 0;
}