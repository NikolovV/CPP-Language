#include <cstdlib>
#include <iostream> 
#include <cmath>
using namespace std;
class Cube
{
public :
    Cube (int side = 0) : _side(side) {}
    void set_side (int side) {_side = side;}
    int get_side () const {return _side;}
    
    int perimeter(const Cube &side);
    int surface(const Cube &side);
    int volume(const Cube &side);
private :
    int _side;
};
int main()
{
    Cube a(2);
    cout << a.perimeter(a) << endl;
    return 0;
}
int Cube::perimeter(const Cube &side)
{
    return (int)pow((float)side.get_side(), 2.0);
}

//int Cube::surface(const Cube &side);
//int Cube::volume(const Cube &side);