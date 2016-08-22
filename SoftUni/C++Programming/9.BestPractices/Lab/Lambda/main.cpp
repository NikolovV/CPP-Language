#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

class Foo
{
public:

    Foo() : _x(3){}
    void func(const string &msg, void lamb(const string mg))
    {
        lamb(msg);
    }
private:
    int _x;
};

void fun(function<void () > lamb)
{
    lamb();
}

int main()
{
    Foo f;
    string k = "aksdfhk";
    f.func(k, [] (const string ms) {cout << ms << endl;});
    
    string m = "Hi";
    fun([&]()
    {
        cout << "massige from main: " << m << endl;
    }
        );

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for_each(v.begin(), v.end(), [](auto val)
    {
        if (val > 5)
        {
            cout << val << endl;
        }
    }
             );

    return 0;
}