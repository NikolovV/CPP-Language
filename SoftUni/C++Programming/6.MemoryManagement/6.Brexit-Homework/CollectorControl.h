#ifndef COLLECTORCONTROL_H
#define COLLECTORCONTROL_H

#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;
#include "Data.h"

// Abstract class for calculating data based on different parameter. Returned in map<>.
class CollectorControl
{
public:
    virtual ~CollectorControl() {};
    virtual map<float, float> result_based_in_percent() = 0;
    virtual map<int, int> result_base_on_age(int age) = 0;
    virtual map<int, int> result_base_on_name(string name) = 0;
    virtual map<int, int> result_base_on_ethnos(string name) = 0;
    virtual map<int, int> result_base_on_city(string name) = 0;
};

#endif /* COLLECTORCONTROL_H */