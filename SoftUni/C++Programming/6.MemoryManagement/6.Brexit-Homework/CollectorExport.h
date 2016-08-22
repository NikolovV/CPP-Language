#ifndef COLLECTOREXPORT_H
#define COLLECTOREXPORT_H

#include <iostream>
#include <memory>
#include <set>

#include "Data.h"

class CollectorExport
{
public:
    CollectorExport(std::shared_ptr<Data> data) : _collectorExport(data) {};
    ~CollectorExport() {};
    
    /**
     * Export all parameters in a set.
     * @return - set of specify data.
     */
    std::set<int> all_possible_age();
    std::set<std::string> all_possible_name();
    std::set<std::string> all_possible_ethnos();
    std::set<std::string> all_possible_city();

private:
    /**
     * Call different function based on pointer to function.
     * @param funcPtr - take pointer to function with index
     * @return - Current set of specify type value.
     */
    template<typename T>
    std::set<T> all_possible_for(T (CollectorExport::*funcPtr)(int index));
    
    /**
     * Used for export attribute into a set and return it.
     * @param data 
     */
    int age_in_pos(int index);
    std::string name_in_pos(int index);
    std::string ethnos_in_pos(int index);
    std::string city_in_pos(int index);
    
    std::shared_ptr<Data> _collectorExport;
};

#endif /* COLLECTOREXPORT_H */