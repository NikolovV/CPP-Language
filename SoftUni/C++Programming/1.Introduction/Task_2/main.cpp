#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void add_one_sample(int a);
void add_one_pointer(int *a);
void add_one_reference(int &a);

int main()
{
    cout << "sjkdfh\n";
    // same as:
    cout << "sjkdfh" << endl; // must use std namespace !!!

    int a = 6;
    cout << "a = " << a << endl;

    float b = 0.123456789;
    cout << "b = " << b << endl;
    cout << "b = " << (int) b << endl; // cast to int.
    cout << "b = " << static_cast<int> (b) << endl; //same as previous line.

    char arr[10] = {'a', 'b', 'c', 'd', 'i', 'f', 'g'};
    cout << "arr[0] = " << arr[0] << endl;
    cout << "arr[0] = " << (int) arr[9] << endl;
    cout << "arr[0] = " << *(arr + 0) << endl;

    if (arr[0] == 'a')
    {
        cout << "A" << endl;
    }
    if (!(arr[0] != 'a'))
    {
        cout << "A?" << endl;
    }

    arr[0] = 'b';
    cout << "arr[0] = " << arr[0] << endl;

    add_one_sample(a);
    cout << "a = " << a << " ???" << endl;

    add_one_pointer(&a);
    cout << "a = " << a << endl;

    add_one_reference(a);
    cout << "a = " << a << endl;

    int i = 0;
    while (i++ < 5)
    {
        cout << "i= ";
        cout << i << endl;
        break;
    }
    cout << "i= ";
    cout << i << "???" << endl;

    for (int j = 0; j < 5; j++)
    {
        a += j;
    }
    cout << "a = " << a << endl;

    string str;
    cout << "Put some text with space: ";
    cin >> str;

    // clear stdio buffer. Try without it
    cin.clear();  
    fflush(stdin);

    cout << "str = " << str << endl;

    cout << "Put another text with space: ";
    getline(cin, str);
    cout << "str = " << str << endl;

    cout << "123456789" << endl;
    cout << setw(9) << "x" << endl;

    cout << "123456789" << endl;
    cout << setfill('-') << setw(9) << "X" << endl;

    double oneThird = 1.0 / 3.0;
    cout << setprecision(1) << oneThird << endl;
    cout << setprecision(3) << oneThird << endl;
    cout << setprecision(5) << oneThird << endl;


    cout << setw(10) << setiosflags(std::ios::left) << "Hello " << "World!" << endl;
    //set numeric base to 16 , show plus sign and show base
    cout << hex << setiosflags(std::ios::showpos | std::ios::showbase) << 160 << endl;
    double var = 0.000000000001;
    //show a double value in decimal base and hexadecimal base
    cout << var << " = " << setiosflags(std::ios::floatfield) << var << endl;

    return 0;
}

void add_one_sample(int a)
{
    a++;
}

void add_one_pointer(int *a)
{
    (*a)++; // !!! see operator precedence
}

void add_one_reference(int &a)
{
    a++;
}