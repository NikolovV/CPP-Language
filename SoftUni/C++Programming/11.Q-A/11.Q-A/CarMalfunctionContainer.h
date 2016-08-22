#ifndef CARMALFUNCTIONCONTAINER_H
#define CARMALFUNCTIONCONTAINER_H

#include <iostream>
#include <vector>
#include <set>
#include <mutex>
#include <thread>

#include "Malfunction.h"

class CarMalfunctionContainer
{
    void sortMalfunction();
protected :
    std::mutex containerLock;
    std::vector<Malfunction> malfunction;
public:
    std::vector<std::thread> thread;
    ~CarMalfunctionContainer();
    std::string carMake;
    float priceForRepairOfMalfunction(std::set<std::string> sympton);
    void addMalfunction(Malfunction aMalfunction);
};

#endif /* CARMALFUNCTIONCONTAINER_H */