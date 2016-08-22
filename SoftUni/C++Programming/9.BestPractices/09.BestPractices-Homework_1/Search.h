#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <memory>
#include <functional>
#include <algorithm>

#include "DataBase.h"

/**
 * Used to search in database for vehicle with registration number.
 * @param data - shared pointer to abstract database.
 */
class Search
{
public:
    Search(std::shared_ptr<DataBase> data) {_dataBsae = data;};
    ~Search(){};
    
    /**
     * Search for registration number.
     * @param registrationNumber - given string parameter - vehicle registration number.
     * @param lambdaExpression - ask for lambda expression.
     */
    void search_vehicle_in_database(std::string registrationNumber,
                                   std::function<void () > lambdaExpression);
private:
    std::shared_ptr<DataBase> _dataBsae;
};

#endif /* SEARCH_H */