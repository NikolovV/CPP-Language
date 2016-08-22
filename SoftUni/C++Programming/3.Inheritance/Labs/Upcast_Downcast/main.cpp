#include <iostream>

using namespace std;

class Base
{
protected :
    int _x;
public:
    Base(int x) : _x(x) {};
    virtual void sh() {cout << "Base" << endl;};
};

class Derived : public Base
{
public :
    Derived(int x) : Base(x) {};
    void sh() override {cout << "Derived " << _x << endl;}
    void pr() {cout << "Derived pr()" << _x << endl;}
};
class Der1 : public Base
{
public :
    Der1(int x) : Base(x) {};
    void sh() override {cout << "Der1 " << _x << endl;}
    void pr() {cout << "Der1 pr()" << _x << endl;}
};

void p(Base *obj)
{
    Derived *d = dynamic_cast<Derived*>(obj);
    if (d!=NULL)
    {
        obj->sh();
        static_cast<Derived*>(obj)->pr();
    }
    else
    {
        cout << "Not Dereived!" << endl;
    }
    Der1 *d1 = dynamic_cast<Der1*>(obj);
    if (d1!=NULL)
    {
        obj->sh();
        static_cast<Der1*>(obj)->pr();
    }
    else
    {
        cout << "Not Der1" << endl;
    }
}

int main()
{
    Derived d(15);
    Der1 d1(25);
    
    p(&d);
    p(&d1);
    
    
    return 0;
}

