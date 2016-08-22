//#include <cstdlib>
#include <iostream>
#include <string>

#include "School.hpp"
#include "Enums.hpp"
#include "Person.hpp"
#include "Teacher.hpp"
#include "GuestTeacher.hpp"
#include "Student.hpp"

using namespace std;
void print_course();
void display_menu();
/* 
	USED TOO MUCH MEMORY !!! ??? 
	rather than version with aray of base class pointer
	pointing to array of derived class 
	and outside function that get array of base class pointer !
	
	void search_by_id(const Person *ptr[]);
	
	Person *ptrStudent[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++) ptrStudent[i] = student[i];
*/
int main()
{
	School school = School(); // Default SoftUni
	Course currentCourse = Course::CPP;

	Student *student = new Student[MAX_SIZE];
	Teacher *teacher = new Teacher[MAX_SIZE];
	GuestTeacher *guestTeacher = new GuestTeacher[MAX_SIZE];
	uint16_t studentIndex = 0, teacherIndex = 0, guestTeacherIndex = 0;

	// Test data.
	student[studentIndex++] = Student("Student", 101, &school, N_A, 100, 0);
	teacher[teacherIndex++] = Teacher("Teacher", 1, &school, N_A, 1234.56, 100);
	guestTeacher[guestTeacherIndex++] = GuestTeacher("GuestTeacher", 123, &school, N_A, 1324.123);
	//

	display_menu();

	/* Here i don't use function because i have must take many parameters(student,
	 * teacher, e.t.c), or to make them global.
	 */
	UserOption options;
	int currentOption;
	while (1)
	{
		cout << "Choose an option: ";
		cin >> currentOption;
		cin.get();
		cin.clear();
		fflush(stdin);
		switch (currentOption)
		{

			case(EXIT):
				{
					break;
				}
			case(GET_STUDEN):
				{
					student->search_by_id(student);
					break;
				}
			case(GET_TEACHER):
				{
					teacher->search_by_id(teacher);
					break;
				}
			case(GET_GUEST_TEACHER):
				{
					guestTeacher->search_by_id(guestTeacher);
					break;
				}
			case(ADD_STUDENT):
				{
					if (studentIndex >= MAX_SIZE)
					{
						cout << "No space for new student!" << endl;
						break;
					}
					student[studentIndex].set_ID();
					student[studentIndex].set_name();
					student[studentIndex].set_school(&school);
					print_course();
					student[studentIndex].set_course();
					student[studentIndex].set_is_first_course();
					if (!student[studentIndex].get_isFirstCourse())
					{
						student[studentIndex].set_point();
						student[studentIndex].set_mark();
					}
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
					teacher[teacherIndex].set_school(&school);
					print_course();
					teacher[teacherIndex].set_course();
					teacher[teacherIndex].set_days_on_work();
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
					guestTeacher[guestTeacherIndex].set_school(&school);
					print_course();
					guestTeacher[guestTeacherIndex].set_course();
					guestTeacher[guestTeacherIndex].set_course_salary();
					guestTeacherIndex++;
					break;
				}
			default:
				{
					cout << "You must choose between 0 - 6!" << endl;
					break;
				}
		}
		if (currentOption == EXIT)
		{
			break;
		}
	}

	delete[] student;
	delete[] teacher;
	delete[] guestTeacher;

	return 0;
}

void display_menu()
{
	cout << "0. Exit" << endl;
	cout << "1. Get data for student with ID" << endl;
	cout << "2. Get data for teacher with ID" << endl;
	cout << "3. Get data for gest teacher with ID" << endl;
	cout << "4. Add data for new student" << endl;
	cout << "5. Add data for new teacher" << endl;
	cout << "6. Add data for new guest teacher" << endl;
}

void print_course()
{
	for (int i = 1; i < LAST_COURSE; i++)
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
	cout << endl;
}