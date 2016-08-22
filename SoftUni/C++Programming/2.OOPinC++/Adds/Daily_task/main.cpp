#include "stdafx.h"#include <cstdlib>
#include <iostream>
using namespace std;

class Position
{
public:
	Position(float x, float y) :_x(x), _y(y) { cout << "Constructor Position\n"; };
	Position() :_x(0), _y(0) { cout << "Constructor def Position\n"; };
	~Position() { cout << "Detructor Position\n"; };
	float _x;
	float _y;
};
class Size
{
public:
	Size(float newHeight, float newWidth) : height(newHeight), width(newWidth) { cout << "Constructor Size\n"; };
	Size() :height(0), width(0) { cout << "Constructor def Size\n";};
	~Size() { cout << "Destruct Size\n"; }
	float height;
	float width;

};
class Rectangle
{
	double _perimeter;
	double _surfase;
	double _diagonal;
public:
	Rectangle(Position newPosition, Size newSize) : position(newPosition), size(newSize) { cout << "Constructor Rectangle\n"; };
	Rectangle(float x, float y, float width, float height)
	{
		position._x = x;
		position._y = y;
		size.width = width;
		size.height = height;
		cout << "Constructor def Rectangle\n";
	}
	~Rectangle() { cout << "Destruct Rectangle\n"; }
	Position position;
	Size size;

	double perimeter()
	{
		_perimeter = 2 * size.width + 2 * size.height;
		return _perimeter;
	}

	double surface()
	{
		_surfase = size.width*size.height;
		return _surfase;
	}

	double diagonal()
	{
		_diagonal = sqrt(size.height*size.height + size.width*size.width);
		return _diagonal;
	}
};

int main()
{
	//Rectangle rectangle1 = Rectangle(2, 2, 2, 2);
	Rectangle rectangle2 = Rectangle(Position(2, 2), Size(4, 4));
	//cout << rectangle1.perimeter() << " " << rectangle1.diagonal() << endl;
	cout << rectangle2.surface() << " " << rectangle2.diagonal() << endl;
	return 0;
}