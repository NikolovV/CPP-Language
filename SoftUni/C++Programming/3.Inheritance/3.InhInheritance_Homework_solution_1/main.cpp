#include <cstdlib>
#include <iostream>

#include "School.hpp"
#include "Enums.hpp"
#include "Person.hpp"
#include "Teacher.hpp"
#include "GuestTeacher.hpp"
#include "Student.hpp"

using namespace std;

void search_by_id(Person *ptr[]);
void print_course();

int main()
{
    School school = School();
    Course currentCourse = Course::CPP;
    //            vector<Teacher> teachers;
    //            vector<GuestTeacher> guestTeachers;
    //            vector<Student> students;

    //    // Test data.
    //        teachers.push_back(Teacher("Teacher", 65535, &school, &currentCourse, 1234.56, 100));
    //        guestTeachers.push_back(GuestTeacher("GuestTeacher", 123, &school, &currentCourse, 1324.123));
    //        students.push_back(Student("Student", 101, &school, &currentCourse, 100, 0));

    Person * ptrStudent[MAX_SIZE];
    Person * ptrTeacher[MAX_SIZE];
    Person * ptrGuestTeacher[MAX_SIZE];

    Student *student = new Student[MAX_SIZE];
    Teacher *teacher = new Teacher[MAX_SIZE];
    GuestTeacher *guestTeacher = new GuestTeacher[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        ptrStudent[i] = &student[i];
        ptrTeacher[i] = &teacher[i];
        ptrGuestTeacher[i] = &guestTeacher[i];
    }

    uint16_t studentIndex = 0, teacherIndex = 0, guestTeacherIndex = 0;

    // Test data.
    student[studentIndex++] = Student("Student", 101, &school, N_A, 100, 0);
    teacher[teacherIndex++] = Teacher("Teacher", 1, &school, N_A, 1234.56, 100);
    guestTeacher[guestTeacherIndex++] = GuestTeacher("GuestTeacher", 123, &school, N_A, 1324.123);

    cout << "1. Get data for student with ID" << endl;
    cout << "2. Get data for teacher with ID" << endl;
    cout << "3. Get data for gest teacher with ID" << endl;
    cout << "4. Add data for new student" << endl;
    cout << "5. Add data for new teacher" << endl;
    cout << "6. Add data for new guest teacher" << endl;

    while (1)
    {
        UserOption options;
        int currentOption;
        cin >> currentOption;
        cin.get();
        cin.clear();
        fflush(stdin);
        switch (currentOption)
        {
            case(GET_STUDEN):
            {
                search_by_id(ptrStudent);
                break;
            }
            case(GET_TEACHER):
            {
                search_by_id(ptrTeacher);
                break;
            }
            case(GET_GUEST_TEACHER):
            {
                search_by_id(ptrGuestTeacher);
                break;
            }
            case(ADD_STUDENT):
            {
                if (studentIndex >= MAX_SIZE)
                {
                    cout << "No space for new student!" << endl;
                    break;
                }
                ptrStudent[studentIndex]->set_ID();
                ptrStudent[studentIndex]->set_name();
                ptrStudent[studentIndex]->set_course();
                ptrStudent[studentIndex]->set_point();
                studentIndex++;

                break;
            }
            case(ADD_TEACHER):
            {
                if (teacherIndex >= MAX_SIZE)
                {
                    cout << "No space for new Teacher!" << endl;
                    break;
                }
                teacher[teacherIndex].set_ID();
                teacher[teacherIndex].set_name();
                teacher[teacherIndex].set_course();
                teacher[teacherIndex].set_month_salary();
                teacherIndex++;
                break;
            }
            case(ADD_GUEST_TEACHER):
            {
                if (guestTeacherIndex >= MAX_SIZE)
                {
                    cout << "No space for new GuestTeacher!" << endl;
                    break;
                }
                guestTeacher[guestTeacherIndex].set_ID();
                guestTeacher[guestTeacherIndex].set_name();
                guestTeacher[guestTeacherIndex].set_course();
                guestTeacher[guestTeacherIndex].set_course_salary();
                guestTeacherIndex++;
                break;
            }
            default:
            {
                cout << "You must choose between 1 - 6!" << endl;
                break;
            }
        }
    }
        delete [] student;
        delete [] teacher;
        delete [] guestTeacher;

    return 0;
}

void search_by_id(Person *ptr[])
{
    cout << "Enter ID to search: ";
    int id;
    cin >> id;
    cin.clear();
    fflush(stdin);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (ptr[i]->get_ID() == id)
        {
            ptr[i]->show_base_info();
            ptr[i]->show_ext_info();
            return;
        }
    }
    cout << "Not found." << endl;
}

void print_course()
{
    for (int i = 1; i < PHP; i++)
    {
        switch (i)
        {
            case(CPP):
            {
                cout << i << " - " << "CPP";

                break;
            }
            case(C):
            {
                cout << i << " - " << "C";

                break;
            }
            case(CSH):
            {
                cout << i << " - " << "C#";

                break;
            }
            case(JAVA):
            {
                cout << i << " - " << "JAVA";

                break;
            }
            case(PHP):
            {
                cout << i << " - " << "PHP";

                break;
            }
            case(HTML):
            {
                cout << i << " - " << "HTML";
                break;
            }
            case(CSS):
            {
                cout << i << " - " << "CSS";
                break;
            }
        }
        cout << "; ";
    }
}