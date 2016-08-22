#include "Search.h"

void Search::search_vehicle_in_database(std::string registrationNumber,
                                        std::function<void () > lambdaExpression)
{
    int counter = 0;
    bool isFound = false;
    for (auto elem : _dataBsae->get_vehicle_database())
    {
        counter++;
        if (registrationNumber.compare(elem.first) == 0)
        {
            isFound = true;
            // Only if is found call lambda function.
            lambdaExpression();
        }
        else if (counter == _dataBsae->get_vehicle_database().size() && !isFound)
        {
            if (elem.second.ID == 0)
            {
                std::cout << "<< No car with registration number " << 
                        registrationNumber << std::endl;
            }
            else if (elem.second.ID == 1)
            {
                std::cout << "<< No truck with registration number " << 
                        registrationNumber << std::endl;
            }
            else if (elem.second.ID == 2)
            {
                std::cout << "<< No motorcycle with registration number " << 
                        registrationNumber << std::endl;
            }
        }
    }
}