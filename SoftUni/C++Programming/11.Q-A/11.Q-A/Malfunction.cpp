#include "Malfunction.h"
#include <algorithm>

float Malfunction::finalPriceForRepair()
{
    float finalPriceForRepair = priceForWork;
    std::for_each(neededParts.begin(), neededParts.end(),
                  [&finalPriceForRepair] (const std::pair<std::string,float> aPair)
                  {
                      finalPriceForRepair += aPair.second;
                  }
                  );
    return finalPriceForRepair;
}