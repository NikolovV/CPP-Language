#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <memory>
#include <functional>
#include <algorithm>

#include "DataBase.h"

class Search
{
public:
    Search(std::shared_ptr<DataBase> data) {_dataBsae = data;};
    ~Search(){};
    
    void search_car_in_database(std::string registrationNumber,
                                   std::function<void () > lambdaExpression);
    void search_truck_in_database(std::string registrationNumber,
                                   std::function<void () > lambdaExpression);
    void search_motorcycle_in_database(std::string registrationNumber,
                                   std::function<void () > lambdaExpression);
private:
    std::shared_ptr<DataBase> _dataBsae;
};

#endif /* SEARCH_H */