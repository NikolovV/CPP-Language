#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <map>
#include <set>
using namespace std;

class Printer
{
public:
    Printer(){};
    ~Printer(){};
    
    /**
    * Take some user input in map<int, int> variable, and print to console.
    * It's not template because in switch AGE there is specific output.
    * @param value - user input string.
    * @param result - map<int, int> variable.
    */
    void print_info(string value, map<int, int> result)
    {
        map<int, int>::iterator it = result.begin();
        if (it->first >= 0)
        {
            cout << value << " - Stay: " << it->first << ", Leave: " << it->second;
            cout << endl << endl;
        }
    }
    /**
    * Template to print the set of voter data.
    * !!! INPORTANT NOTE Template function must be declare and define in HEADER!!!
    * @param data - set of voter argument
    */
    template<typename T>
    void print_specific_voter_data(set<T> data)
    {
        int i = 0;
        for (auto elem : data)
        {
            cout << elem;
            if (i < data.size() - 1)
            {
                cout << ", ";
            }
            i++;
        }
        cout << endl << endl;
    }
};

#endif /* PRINTER_H */

