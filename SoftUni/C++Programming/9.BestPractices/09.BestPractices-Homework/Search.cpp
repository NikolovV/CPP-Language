#include "Search.h"

void Search::search_car_in_database(std::string registrationNumber,
                                    std::function<void () > lambdaExpression)
{
    int counter = 0;
    bool isFound = false;
    for (auto elem : _dataBsae->get_car_database())
    {
        counter++;
        if (registrationNumber.compare(elem.first) == 0)
        {
            isFound = true;
            lambdaExpression();
        }
        else if (counter == _dataBsae->get_car_database().size() && !isFound)
        {
            std::cout << "No car with registartion number " << registrationNumber << std::endl;
        }
    }
}

void Search::search_truck_in_database(std::string registrationNumber,
                                      std::function<void () > lambdaExpression)
{
    int counter = 0;
    bool isFound = false;
    for (auto elem : _dataBsae->get_truck_database())
    {
        counter++;
        if (registrationNumber.compare(elem.first) == 0)
        {
            lambdaExpression();
        }
        else if (counter == _dataBsae->get_car_database().size() && !isFound)
        {
            std::cout << "No truck with registartion number " << registrationNumber << std::endl;
        }
    }
}

void Search::search_motorcycle_in_database(std::string registrationNumber,
                                           std::function<void () > lambdaExpression)
{
    int counter = 0;
    bool isFound = false;
    for (auto elem : _dataBsae->get_motorcycle_database())
    {
        counter++;
        if (registrationNumber.compare(elem.first) == 0)
        {
            lambdaExpression();
        }
        else if (counter == _dataBsae->get_car_database().size() && !isFound)
        {
            std::cout << "No motorcycle with registartion number " << registrationNumber << std::endl;
        }
    }
}