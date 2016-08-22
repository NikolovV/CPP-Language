#include <iostream>
#include <string>
#include <map>

using namespace std;

#define STAY 1
#define LEAVE 0
#define MAX_COUNT 3

int main()
{
    map<string, bool> Brexit;

    int countVotes = 0;
    while (countVotes <= MAX_COUNT)
    {
        cout << "Your name: ";
        string name;
        getline(cin, name);
        cout << "Your vote: (0 or 1): ";
        bool vote;
        cin >> vote;
        cin.get();
        cin.clear();
        fflush(stdin);
        Brexit.insert(make_pair(name, vote));
        countVotes++;
    }
    
    for (auto elem : Brexit)
    {
        cout << elem.first << "->" << elem.second << endl;
    }


    return 0;
}

