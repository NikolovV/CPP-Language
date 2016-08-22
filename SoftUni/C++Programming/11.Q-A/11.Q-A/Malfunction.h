#ifndef MALFUNCTION_H
#define MALFUNCTION_H

#include <iostream>
#include <set>
#include <map>

class Malfunction
{
public:
    Malfunction(){};
    ~Malfunction(){};
    std::string fixingMethod;
    std::map<std::string, float> neededParts;
    std::set<std::string> sympthons; // linked list
    float priceForWork;
    int frequencyOfMalfunction;
    float finalPriceForRepair();
};

#endif /* MALFUNCTION_H */