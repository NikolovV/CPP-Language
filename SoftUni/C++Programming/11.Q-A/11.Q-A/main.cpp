#include <iostream>

#include "CarMalfunctionContainer.h"

using namespace std;

int main()
{
    CarMalfunctionContainer aContainer;
    
    Malfunction aMalafunction;
    aMalafunction.neededParts["partOne"] = 5;
    aMalafunction.neededParts["partTwo"] = 7;
    aMalafunction.priceForWork = 18;
    aMalafunction.sympthons.insert("1");
    aMalafunction.sympthons.insert("2");

    Malfunction malfunctionTwo;
    malfunctionTwo.neededParts["partThree"] = 3;
    malfunctionTwo.neededParts["partFour"] = 6;
    malfunctionTwo.priceForWork = 11;
    malfunctionTwo.sympthons.insert("3");
    malfunctionTwo.sympthons.insert("4");
    aContainer.addMalfunction(aMalafunction);
    aContainer.addMalfunction(malfunctionTwo);
    
    std::set<std::string> symptoms;
    symptoms.insert("1");
    symptoms.insert("2");
    cout << aContainer.priceForRepairOfMalfunction(symptoms) << endl;
    aContainer.addMalfunction(aMalafunction);
    for (int i = 0; i < aContainer.thread.size(); i++)
    {
        aContainer.thread[i].join();
    }

    return 0;
}