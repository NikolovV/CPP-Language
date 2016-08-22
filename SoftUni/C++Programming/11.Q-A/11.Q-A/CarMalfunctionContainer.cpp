#include <algorithm>

#include "CarMalfunctionContainer.h"

float CarMalfunctionContainer::priceForRepairOfMalfunction(std::set<std::string> sympton)
{
    float priceForRepeirOfMalfunction = 0;
    containerLock.lock();
    std::for_each(malfunction.begin(), malfunction.end(),
                  [&] (Malfunction aMalfunction)
                  {
                      auto aGivenSympton = sympton.begin();
                      for (auto elem : aMalfunction.sympthons)
                      {
                  if (elem != *aGivenSympton)
                          {
                  return;
                          }
                  aGivenSympton++;
                      }
                      priceForRepeirOfMalfunction = aMalfunction.finalPriceForRepair();
                  }
                  );
    containerLock.unlock();
    return priceForRepeirOfMalfunction;
}

void CarMalfunctionContainer::addMalfunction(Malfunction aMalfunction)
{
    containerLock.lock();
    thread.push_back(std::thread([&] ()
    {
        malfunction.push_back(aMalfunction);
        std::sort(malfunction.begin(), malfunction.end(), [&]
                  (Malfunction malfunctionOne, Malfunction malfunctionTwo)
        {
            return (malfunctionOne.frequencyOfMalfunction > malfunctionTwo.frequencyOfMalfunction);
        }
                  );
        containerLock.unlock();
    }
                                 )
                     );
}

CarMalfunctionContainer::~CarMalfunctionContainer()
{
}
