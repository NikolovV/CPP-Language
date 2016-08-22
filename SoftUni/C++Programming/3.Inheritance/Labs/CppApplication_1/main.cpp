#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

namespace ABC{
    class A
    {
    protected :
        int x;
    public :
        A() : x(0) {}
        A(int _x) : x(_x) {cout << "A constructor" << endl;}
        virtual void sh_ad() const = 0;
        virtual void sh() const {cout << x << endl; /*sh_ad();*/}
    };
}
namespace ABC
{
    class B : public A
    {
    protected :
        int y;
        virtual void sh_ad() const = 0; // {cout << y << endl;}
    public :
        B (int _y) : A(_y), y(0){}
        B(int _x, int _y) : A(_x), y(_y) {cout << "B constructor" << endl;}
        void sh() const {A::sh();}
    };
}
namespace ABC
{
    class C : public B
    {
    protected :
        int z;
        B *p;
    private :
        void sh_ad() const {cout << z << endl;}
    public :
        C(int _x, int _z) : B(_x), z(_z) {}
    //    C(int _x, int _y, int _z) : B(_x, _y), z(_z) {cout << "C constructor" << endl;}
        void sh() const {B::sh(); sh_ad();}
    };
}
using namespace ABC;
void pr(const A &r)
{
    r.sh();
}
int main()
{
//    vector<B> v;
//    v.push_back(B(1, 2));
//    
//    for (auto elem : v)
//    {
//        elem.sh();
//    }
//    
//    v.push_back(B(3, 4));
//    for (auto elem : v)
//    {
//        elem.sh();
//    }

    

//    A a = A(159);
//    a.sh();
//    pr(a);
    
//    B b = B(321, 654);
//    b.sh();
//    pr(*b);
////        
    C c = C(1, 2);
//    c.sh();
    pr(c);
  
    return 0;
}