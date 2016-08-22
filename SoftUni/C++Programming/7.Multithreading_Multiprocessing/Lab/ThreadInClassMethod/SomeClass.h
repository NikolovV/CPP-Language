#ifndef SOMECLASS_H
#define SOMECLASS_H

class SomeClass
{
public:
    SomeClass(int a, int b) : _a(a), _b(b) {}
    void printA();
    void printB();
private:
    int _a;
    int _b;
};

#endif /* SOMECLASS_H */