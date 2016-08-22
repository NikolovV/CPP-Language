#ifndef CONTROLDATA_H
#define CONTROLDATA_H

#include <iostream>
#include <list>

#include "ShopList.h"

class ControlData
{
public:
    std::list<ShopList> items;
    void add_to_list(const ShopList &obj) {items.push_back(obj);}
    void remove_from_list_by_id(unsigned int &ID);
    void print_list();
};

#endif /* CONTROLDATA_H */

