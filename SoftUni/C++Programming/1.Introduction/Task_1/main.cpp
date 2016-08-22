#include <iostream>
#include <string>

using namespace std;

void count_letter(const string &str);

int main()
{
    string input;
    getline(cin, input);

    count_letter(input);

    return 0;
}

void count_letter(const string &str)
{
    int uppercase = 0, lowercase = 0, other = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            uppercase++;
        }
        else if (islower(str[i]))
        {
            lowercase++;
        }
        else
        {
            other++;
        }
    }

    cout << "Uppercase: " << uppercase << endl;
    cout << "Lowercase: " << lowercase << endl;
    cout << "Other: " << other << endl;
}